#include <iostream>
#include <string>
#include <vector>

struct Task {
	std::string name;
	std::string description;
	bool isDone;
};

void addTask(std::vector<Task>& tasks) {
	Task newTask;
	std::cout << "Task name: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, newTask.name);
	std::cout << "Task description: ";
	std::getline(std::cin, newTask.description);
	newTask.isDone = false;
	tasks.push_back(newTask);
}

void deleteTask(std::vector<Task>& tasks) {
	int choice;
	std::cout << "Choose a task to delete: ";
	std::cin >> choice;
	if (choice >= tasks.size() || choice < 0)
	{
		std::cout << "Invalid choice" << std::endl;
		return;
	}
	tasks.erase(tasks.begin() + choice);
}

void listTasks(const std::vector<Task>& tasks) {
	for (int i = 0; i < tasks.size(); i++) 
		std::cout << i << ". " << tasks[i].name << " " << (tasks[i].isDone ? "Done" : "Not done") << std::endl;
}

void markTask(std::vector<Task>& tasks) {
	int choice;
	std::cout << "Choose a task to mark/unmark: ";
	std::cin >> choice;
	if (choice >= tasks.size() || choice < 0)
	{
		std::cout << "Invalid choice" << std::endl;
		return;
	}
	tasks[choice].isDone = !tasks[choice].isDone;
}

void readTaskDescription(const std::vector<Task>& tasks) {
	int choice; 
	std::cout << "Choose a task for description: ";
	std::cin >> choice;
	if (choice >= tasks.size() || choice < 0)
	{
		std::cout << "Invalid choice" << std::endl;
		return;
	}
	std::cout << tasks[choice].description << std::endl;
}

void printHelp() {
	std::cout << "0 to add a task" << std::endl
		<< "1 to delete a task" << std::endl
		<< "2 to list all tasks" << std::endl
		<< "3 to mark/unmark a task as done" << std::endl
		<< "4 to read task description" << std::endl
		<< "5 to exit" << std::endl
		<< "6 to help" << std::endl;
}

int main() {
	std::vector<Task> tasks;
	std::cout << "Welcome to the To-Do List" << std::endl
		<< "0 to add a task" << std::endl
		<< "1 to delete a task" << std::endl
		<< "2 to list all tasks" << std::endl
		<< "3 to mark/unmark a task as done" << std::endl
		<< "4 to read task description" << std::endl
		<< "5 to exit" << std::endl
		<< "6 to help" << std::endl;

	int choice;
	while (true) {
		std::cin >> choice;
		switch (choice) {
		case 0:
			addTask(tasks);
			break;
		case 1:
			deleteTask(tasks);
			break;
		case 2:
			listTasks(tasks);
			break;
		case 3:
			markTask(tasks);
			break;
		case 4:
			readTaskDescription(tasks);
			break;
		case 5:
			return 0;
		case 6:
			printHelp();
			break;
		}
	}
}