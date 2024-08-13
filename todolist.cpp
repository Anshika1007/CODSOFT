#include <iostream>
#include <vector>
#include <string>
#include <iomanip> 

using namespace std;

// struct to represent a task
struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

//  display the menu
void displayMenu() {
    cout << "\n*** To-Do List Menu ***\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

//  add a new task to the list
void addTask(vector<Task>& tasks) {
    cout << "Enter the description of the task: ";
    string description;
    cin.ignore(); // To ignore the leftover newline character from the previous input
    getline(cin, description);

    if (!description.empty()) {
        tasks.emplace_back(description);
        cout << "Task added successfully!\n";
    } else {
        cout << "Task description cannot be empty!\n";
    }
}

// view all tasks with their status
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available!\n";
        return;
    }

    cout << "\n*** Task List ***\n";
    cout << left << setw(5) << "ID" << setw(20) << "Description" << "Status\n";
    cout << "****************************************\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << setw(5) << i + 1
             << setw(20) << tasks[i].description
             << (tasks[i].completed ? "Completed" : "Pending") << '\n';
    }
}

// mark a task as completed
void markTaskAsCompleted(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available to mark as completed!\n";
        return;
    }

    cout << "Enter the task ID to mark as completed: ";
    int taskId;
    cin >> taskId;

    if (taskId > 0 && taskId <= static_cast<int>(tasks.size())) {
        if (!tasks[taskId - 1].completed) {
            tasks[taskId - 1].completed = true;
            cout << "Task marked as completed!\n";
        } else {
            cout << "Task is already marked as completed!\n";
        }
    } else {
        cout << "Invalid task ID!\n";
    }
}

//  remove a task from the list
void removeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available to remove!\n";
        return;
    }

    cout << "Enter the task ID to remove: ";
    int taskId;
    cin >> taskId;

    if (taskId > 0 && taskId <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + (taskId - 1));
        cout << "Task removed successfully!\n";
    } else {
        cout << "Invalid task ID!\n";
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskAsCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting the program. Thank you for using the To-Do List application!\n";
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 5.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
