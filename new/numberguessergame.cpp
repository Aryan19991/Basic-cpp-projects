#include <iostream>
#include <ctime>
int main()
{
  char playAgain;
  do
  {
    int number;
    std::cout << "Please enter a number between 1 to 100: ";
    std::cin >> number;

    if (number < 1 || number > 100)
    {
      std::cout << "Invalid input! Please enter a number between 1 and 100." << std::endl;
      return 1;
    }
    // To Generate random number
    std::srand(std::time(0));
    int randomNum = rand() % 100 + 1;
    std::cout << "Random number generated:" << randomNum << std::endl;

    if (number == randomNum)
    {
      std::cout << "Congratulations! you have guessed the correct number!" << std::endl;
    }

    else if (number > randomNum)
    {
      std::cout << "The number you have entered is greater than the number generted by the computer. You Lost!" << std::endl;
    }
    else if (number < randomNum)
    {
      std::cout << "The number you have entered is less than the number generted by the computer. You Lost!" << std::endl;
      ;
    }
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> playAgain;
  } while (playAgain == 'y' || playAgain == 'Y');
  std::cout << "Thank You for playing!" << std::endl;
  return 0;
}