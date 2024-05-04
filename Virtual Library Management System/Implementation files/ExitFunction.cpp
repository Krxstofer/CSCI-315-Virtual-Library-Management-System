#include <iostream>
#include "ExitFunction.h"  // Include the exit function header

using namespace std;

void userMenu() {
    int choice = 0;
    while (true) {
        cout << "\nUser Menu\n";
        cout << "1. View Profile\n";
        cout << "2. Edit Profile\n";
        cout << "3. Logout\n";
        cout << "Choose an option or 3 to exit: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Viewing profile...\n";
                break;
            case 2:
                cout << "Editing profile...\n";
                break;
            case 3:
                cout << "Logging out...\n";
                return;  // Returns to the calling function, effectively exiting the menu
            default:
                cout << "Invalid option, try again.\n";
        }
    }
}

int main() {
    while (true) {
        cout << "Main Menu\n";
        cout << "1. Login\n";
        cout << "2. Exit\n";
        cout << "Choose an option or 2 to exit: ";
        int mainChoice;
        cin >> mainChoice;

        switch (mainChoice) {
            case 1:
                userMenu();  // Goes into the user menu
                break;
            case 2:
                exitApplication();  // Call the exit function
                break;
            default:
                cout << "Invalid option, try again.\n";
        }
    }
    return 0;  // Not typically reached
}
