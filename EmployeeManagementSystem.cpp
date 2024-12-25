#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Define a structure for Employee
struct Employee {
    int id;
    std::string name;
    std::string position;
    double salary;
};

// Function to set text color
void SetColor(int color) {
    std::cout << "\033[1;" << color << "m";
}

// Function to reset color
void ResetColor() {
    std::cout << "\033[0m";
}

// Function to show the menu
void showMenu() {
    SetColor(34);  // Blue color
    std::cout << "\nEmployee Management System\n";
    ResetColor();

    std::cout << "1. Add Employee\n";
    std::cout << "2. View Employees\n";
    std::cout << "3. Update Employee\n";
    std::cout << "4. Delete Employee\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option: ";
}

// Function to add a new employee
void addEmployee(std::vector<Employee>& employees) {
    SetColor(32);  // Green color for input prompt
    Employee emp;
    std::cout << "Enter employee ID: ";
    std::cin >> emp.id;
    std::cout << "Enter employee name: ";
    std::cin.ignore();  // To clear the input buffer
    std::getline(std::cin, emp.name);
    std::cout << "Enter employee position: ";
    std::getline(std::cin, emp.position);
    std::cout << "Enter employee salary: ";
    std::cin >> emp.salary;
    employees.push_back(emp);
    ResetColor();
}

// Function to view all employees
void viewEmployees(const std::vector<Employee>& employees) {
    SetColor(36);  // Cyan color for header
    std::cout << "\nEmployee List\n";
    ResetColor();

    for (const auto& emp : employees) {
        std::cout << "ID: " << emp.id << ", Name: " << emp.name
                  << ", Position: " << emp.position << ", Salary: " << emp.salary << std::endl;
    }
}

// Function to update an employee's details
void updateEmployee(std::vector<Employee>& employees) {
    SetColor(32);  // Green color for input prompt
    int id;
    std::cout << "Enter employee ID to update: ";
    std::cin >> id;

    auto it = std::find_if(employees.begin(), employees.end(), [id](const Employee& emp) {
        return emp.id == id;
    });

    if (it != employees.end()) {
        std::cout << "Enter new name: ";
        std::cin.ignore();
        std::getline(std::cin, it->name);
        std::cout << "Enter new position: ";
        std::getline(std::cin, it->position);
        std::cout << "Enter new salary: ";
        std::cin >> it->salary;
    } else {
        SetColor(31);  // Red color for error message
        std::cout << "Employee not found!\n";
        ResetColor();
    }
}

// Function to delete an employee
void deleteEmployee(std::vector<Employee>& employees) {
    SetColor(32);  // Green color for input prompt
    int id;
    std::cout << "Enter employee ID to delete: ";
    std::cin >> id;

    auto it = std::remove_if(employees.begin(), employees.end(), [id](const Employee& emp) {
        return emp.id == id;
    });

    if (it != employees.end()) {
        employees.erase(it, employees.end());
        SetColor(33);  // Yellow color for success message
        std::cout << "Employee deleted successfully.\n";
        ResetColor();
    } else {
        SetColor(31);  // Red color for error message
        std::cout << "Employee not found!\n";
        ResetColor();
    }
}

int main() {
    std::vector<Employee> employees;
    int choice;

    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                addEmployee(employees);
                break;
            case 2:
                viewEmployees(employees);
                break;
            case 3:
                updateEmployee(employees);
                break;
            case 4:
                deleteEmployee(employees);
                break;
            case 5:
                SetColor(34);  // Blue color for exit message
                std::cout << "Exiting program...\n";
                ResetColor();
                break;
            default:
                SetColor(31);  // Red color for invalid choice
                std::cout << "Invalid choice. Please try again.\n";
                ResetColor();
        }
    } while (choice != 5);

    return 0;
}
