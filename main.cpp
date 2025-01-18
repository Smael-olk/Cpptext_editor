#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void displayMenu() {
    cout << "1. Open File\n";
    cout << "2. Save File\n";
    cout << "3. Edit Text\n";
    cout << "4. Exit\n";
}

int main() {
    string text;
    string filename;
    int choice;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { // Open File
                cout << "Enter filename to open: ";
                cin >> filename;
                ifstream file(filename);
                if (file.is_open()) {
                    text.assign((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
                    cout << "File content:\n" << text << endl;
                } else {
                    cout << "Error: Unable to open file.\n";
                }
                break;
            }
            case 2: { // Save File
                cout << "Enter filename to save: ";
                cin >> filename;
                ofstream file(filename);
                if (file.is_open()) {
                    file << text;
                    cout << "File saved successfully.\n";
                } else {
                    cout << "Error: Unable to save file.\n";
                }
                break;
            }
            case 3: { // Edit Text
                cout << "Enter new text (type 'exit' to stop):\n";
                cin.ignore(); // Clear input buffer
                string line;
                text.clear();
                while (getline(cin, line) && line != "exit") {
                    text += line + "\n";
                }
                break;
            }
            case 4: { // Exit
                cout << "Exiting...\n";
                return 0;
            }
            default: {
                cout << "Invalid choice. Try again.\n";
                break;
            }
        }
    }

    return 0;
}