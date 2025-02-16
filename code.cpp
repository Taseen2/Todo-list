#include <iostream>
#include <vector>
#include <fstream> // For file handling
#include <algorithm>  
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
void markTaskCompleted(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available to complete.\n";
        return;
    }

    int taskId;
    cout << "Enter Task ID to mark as completed: ";
    cin >> taskId;

    bool found = false;
    for (auto& task : tasks) {
        if (task.id == taskId) {
            task.isCompleted = true;
            cout << "Task marked as completed!\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Task ID not found.\n";
    }
}
void deleteTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available to delete.\n";
        return;
    }

    int taskId;
    cout << "Enter Task ID to delete: ";
    cin >> taskId;

    auto it = remove_if(tasks.begin(), tasks.end(), [&](const Task& task) {
        return task.id == taskId;
    });

    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        cout << "Task deleted successfully!\n";

        // Reassign IDs after deletion
        for (size_t i = 0; i < tasks.size(); ++i) {
            tasks[i].id = i + 1;
        }
    } else {
        cout << "Task ID not found.\n";
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
                markTaskCompleted(tasks);
                break;
            case 4:
                deleteTask(tasks);
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
