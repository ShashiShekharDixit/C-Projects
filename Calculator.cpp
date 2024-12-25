#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

void showMenu() {
    cout << "\n=====================================" << endl;
    cout << "          Advanced Calculator" << endl;
    cout << "=====================================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Square Root" << endl;
    cout << "6. Power" << endl;
    cout << "7. Sine (sin)" << endl;
    cout << "8. Cosine (cos)" << endl;
    cout << "9. Tangent (tan)" << endl;
    cout << "10. Inverse Sine (asin)" << endl;
    cout << "11. Inverse Cosine (acos)" << endl;
    cout << "12. Inverse Tangent (atan)" << endl;
    cout << "13. Exit" << endl;
    cout << "=====================================" << endl;
}

void printResult(string message, double result) {
    cout << "\n==================== RESULT ====================" << endl;
    cout << ">>> " << message << endl;
    cout << ">>> " << fixed << setprecision(2) << result << endl;
    cout << "===============================================" << endl;
}

void printError(string errorMessage) {
    cout << "\n************** ERROR **************" << endl;
    cout << "* " << errorMessage << " *" << endl;
    cout << "************************************" << endl;
}

int main() {
    double num1, num2;
    int choice;

    while (true) {
        showMenu();
        cout << "Enter your choice (1-13): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter two numbers: ";
                cin >> num1 >> num2;
                printResult("Addition Result", num1 + num2);
                break;

            case 2:
                cout << "\nEnter two numbers: ";
                cin >> num1 >> num2;
                printResult("Subtraction Result", num1 - num2);
                break;

            case 3:
                cout << "\nEnter two numbers: ";
                cin >> num1 >> num2;
                printResult("Multiplication Result", num1 * num2);
                break;

            case 4:
                cout << "\nEnter two numbers: ";
                cin >> num1 >> num2;
                if (num2 != 0) {
                    printResult("Division Result", num1 / num2);
                } else {
                    printError("Error! Division by zero is not allowed.");
                }
                break;

            case 5:
                cout << "\nEnter a number: ";
                cin >> num1;
                if (num1 >= 0) {
                    printResult("Square Root", sqrt(num1));
                } else {
                    printError("Error! Cannot calculate square root of a negative number.");
                }
                break;

            case 6:
                cout << "\nEnter base and exponent: ";
                cin >> num1 >> num2;
                printResult("Power Result", pow(num1, num2));
                break;

            case 7:
                cout << "\nEnter an angle in degrees: ";
                cin >> num1;
                num1 = num1 * (M_PI / 180);
                printResult("Sine Result", sin(num1));
                break;

            case 8:
                cout << "\nEnter an angle in degrees: ";
                cin >> num1;
                num1 = num1 * (M_PI / 180);
                printResult("Cosine Result", cos(num1));
                break;

            case 9:
                cout << "\nEnter an angle in degrees: ";
                cin >> num1;
                num1 = num1 * (M_PI / 180);
                printResult("Tangent Result", tan(num1));
                break;

            case 10:
                cout << "\nEnter a value between -1 and 1: ";
                cin >> num1;
                if (num1 >= -1 && num1 <= 1) {
                    printResult("Inverse Sine Result", asin(num1));
                } else {
                    printError("Error! The value must be between -1 and 1.");
                }
                break;

            case 11:
                cout << "\nEnter a value between -1 and 1: ";
                cin >> num1;
                if (num1 >= -1 && num1 <= 1) {
                    printResult("Inverse Cosine Result", acos(num1));
                } else {
                    printError("Error! The value must be between -1 and 1.");
                }
                break;

            case 12:
                cout << "\nEnter a value: ";
                cin >> num1;
                printResult("Inverse Tangent Result", atan(num1));
                break;

            case 13:
                cout << "\n=====================================" << endl;
                cout << "Exiting the program. Goodbye!" << endl;
                cout << "=====================================" << endl;
                return 0;

            default:
                printError("Invalid choice! Please select a valid option.");
        }
    }

    return 0;
}