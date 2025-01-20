#include <iostream>
#include <string>

using namespace std;

// Define maximum tasks that can be managed
const int MAX_TASKS = 10;

// Structure to represent a task
struct Task {
    string description;
    bool completed;
};

// Function to add a task to the list
void addTask(Task tasks[], int &taskCount) {
    if (taskCount >= MAX_TASKS) {
        cout << "Task list is full. Cannot add more tasks.\n";
        return;
    }
    
    cout << "Enter the task description: ";
    cin.ignore(); // Ignore any leftover newline character
    getline(cin, tasks[taskCount].description);
    tasks[taskCount].completed = false; // New tasks are initially not completed
    taskCount++;
    cout << "Task added successfully.\n";
}

// Function to display all tasks
void viewTasks(const Task tasks[], int taskCount) {
    if (taskCount == 0) {
        cout << "No tasks available.\n";
        return;
    }
    
    for (int i = 0; i < taskCount; i++) {
        cout << i + 1 << ". " << tasks[i].description;
        if (tasks[i].completed) {
            cout << " [Completed]";
        } else {
            cout << " [Pending]";
        }
        cout << endl;
    }
}

// Function to mark a task as completed
void markTaskCompleted(Task tasks[], int taskCount) {
    int taskNumber;
    cout << "Enter task number to mark as completed: ";
    cin >> taskNumber;
    
    if (taskNumber < 1 || taskNumber > taskCount) {
        cout << "Invalid task number.\n";
        return;
    }
    
    tasks[taskNumber - 1].completed = true;
    cout << "Task marked as completed.\n";
}

// Function to remove a task from the list
void removeTask(Task tasks[], int &taskCount) {
    int taskNumber;
    cout << "Enter task number to remove: ";
    cin >> taskNumber;
    
    if (taskNumber < 1 || taskNumber > taskCount) {
        cout << "Invalid task number.\n";
        return;
    }
    
    // Shift tasks after the deleted task to fill the gap
    for (int i = taskNumber - 1; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    
    taskCount--;
    cout << "Task removed successfully.\n";
}

int main() {
    Task tasks[MAX_TASKS];  // Array to store tasks
    int taskCount = 0;  // Number of tasks currently in the list
    int choice;

    while (true) {
        cout << "\nTo-Do List Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks, taskCount);
                break;
            case 2:
                viewTasks(tasks, taskCount);
                break;
            case 3:
                markTaskCompleted(tasks, taskCount);
                break;
            case 4:
                removeTask(tasks, taskCount);
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

