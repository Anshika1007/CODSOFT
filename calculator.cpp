#include <iostream>
using namespace std;

// Function declarations
void displayMenu();
double performOperation(char operation, double num1, double num2);

int main() {
    double num1, num2, result;
    char operation;
    char choice;

    do {
       
        cout << "Enter the first number: ";
        cin >> num1;
        cout << "Enter the second number: ";
        cin >> num2;

     
        displayMenu();
        
     
        cout << "Choose an operation (+, -, *, /): ";
        cin >> operation;

        // Perform the selected operation and handle division by zero
        if (operation == '/' && num2 == 0) {
            cout << "Error: Division by zero is undefined.\n";
        } else {
            result = performOperation(operation, num1, num2);
            cout << "Result: " << result << endl;
        }

        
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using the calculator." << endl;

    return 0;
}


void displayMenu() {
    cout << "\nAvailable operations:\n";
    cout << "Addition (+)\n";
    cout << "Subtraction (-)\n";
    cout << "Multiplication (*)\n";
    cout << "Division (/)\n";
}


double performOperation(char operation, double num1, double num2) {
    switch (operation) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        default:
            cout << "Invalid operation.\n";
            return 0.0;
    }
}
