#include <iostream>
#include <vector>
#include <fstream> // For file handling
using namespace std;
struct Task {
    int id;
    string title;
    bool isCompleted;
};
int main() {
    vector<Task> tasks; // List to store tasks
    int choice;

    do {
        cout << "\n===== To-Do List =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task Completed\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Function to add task (we'll implement next)
                break;
            case 2:
                // Function to view tasks
                break;
            case 3:
                // Function to mark a task as completed
                break;
            case 4:
                // Function to delete a task
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
