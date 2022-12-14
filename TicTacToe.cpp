#include <iostream>

using namespace std;

void play(char board[]);
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
bool isSpaceFree(int position, char board[])
{
	if (board[position] == '\0')
		return true;
	else
		return false;
}
bool isFull(char board[])
{
		if (isSpaceFree)
			return false;
		else
			return true;
}
void replay(char board[], bool gameOn)
{
	char decision;
	cout << "Do you want to play again? y/n" << endl;
	cin >> decision;
	if (decision == 'y' || decision == 'Y')
	{
		char board[10] = "";
		play(board);
	}
	else
	{
		gameOn = false;
		cout << "Thank you! Good Bye!" << endl;
	}
}
void play(char board[])
{
	//char board[10] = "";
	bool gameOn = true;
	char turn = 'X';
	int position;
	//char board[10] = "";

	while (gameOn)
	{
		displayBoard(board);
		if (turn == 'X')
		{
			cout << "X, where do you want to play? 1-9" << endl;
			cin >> position;
			board[position] = 'X';
			//if (isSpaceFree(position, board))
			//{
			//	board[position] = 'X';
			//}
			//else
			//{
			//	cout << "Cannot play there" << endl;
			//	cin >> position;

			//}
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
				//gameOn = false;
				replay(board, gameOn);
			}
			else
			{
				if (isFull(board))
				{
					displayBoard(board);
					cout << "Draw!";
					replay(board, gameOn);
					//break;
				}
				else
				{
					turn = 'O';
				}
				//turn = 'O';
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
					//gameOn = false;
					replay(board, gameOn);
				}
				else
				{
					if (isFull(board))
					{
						displayBoard(board);
						cout << "Draw!";
						//break;
						replay(board, gameOn);
					}
					else
					{
						turn = 'X';
					}

				}
			}
		}
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
int main()
{
	char test[10] = { '#', ' ','O', '#', '#','X','#','X','O','#' };
	char board[10] = "" ;
	play(board);
	// displayBoard(board);
//	bool gameOn = true;
//
//	while (gameOn)
//	{
//		char turn = 'X';
//		int position;
//		char board[10] = "";
//
//		displayBoard(board);
//		if (turn == 'X')
//		{
//			cout << "X, where do you want to play? 1-9" << endl;
//			cin >> position;
//			if (isSpaceFree(position, board))
//			{
//				board[position] = 'X';
//			}
//			else
//			{
//				cout << "Cannot play there" << endl;
//				cin >> position;
//
//			}
//
//			//if (isSpaceEmpty(position, board))
//			//{
//			//	board[position] = 'X';
//			//}
//			//else
//			//{
//			//	cout << "Space is filled!"
//			//}
//			if (isWinner('X', board))
//			{
//				displayBoard(board);
//				cout << "Congrats X!  You've won!" << endl;
//				gameOn = false;
//				//replay();
//			}
//			else
//			{
//				if (isFull(board))
//				{
//					displayBoard(board);
//					cout << "Draw!";
//					break;
//				}
//				else 
//				{
//					turn = 'O';
//				}
//				//turn = 'O';
//			}
//			if (turn == 'O')
//			{
//				displayBoard(board);
//				cout << "O, where do you want to play? 1-9" << endl;
//				cin >> position;
//				board[position] = 'O';
//				if (isWinner('O', board))
//				{
//					displayBoard(board);
//					cout << "Congrats O!  You've won!" << endl;
//					gameOn = false;
//					//replay();
//				}
//				else
//				{
//					if (isFull(board))
//					{
//						displayBoard(board);
//						cout << "Draw!";
//						break;
//					}
//					else
//					{
//						turn = 'X';
//					}
//					
//				}
//			}
//		}
//		
//
//
////		replay();
//	
//		char decision;
//		cout << "Do you want to play again? y/n" << endl;
//		cin >> decision;
//		if (decision == 'y' || decision == 'Y')
//		{
//			gameOn = true;
//			fill_n(board, 10, ' ');
//			// board[10] = ""; // i can't do this. i need to reset to a new clean board.
//		}
//		else
//		{
//			cout << "Thanks! Good Bye!" << endl;
//		}
//	}
//

	return 0;
}


/* TODO:

1) when 'O' wins and you select no to replay, it displays the board forever.
2) when 'X' wins and you say no, it still displays for X to move
3) DRAW does not work.
4) currently no check for isSpaceFree. 
*/