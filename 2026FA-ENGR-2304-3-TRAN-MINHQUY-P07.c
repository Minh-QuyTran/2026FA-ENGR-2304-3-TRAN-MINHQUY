/*2026FA-ENGR-2304-3-TRAN-MINHQUY-P07*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int WinnerCondition(char board[]) /*Winner patterm with ChatGPT assistance*/
{
	int Patterns[8][3] = {
		{0, 1, 2},
		{3, 4, 5},
		{6, 7, 8},
		{0, 4, 8},
		{2, 4, 6},
		{0, 3, 6},
		{1, 4, 7},
		{2, 5, 8}
	};
	int i;
	for (i = 0;i < 8;i++)
	{
		if (board[Patterns[i][0]] == board[Patterns[i][1]] &&
			board[Patterns[i][1]] == board[Patterns[i][2]])
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	char position[9];
	char firstplayer;
	char computer;
	char secondplayer;
	int choice;
	while (1) {
		printf("1. Player vs Computer\n");
		printf("2. Player vs Player\n");
		printf("3. Exit\n");
		printf("Your choice: ");
		scanf(" %d", &choice);
		int playfirst;
		int firstmove, secondmove, computermove, index;
		char turn[4];
		int gameover = 0;
		int moves = 0;

		if (choice == 1) {
			/*play with computer*/
			for (int i = 0; i < 9; i++)
			{
				position[i] = i + '1';
			}

			for (int i = 0; i < 9; i++)
			{
				printf(" %c ", position[i]);

				if (i % 3 == 2)
				{
					printf("\n");

					if (i != 8)
					{
						printf("---|---|---\n");
					}
				}
				else
				{
					printf("|");
				}
			}
			printf("Choose your symbol (X or O): ");
			scanf(" %c", &firstplayer);
			printf("You are %c\n", firstplayer);
			if (firstplayer == 'X')
			{
				computer = 'O';
			}
			else
			{
				firstplayer = 'O';
				computer = 'X';
			}
			printf("Computer is %c\n", computer);

			printf("\nRandomly selecting who goes first ...\n");
			srand(time(NULL));
			playfirst = rand() % 2;
			if (playfirst == 0)
			{
				printf("\nYou play first!\n");
				printf("Computer play second!\n");
			}
			else
			{
				printf("\nComputer play first!\n");
				printf("You play second!\n");
			}

			while (moves < 9 && gameover == 0)
			{
				if (playfirst == 0)
				{	/*player go first*/
					printf("\nEnter your move (1-9):");
					scanf(" %d", &firstmove);
					index = firstmove - 1;
					while (firstmove >= 1 && firstmove <= 9 && position[index] != '1' + index) /*first i used "if" but later with ChatGPT's assistance,
						i change the code to while for better result*/
					{
						printf("Invalid move! Choose an empty position(1 - 9) : ");
						scanf("%d", &firstmove);
						index = firstmove - 1;
					}
					position[index] = firstplayer;
					moves++; /*ChatGPT helped me to solve the winning pattern problem*/
					for (index = 0;index < 9; index++)
					{
						printf(" %c ", position[index]);
						if (index % 3 == 2)
						{
							if (index != 8)
							{
								printf("\n");
								printf("---|---|---\n");
							}
							else
							{
								printf("\n");
							}
						}
						else
						{
							printf("|");
						}
					}
					if (WinnerCondition(position))
					{
						printf("\nCongratulations! You win!\n");
						gameover = 1;
						break;
					}
					if (moves >= 9) {
						printf("\nIt's a draw game!\n");
						break;
					}

					printf("\nComputer's turn ...\n");
					computermove = rand() % 9 + 1; /*ChatGPT gave me instructions and i tried to do it myself first, then it would review for me later*/
					index = computermove - 1;
					while (position[index] != '1' + index)
					{
						computermove = rand() % 9 + 1;
						index = computermove - 1;
					}
					position[index] = computer;
					moves++;
					for (index = 0;index < 9; index++)
					{
						printf(" %c ", position[index]);
						if (index % 3 == 2)
						{
							if (index != 8)
							{
								printf("\n");
								printf("---|---|---\n");
							}
							else
							{
								printf("\n");
							}
						}
						else
						{
							printf("|");
						}
					}
					if (WinnerCondition(position))
					{
						printf("\nCongratulations! Computer win!\n");
						gameover = 1;
						break;
					}

				}


				else { /*computer go first*/
					printf("\nComputer's turn ...\n");
					computermove = rand() % 9 + 1;
					index = computermove - 1;
					while (position[index] != '1' + index)
					{
						computermove = rand() % 9 + 1;
						index = computermove - 1;
					}
					position[index] = computer;
					moves++;
					for (index = 0;index < 9; index++)
					{
						printf(" %c ", position[index]);
						if (index % 3 == 2)
						{
							if (index != 8)
							{
								printf("\n");
								printf("---|---|---\n");
							}
							else
							{
								printf("\n");
							}
						}
						else
						{
							printf("|");
						}
					}
					if (WinnerCondition(position))
					{
						printf("\nCongratulations! Computer win!\n");
						gameover = 1;
						break;
					}
					if (moves >= 9) {
						printf("\nIt's a draw game!\n");
						break;
					}

					printf("Enter your move (1-9):");
					scanf("%d", &firstmove);
					index = firstmove - 1;
					while (firstmove >= 1 && firstmove <= 9 && position[index] != '1' + index)
					{
						printf("Invalid move!Choose an empty position(1 - 9) : ");
						scanf("%d", &firstmove);
						index = firstmove - 1;
					}
					position[index] = firstplayer;
					moves++;
					for (index = 0;index < 9; index++)
					{
						printf(" %c ", position[index]);
						if (index % 3 == 2)
						{
							if (index != 8)
							{
								printf("\n");
								printf("---|---|---\n");
							}
							else
							{
								printf("\n");
							}
						}
						else
						{
							printf("|");
						}
					}
					if (WinnerCondition(position))
					{
						printf("\nCongratulations! You win!\n");
						gameover = 1;
						break;
					}
				}
			}
			printf("\nGame Over!\n");
		}

		/*Play with other player*/
		else if (choice == 2) {
			for (int i = 0; i < 9; i++)
			{
				position[i] = i + '1';
			}

			for (int i = 0; i < 9; i++)
			{
				printf(" %c ", position[i]);

				if (i % 3 == 2)
				{
					printf("\n");

					if (i != 8)
					{
						printf("---|---|---\n");
					}
				}
				else
				{
					printf("|");
				}
			}
			printf("Choose your symbol (X or O): ");
			scanf(" %c", &firstplayer);
			printf("You are %c\n", firstplayer);
			if (firstplayer == 'X')
			{
				secondplayer = 'O';
			}
			else
			{
				firstplayer = 'O';
				secondplayer = 'X';
			}
			printf("Your opponent is %c\n", secondplayer);
			
			printf("\nRandomly selecting who goes first ...\n");
			srand(time(NULL));
			playfirst = rand() % 2;
			if (playfirst == 0)
			{
				printf("\nYou play first!\n");
				printf("Your opponent play second!\n");
			}
			else
			{
				printf("\nYour opponent play first!\n");
				printf("You play second!\n");
			}

			while (moves < 9 && gameover == 0) 
			{
				if (playfirst == 0)
				{	/*first player go first*/
					printf("\nEnter your move (1-9):");
					scanf(" %d", &firstmove);
					index = firstmove - 1;
					while (firstmove >= 1 && firstmove <= 9 && position[index] != '1' + index)
					{
						printf("Invalid move! Choose an empty position(1 - 9) : ");
						scanf("%d", &firstmove);
						index = firstmove - 1;
					}
					position[index] = firstplayer;
					moves++;
					for (index = 0;index < 9; index++)
					{
						printf(" %c ", position[index]);
						if (index % 3 == 2)
						{
							if (index != 8)
							{
								printf("\n");
								printf("---|---|---\n");
							}
							else
							{
								printf("\n");
							}
						}
						else
						{
							printf("|");
						}
					}
					if (WinnerCondition(position))
					{
						printf("\nCongratulations! You win!\n");
						gameover = 1;
						break;
					}
					if (moves >= 9) {
						printf("\nIt's a draw game!\n");
						break;
					}

					printf("\nYour opponent's choice (1-9): ");
					scanf(" %d", &secondmove);
					index = secondmove - 1;
					while (secondmove >= 1 && secondmove <= 9 && position[index] != '1' + index)
					{
						printf("Invalid move! Choose an empty position(1 - 9) : ");
						scanf("%d", &secondmove);
						index = secondmove - 1;
					}
					position[index] = secondplayer;
					moves++;
					for (index = 0;index < 9; index++)
					{
						printf(" %c ", position[index]);
						if (index % 3 == 2)
						{
							if (index != 8)
							{
								printf("\n");
								printf("---|---|---\n");
							}
							else
							{
								printf("\n");
							}
						}
						else
						{
							printf("|");
						}
					}
					if (WinnerCondition(position))
					{
						printf("\nCongratulations! Your opponent win!\n");
						gameover = 1;
						break;
					}
				}

				else
				{/*second player go first*/
					printf("\nYour opponent's choice (1-9): ");
					scanf(" %d", &secondmove);
					index = secondmove - 1;
					while (secondmove >= 1 && secondmove <= 9 && position[index] != '1' + index)
					{
						printf("Invalid move! Choose an empty position(1 - 9) : ");
						scanf("%d", &secondmove);
						index = secondmove - 1;
					}
					position[index] = secondplayer;
					moves++;
					for (index = 0;index < 9; index++)
					{
						printf(" %c ", position[index]);
						if (index % 3 == 2)
						{
							if (index != 8)
							{
								printf("\n");
								printf("---|---|---\n");
							}
							else
							{
								printf("\n");
							}
						}
						else
						{
							printf("|");
						}
					}
					if (WinnerCondition(position))
					{
						printf("\nCongratulations! Your opponent win!\n");
						gameover = 1;
						break;
					}
					if (moves >= 9) {
						printf("\nIt's a draw game!\n");
						break;
					}
					printf("\nEnter your move (1-9):");
					scanf(" %d", &firstmove);
					index = firstmove - 1;
					while (firstmove >= 1 && firstmove <= 9 && position[index] != '1' + index)
					{
						printf("Invalid move! Choose an empty position(1 - 9) : ");
						scanf("%d", &firstmove);
						index = firstmove - 1;
					}
					position[index] = firstplayer;
					moves++;
					for (index = 0;index < 9; index++)
					{
						printf(" %c ", position[index]);
						if (index % 3 == 2)
						{
							if (index != 8)
							{
								printf("\n");
								printf("---|---|---\n");
							}
							else
							{
								printf("\n");
							}
						}
						else
						{
							printf("|");
						}
					}
					if (WinnerCondition(position))
					{
						printf("\nCongratulations! You win!\n");
						gameover = 1;
						break;
					}
				}
			}
			printf("\nGame Over!\n");
		}

		else {/*end the game*/
			break;
		}
	}
	return 0;
}
