// COMMAND LINE CALCULATOR WHICH WERE PERFORMS THE BASIC ARITHMETIC OPERATIONS.

#include <iostream>
#include <cmath>

int main()
{
    double numbers[5];
    char op;
    int numCount = 0;

    // Display the menu

    std::cout << "Command Line Calculator\n";
    std::cout << "Choose an operation (+, -, *, /, ^, ln, log10): \n";

    // Get user input
    std::cin >> op;

    // Get upto 5 Inputs
    std::cout << "Enter upto 5 numbers (Kindly press ENTER after each):\n";
    while (numCount < 5)
    {
        if (std::cin >> numbers[numCount])
        {
            numCount++;
        }
        else
        {
            std::cout << "Error: Invalid imput. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    /*
     // In case of two inputs only:-
     std::cout << "Enter the first number: ";
     std::cin >> num1;
     std::cout << "Enter the second number: ";
     std::cin >> num2;
    */

    // Perform the calculations
    double result = numbers[0];
    for (int i = 1; i < numCount; i++)
    {
        switch (op)
        {
        case '+':
            result += numbers[i];
            break;

        case '-':
            result -= numbers[i];
            break;

        case '*':
            result *= numbers[i];
            break;

        case '/':
            if (numbers[i] == 0)
            {
                std::cout << "Error: Division by Zero" << std::endl;
                return 1;
            }
            result /= numbers[i];
            break;

        case '^':
            result = std::pow(result, numbers[i]);
            break;

        case 'l':
        case 'L':
            result = std::log(numbers[i]);
            break;
        case 'o':
        case 'O':
            result = std::log10(numbers[i]);
            break;

        default:
            std::cout << "Error: Invalid Operation being Performed" << std::endl;
            return 1;
            break;
        }
    }

    std::cout << "Result: " << result << std::endl;
    return 0;
}