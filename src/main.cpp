#include <iostream>
#include "../include/DeribitAPI.h"

/**
 * @brief Displays the main menu of actions available to the user.
 */
void display_menu() {
    std::cout << "Select an action:" << std::endl;
    std::cout << "1. Authenticate" << std::endl;
    std::cout << "2. Place Order" << std::endl;
    std::cout << "3. Get Positions" << std::endl;
    std::cout << "4. Get Order Book" << std::endl;
    std::cout << "5. Modify Order" << std::endl;
    std::cout << "6. Cancel Order" << std::endl;
    std::cout << "7. Exit" << std::endl;
}

/**
 * @brief The main function that runs the Deribit API client.
 *
 * It continuously displays a menu for the user to select various actions
 * until the user decides to exit the program.
 */
int main() {
    DeribitAPI api; // Create an instance of the DeribitAPI class

    while (true) {
        display_menu(); // Display the available actions
        int choice;
        std::cin >> choice; // Get user input

        // Process the user's choice
        switch (choice) {
            case 1:
                api.get_token(); // Authenticate and get the access token
                break;
            case 2:
                api.place_order(); // Place a new order
                break;
            case 3:
                api.get_positions(); // Retrieve current trading positions
                break;
            case 4:
                api.get_order_book(); // Get the current order book
                break;
            case 5:
                api.modify_order(); // Modify an existing order
                break;
            case 6:
                api.cancel_order(); // Cancel an existing order
                break;
            case 7:
                return 0; // Exit the program
            default:
                std::cout << "Invalid choice! Please try again." << std::endl; // Handle invalid input
        }
    }
    return 0; // Return success
}
