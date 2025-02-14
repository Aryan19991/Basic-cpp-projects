#include <iostream>
#include <cmath>
int main()
{
  char decision;
  double firstNumber;
  double secondNumber;
  char anotherOperation;
  do
  {
    std::cout << "Please choose an operation(+, -, *, /,^,sqrt): ";
    std::cin >> decision;

    if (decision == '+')
    {
      std::cout << "You have chosen 'Addition'!" << std::endl;
      std::cout << "Enter a number: " << std::endl;
      std::cin >> firstNumber;
      std::cout << "Enter second number: " << std::endl;
      std::cin >> secondNumber;
      std::cout << "Result: " << firstNumber + secondNumber << std::endl;
    }

    else if (decision == '-')
    {

      std::cout << "You have chosen 'Subtraction'!" << std::endl;
      std::cout << "Enter a number: " << std::endl;
      std::cin >> firstNumber;
      std::cout << "Enter second number: " << std::endl;
      std::cin >> secondNumber;
      std::cout << "Result: " << firstNumber - secondNumber << std::endl;
    }

    else if (decision == '*')
    {

      std::cout << "You have chosen'Multiplication'!" << std::endl;
      std::cout << "Enter a number: " << std::endl;
      std::cin >> firstNumber;
      std::cout << "Enter second number: " << std::endl;
      std::cin >> secondNumber;
      std::cout << "Result: " << firstNumber * secondNumber << std::endl;
    }

    else if (decision == '/')
    {

      std::cout << "You have chosen 'Division'!" << std::endl;
      std::cout << "Enter a number: " << std::endl;
      std::cin >> firstNumber;
      std::cout << "Enter second number: " << std::endl;
      std::cin >> secondNumber;
      if (secondNumber == 0)
      {
        std::cout << "Error:Division by zero is not allowed" << std::endl;
      }
      else
      {
        std::cout << "Result: " << firstNumber / secondNumber << std::endl;
      }
    }
    else if (decision == '^')
    {

      std::cout << "You have chosen 'Power'!" << std::endl;
      std::cout << "Enter a number: " << std::endl;
      std::cin >> firstNumber;
      std::cout << "Enter the power you want to raise it to: " << std::endl;
      std::cin >> secondNumber;
      std::cout << "Result: " << std::pow(firstNumber, secondNumber) << std::endl;
    }
    // Using 's' for square root operations.
    else if (decision == 's')
    {
      std::cout << "You have chosen 'Square Root':" << std::endl;
      std::cout << "Enter a number: ";
      std::cin >> firstNumber;
      if (firstNumber < 0)
      {
        std::cout << " Please enter a valid input.The square root of a negative integer is a complex number.";
      }
      else
      {
        std::cout << "Result: " << std::sqrt(firstNumber) << std::endl;
      }
    }
    else
    {
      std::cout << "Invalid operation!!!!!!. please chose a valid input." << std::endl;
    }
    std::cout << "Do you want to do another operation(y/n): " << std::endl;
    std::cin >> anotherOperation;
  } while (anotherOperation == 'y' || anotherOperation == 'Y');

  std::cout << "Thankyou!" << std::endl;
  return 0;
}