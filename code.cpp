#include <iostream>
#include <vector>
#include <fstream> 
#include <algorithm>  
#include <sstream>
#include <string>
using namespace std;
struct Task {
    int id;
    string title;
    bool isCompleted;
    string toString() const {
        return to_string(id) + "," + title + "," + (isCompleted ? "1" : "0");
    }
    static Task fromString(const string& line) {
        Task task;
        stringstream ss(line);
        string temp;
        getline(ss, temp, ','); task.id = stoi(temp);
        getline(ss, task.title, ',');
        getline(ss, temp, ','); task.isCompleted = (temp == "1");
        return task;
    }
};
void saveTasksToFile(const vector<Task>& tasks) {
    ofstream file("tasks.txt");
    if (!file) {
        cout << "Error: Could not open file to save tasks!\n";
        return;
    }
    for (const auto& task : tasks) {
        file << task.toString() << endl;
    }
    file.close();
}
void addTask(vector<Task>& tasks) {
    Task newTask;
    newTask.id = tasks.empty() ? 1 : tasks.back().id + 1;  
    cout << "Enter task description: ";
    cin.ignore();  
    getline(cin, newTask.title);
    newTask.isCompleted = false;
    tasks.push_back(newTask);
    saveTasksToFile(tasks);
    cout << "Task added successfully!\n";
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\n===== Task List =====\n";
    cout << " ID  |       Task        |   Status  \n";
    cout << "------------------------------------\n";

    for (const auto& task : tasks) {
        cout << " " << task.id << "   | " 
             << task.title << "  | " 
             << (task.isCompleted ? "Completed" : "Not Completed") 
             << endl;
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
    if (!found) cout << "Task ID not found.\n";
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
        Task deletedTask = *it;  // Store deleted task
        tasks.erase(it, tasks.end());
        saveTasksToFile(tasks);
        cout << "Task deleted successfully! (Type 'undo' to restore)\n";
        string choice;
        cin >> choice;
        if (choice == "undo") {
            tasks.push_back(deletedTask);  // Restore task
            saveTasksToFile(tasks);
            cout << "Task restored!\n";
        }
    } else {
        cout << "Task ID not found.\n";
    }
}
void loadTasksFromFile(vector<Task>& tasks) {
    ifstream file("tasks.txt");
    if (!file) return; 
    string line;
    while (getline(file, line)) tasks.push_back(Task::fromString(line));
    file.close();
}

int main() {
    vector<Task> tasks;
    loadTasksFromFile(tasks);
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
                saveTasksToFile(tasks);
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);
    return 0;
}
