#include <iostream>

// Function to initialize the board
void initializeBoard(char board[3][3])
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      board[i][j] = ' ';
    }
  }
}

// Function to display the board
void displayBoard(char board[3][3])
{
  std::cout << " 0 1 2" << std::endl;
  for (int i = 0; i < 3; i++)
  {
    std::cout << " ";
    for (int j = 0; j < 3; j++)
    {
      std::cout << board[i][j];
      // Making vertical separator
      if (j < 2)
        std::cout << "|";
    }
    std::cout << std::endl;
    // Making horizontal separator
    if (i < 2)
      std::cout << "-------" << std::endl;
  }
}

// Function to check for a win condition
bool checkWin(char board[3][3], char player)
{
  // Check rows
  for (int i = 0; i < 3; i++)
  {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
    {
      return true;
    }
  }

  // Check columns
  for (int j = 0; j < 3; j++)
  {
    if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
    {
      return true;
    }
  }

  // Check diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
  {
    return true;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
  {
    return true;
  }

  return false;
}

// Function to check for a draw condition
bool checkDraw(char board[3][3])
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (board[i][j] == ' ')
      {
        // Found an empty space, not a draw
        return false;
      }
    }
  }
  // No empty spaces, it's a draw
  return true;
}

// Function to handle player moves
void playerMove(int &player1, int &player2, char board[3][3])
{
  // Player 1's move
  std::cout << "Player 1, please enter the place where you would like to make your move (1-9): ";
  std::cin >> player1;
  if (player1 < 1 || player1 > 9)
  {
    std::cout << "Invalid move! Please enter a number between 1 and 9." << std::endl;
    return;
  }

  int row = (player1 - 1) / 3;
  int col = (player1 - 1) % 3;

  if (board[row][col] != ' ')
  {
    std::cout << "Incorrect Move! This space is already occupied." << std::endl;
    return;
  }
  // Player 1 gets the 'X'
  board[row][col] = 'X';
  std::cout << "Player 1 moves to " << player1 << " (X)" << std::endl;
  displayBoard(board);

  // Check for win condition for Player 1
  if (checkWin(board, 'X'))
  {
    std::cout << "Player 1 wins!" << std::endl;
    exit(0);
  }

  // Check for draw condition
  if (checkDraw(board))
  {
    std::cout << "The game is a draw!" << std::endl;
    exit(0);
  }

  // Player 2's move
  std::cout << "Player 2, please enter the place where you would like to counter your opponent (1-9): ";
  std::cin >> player2;
  if (player2 < 1 || player2 > 9)
  {
    std::cout << "Invalid move! Please enter a number between 1 and 9." << std::endl;
    return;
  }

  row = (player2 - 1) / 3;
  col = (player2 - 1) % 3;

  if (board[row][col] != ' ')
  {
    std::cout << "Incorrect Move! This space is already occupied." << std::endl;
    return;
  }
  // Player 2 gets the 'O'
  board[row][col] = 'O';
  std::cout << "Player 2 moves to " << player2 << " (O)" << std::endl;
  displayBoard(board);

  // Check for win condition for Player 2
  if (checkWin(board, 'O'))
  {
    std::cout << "Player 2 wins!" << std::endl;
    exit(0);
  }

  // Check for draw condition
  if (checkDraw(board))
  {
    std::cout << "The game is a draw!" << std::endl;
    exit(0);
  }
}

// Main function to run the game
int main()
{
  char board[3][3];
  initializeBoard(board);
  int player1, player2;

  while (true)
  {
    playerMove(player1, player2, board);
  }

  return 0;
}
