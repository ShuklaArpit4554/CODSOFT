#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& taskDesc) {
        tasks.push_back(Task(taskDesc));
        cout << "Task added: " << taskDesc << endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks to display." << endl;
            return;
        }

        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description 
                 << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]" << endl;
        }
    }

    void markTaskCompleted(size_t taskNumber) {
        if (taskNumber == 0 || taskNumber > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }

        tasks[taskNumber - 1].completed = true;
        cout << "Task " << taskNumber << " marked as completed." << endl;
    }

    void removeTask(size_t taskNumber) {
        if (taskNumber == 0 || taskNumber > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }

        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task " << taskNumber << " removed." << endl;
    }
};

int main() {
    ToDoList todoList;
    int choice;
    string taskDesc;
    size_t taskNumber;

    while (true) {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, taskDesc);
                todoList.addTask(taskDesc);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                cout << "Enter task number to mark as completed: ";
                cin >> taskNumber;
                todoList.markTaskCompleted(taskNumber);
                break;
            case 4:
                cout << "Enter task number to remove: ";
                cin >> taskNumber;
                todoList.removeTask(taskNumber);
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
