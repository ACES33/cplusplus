#include <iostream>

using namespace std;

void displayBoard(char board[])
{
	cout << "          " << board[7] << "    |    " << board[8] << "   |     " << board[9] << "  " << endl;
	cout << "          " << board[4] << "    |    " << board[5] << "   |     " << board[6] << "  " << endl;
	cout << "          " << board[1] << "    |    " << board[2] << "   |     " << board[3] << "  " << endl;
}

bool isWinner(char turn, char board[])
{
	if (//rows
		((board[9] == turn) && (board[8] == turn) && (board[7] == turn)) ||
		((board[6] == turn) && (board[5] == turn) && (board[4] == turn)) ||
		((board[3] == turn) && (board[2] == turn) && (board[1] == turn)) ||
		//columns
		((board[9] == turn) && (board[6] == turn) && (board[3] == turn)) ||
		((board[8] == turn) && (board[5] == turn) && (board[2] == turn)) ||
		((board[7] == turn) && (board[4] == turn) && (board[1] == turn)) ||
		//diagonals
		((board[9] == turn) && (board[5] == turn) && (board[1] == turn)) ||
		((board[3] == turn) && (board[5] == turn) && (board[7] == turn))
		)
		return true;
	else
		return false;
}

bool isFull(char board[])
{
	for (int i = 1; i <= 9; i++)
	{
		if (!(board[i]))
			return false;
		else
			return true;
	}
}

//void replay()
//{
//	char decision;
//	cout << "Do you want to play again? y/n" << endl;
//	cin >> decision;
//	if (decision == 'y' || decision == 'Y')
//	{
//		gameOn == true;
//	}
//	else
//	{
//		cout << "Thanks! Good Bye!" << endl;
//	}
//
//}
//bool isSpaceEmpty(int position, char board)
//{
//	int position;
//	if (!(board[position] == 'X' || board[position] == 'O'))
//		return true;
//	else
//		return false;
//}
void main()
{
	char test[10] = { '#', ' ','O', '#', '#','X','#','X','O','#' };
	// displayBoard(board);
	bool gameOn = true;
	char turn = 'X';
	int position;
	char board[10] = {};
	while (gameOn)
	{
		displayBoard(board);
		if (turn == 'X')
		{
			cout << "X, where do you want to play? 1-9" << endl;
			cin >> position;
			board[position] = 'X';
			//if (isSpaceEmpty(position, board))
			//{
			//	board[position] = 'X';
			//}
			//else
			//{
			//	cout << "Space is filled!"
			//}
			if (isWinner('X', board))
			{
				displayBoard(board);
				cout << "Congrats X!  You've won!" << endl;
				gameOn = false;
			}
			else
			{
				if (isFull(board))
				{
					displayBoard(board);
					cout << "Draw!";
					break;
				}
				turn = 'O';
			}
			if (turn == 'O')
			{
				displayBoard(board);
				cout << "O, where do you want to play? 1-9" << endl;
				cin >> position;
				board[position] = 'O';
				if (isWinner('O', board))
				{
					displayBoard(board);
					cout << "Congrats O!  You've won!" << endl;
					gameOn = false;
				}
				else
				{
					if (isFull(board))
					{
						displayBoard(board);
						cout << "Draw!";
						break;
					}
					turn = 'X';
				}
			}
		}
		


//		replay();
	
		char decision;
		cout << "Do you want to play again? y/n" << endl;
		cin >> decision;
		if (decision == 'y' || decision == 'Y')
		{
			gameOn = true;
		}
		else
		{
			cout << "Thanks! Good Bye!" << endl;
		}
	}


}