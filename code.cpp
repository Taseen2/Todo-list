#include <iostream>
#include <vector>
#include <fstream> // For file handling
using namespace std;
struct Task {
    int id;
    string title;
    bool isCompleted;
};
void addTask(vector<Task>& tasks) {
    Task newTask;
    newTask.id = tasks.size() + 1; // Assign unique ID
    cout << "Enter task description: ";
    cin.ignore(); // To clear the newline character
    getline(cin, newTask.title); // Get full-line input
    newTask.isCompleted = false; // Default: not completed

    tasks.push_back(newTask); // Add to the list
    cout << "Task added successfully!\n";
}
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\n===== Task List =====\n";
    for (const auto& task : tasks) {
        cout << "ID: " << task.id << " | ";
        cout << "Task: " << task.title << " | ";
        cout << "Status: " << (task.isCompleted ? "Completed" : "Not Completed") << endl;
    }
}

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
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
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
