#include "../include/WebSocketClient.h"

// Constructor for the WebSocketClient class.
// Initializes the resolver and WebSocket stream with the provided I/O context and SSL context.
WebSocketClient::WebSocketClient(net::io_context& ioc, ssl::context& ctx)
    : resolver_(ioc), ws_(ioc, ctx) {}

// Starts the WebSocket client by resolving the specified host and port.
// Takes the instrument name as an argument for subscription purposes.
void WebSocketClient::run(const std::string& host, const std::string& port, const std::string& instrument)
{
    host_ = host; // Store the host for later use
    instrument_ = instrument; // Store the instrument for subscription
    // Asynchronously resolve the host and port
    resolver_.async_resolve(host, port,
        beast::bind_front_handler(&WebSocketClient::on_resolve, shared_from_this()));
}

// Callback function for handling the result of the asynchronous resolve operation.
// If successful, it initiates a connection to the resolved endpoint.
void WebSocketClient::on_resolve(beast::error_code ec, tcp::resolver::results_type results)
{
    if (ec) // Check for errors
        return fail(ec, "resolve"); // Handle error

    // Set the timeout for the connection
    beast::get_lowest_layer(ws_).expires_after(std::chrono::seconds(30));
    // Asynchronously connect to the endpoint
    beast::get_lowest_layer(ws_).async_connect(results,
        beast::bind_front_handler(&WebSocketClient::on_connect, shared_from_this()));
}

// Callback function for handling the result of the asynchronous connect operation.
// If successful, it initiates the SSL handshake.
void WebSocketClient::on_connect(beast::error_code ec, tcp::resolver::results_type::endpoint_type ep)
{
    if (ec) // Check for errors
        return fail(ec, "connect"); // Handle error

    host_ += ':' + std::to_string(ep.port()); // Store the port
    beast::get_lowest_layer(ws_).expires_after(std::chrono::seconds(30)); // Set timeout
    // Asynchronously perform the SSL handshake
    ws_.next_layer().async_handshake(ssl::stream_base::client,
        beast::bind_front_handler(&WebSocketClient::on_ssl_handshake, shared_from_this()));
}

// Callback function for handling the result of the asynchronous SSL handshake.
// If successful, it initiates the WebSocket handshake.
void WebSocketClient::on_ssl_handshake(beast::error_code ec)
{
    if (ec) // Check for errors
        return fail(ec, "ssl_handshake"); // Handle error

    beast::get_lowest_layer(ws_).expires_never(); // No timeout for the WebSocket connection
    ws_.set_option(websocket::stream_base::timeout::suggested(beast::role_type::client)); // Set timeout options
    // Asynchronously perform the WebSocket handshake
    ws_.async_handshake(host_, "/ws/api/v2",
        beast::bind_front_handler(&WebSocketClient::on_handshake, shared_from_this()));
}

// Callback function for handling the result of the asynchronous WebSocket handshake.
// If successful, it subscribes to the order book.
void WebSocketClient::on_handshake(beast::error_code ec)
{
    if (ec) // Check for errors
        return fail(ec, "handshake"); // Handle error

    subscribe_to_orderbook(); // Subscribe to the order book
}

// Prepares and sends a subscription message to the server for the specified instrument's order book.
void WebSocketClient::subscribe_to_orderbook()
{
    Json::Value subscription; // Create a JSON object for the subscription message
    subscription["jsonrpc"] = "2.0"; // Set the JSON-RPC version
    subscription["id"] = 1; // Set the request ID
    subscription["method"] = "public/subscribe"; // Specify the method for subscription
    // Append the channel for the specified instrument to the parameters
    subscription["params"]["channels"].append("book." + instrument_ + ".100ms");

    Json::FastWriter writer; // Create a writer to convert JSON to a string
    std::string message = writer.write(subscription); // Write the JSON message to a string

    // Asynchronously send the subscription message
    ws_.async_write(net::buffer(message),
        beast::bind_front_handler(&WebSocketClient::on_write, shared_from_this()));
}

// Callback function for handling the result of the asynchronous write operation.
// Initiates reading messages from the WebSocket after a successful write.
void WebSocketClient::on_write(beast::error_code ec, std::size_t bytes_transferred)
{
    boost::ignore_unused(bytes_transferred); // Ignore the number of bytes transferred

    if (ec) // Check for errors
        return fail(ec, "write"); // Handle error

    read(); // Start reading messages from the WebSocket
}

// Initiates an asynchronous read operation from the WebSocket.
void WebSocketClient::read()
{
    ws_.async_read(buffer_, // Start reading into the buffer
        beast::bind_front_handler(&WebSocketClient::on_read, shared_from_this()));
}

// Callback function for handling the result of the asynchronous read operation.
// Processes the received message and prints it to the console.
void WebSocketClient::on_read(beast::error_code ec, std::size_t bytes_transferred)
{
    boost::ignore_unused(bytes_transferred); // Ignore the number of bytes transferred

    if (ec) // Check for errors
        return fail(ec, "read"); // Handle error

    std::string data = beast::buffers_to_string(buffer_.data()); // Convert the buffer to a string
    Json::Value root; // Create a JSON object to hold the parsed data
    Json::Reader reader; // Create a reader for parsing JSON
    if (reader.parse(data, root)) // Parse the JSON data
    {
        std::cout << "Received message:\n" << root.toStyledString() << std::endl; // Print the parsed message
    }
    else
    {
        std::cerr << "Failed to parse JSON: " << data << std::endl; // Log parse error
    }

    buffer_.consume(buffer_.size()); // Clear the buffer after processing
    read(); // Continue reading for more messages
}

// Handles errors by printing the error message to the console.
void WebSocketClient::fail(beast::error_code ec, char const* what)
{
    std::cerr << what << ": " << ec.message() << "\n"; // Log the error
}

// Main function of the application.
// Takes the instrument name as a command-line argument and initializes the WebSocket client.
int main()
{
    std::string instrument; // Declare a string to hold the instrument name

    // Prompt the user for the instrument name
    std::cout << "Enter the instrument name (e.g., BTC-PERPETUAL): ";
    std::getline(std::cin, instrument); // Read the instrument name from user input

    // Check if the input is empty
    if (instrument.empty())
    {
        std::cerr << "Error: Instrument name cannot be empty.\n"; // Print error message
        return EXIT_FAILURE; // Exit with failure if no instrument is provided
    }

    try
    {
        net::io_context ioc; // Create an I/O context
        ssl::context ctx{ssl::context::tlsv12_client}; // Create an SSL context for TLSv1.2 client
        ctx.set_verify_mode(ssl::verify_peer); // Set SSL verification mode
        ctx.set_default_verify_paths(); // Use default verification paths

        // Create a shared WebSocketClient instance and run it
        std::make_shared<WebSocketClient>(ioc, ctx)->run("www.deribit.com", "443", instrument);
        ioc.run(); // Run the I/O context to start processing events
    }
    catch (std::exception const& e) // Catch exceptions
    {
        std::cerr << "Error: " << e.what() << std::endl; // Log the error message
        return EXIT_FAILURE; // Exit with failure
    }

    return EXIT_SUCCESS; // Exit successfully
}
