#include <iostream>
#include <stdbool.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <utility>

#define COMPUTER 1 
#define HUMAN 2 
#define SIDE 7 
#define COMPUTERMOVE 'O' 
#define HUMANMOVE 'X' 
  
// ---------------- Intelligent Moves start 
int blank;
int turn;
int score;  
struct Move { 
    int row, col; 
}; 
  
char player = 'x', opponent = 'o'; 
  
bool isMovesLeft(char board[7][7]) 
{ 
    for (int i = 0; i < 7; i++) 
        for (int j = 0; j < 7; j++) 
            if (board[i][j] == '_') 
                return true; 
    return false; 
}
void shuffleMoves(Move moves[], int size) {
    for (int i = size - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        std::swap(moves[i], moves[j]);
    }
}
int minimax(char board[7][7], int depth, bool isMax) 
{ 
  
    // If Maximizer has won the game return his/her 
    // evaluated score 
    if (score >= 0) 
        return score; 
  
    // If Minimizer has won the game return his/her 
    // evaluated score 
    if (score <= 0) 
        return score; 
  
    // If there are no more moves and no winner then 
    // it is a tie 
    if (isMovesLeft(board) == false)  
        return 0; 
  
    Move moves[49];
    int k = 0;

    // Traverse all cells and store the moves
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (board[i][j] == '_') {
                moves[k].row = i;
                moves[k].col = j;
                k++;
            }
        }
    }

    // Shuffle the order of moves
    shuffleMoves(moves, k);
	int best;
    // Traverse the shuffled moves
    for (int l = 0; l < k; ++l) {
        int i = moves[l].row;
        int j = moves[l].col;

        // Check if cell is empty
        if (board[i][j] == '_') {
            // Make the move
            board[i][j] = (isMax) ? player : opponent;

            // Call minimax recursively and choose
            int val = minimax(board, depth + 1, !isMax);

            // Undo the move
            board[i][j] = '_';

            if (isMax) {
                if (val > best) {
                    best = val;
                }
            } else {
                if (val < best) {
                    best = val;
                }
            }
        }
    }

    return best;
} 
  
// This will return the best possible move for the player 
struct Move findBestMove(char board[7][7]) {
    int bestVal = -80;
    struct Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    // ... (other parts of your code)

    // Create an array to store the moves
    Move moves[49];
    int k = 0;

    // Traverse all cells and store the moves
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (board[i][j] == '_') {
                moves[k].row = i;
                moves[k].col = j;
                k++;
            }
        }
    }

    // Shuffle the order of moves
    shuffleMoves(moves, k);

    // Traverse the shuffled moves
    for (int l = 0; l < k; ++l) {
        int i = moves[l].row;
        int j = moves[l].col;

        // Check if cell is empty
        if (board[i][j] == '_') {
            // Make the move
            board[i][j] = player;

            int moveVal = minimax(board, 0, false);

            // Undo the move
            board[i][j] = '_';

            if (moveVal > bestVal) {
                bestMove.row = i;
                bestMove.col = j;
                bestVal = moveVal;
            }
        }
    }

    return bestMove;
} 
  
// Function to display the game board 
void showBoard(char board[][SIDE]) 
{ 
    printf("\n\n"); 
    printf("\t\t\t %c | %c | %c | %c | %c | %c | %c \n", board[0][0], 
           board[0][1], board[0][2], board[0][3], board[0][4], board[0][5], board[0][6]); 
    printf("\t\t\t---------------------------\n"); 
    printf("\t\t\t %c | %c | %c | %c | %c | %c | %c \n", board[1][0], 
           board[1][1], board[1][2], board[1][3], board[1][4], board[1][5], board[1][6]); 
    printf("\t\t\t---------------------------\n"); 
    printf("\t\t\t %c | %c | %c | %c | %c | %c | %c \n", board[2][0], 
           board[2][1], board[2][2], board[2][3], board[2][4], board[2][5], board[2][6]);
	printf("\t\t\t---------------------------\n"); 
    printf("\t\t\t %c | %c | %c | %c | %c | %c | %c \n", board[3][0], 
           board[3][1], board[3][2], board[3][3], board[3][4], board[3][5], board[3][6]);
	printf("\t\t\t---------------------------\n"); 
    printf("\t\t\t %c | %c | %c | %c | %c | %c | %c \n", board[4][0], 
           board[4][1], board[4][2], board[4][3], board[4][4], board[4][5], board[4][6]);
	printf("\t\t\t---------------------------\n"); 
    printf("\t\t\t %c | %c | %c | %c | %c | %c | %c \n", board[5][0], 
           board[5][1], board[5][2], board[5][3], board[5][4], board[5][5], board[5][6]);
	printf("\t\t\t---------------------------\n");
	printf("\t\t\t %c | %c | %c | %c | %c | %c | %c \n", board[6][0], 
           board[6][1], board[6][2], board[6][3], board[6][4], board[6][5], board[6][6]);
    printf("\t\t\t---------------------------\n");
		   
} 
  
// Function to show the instructions 
void showInstructions() 
{ 
    printf("\t\t\t 7X7 Tic-Tac-Toe Game\n\n"); 
    printf("Choose a row numbered from a to g and column numbered from 1 to 7 as below "
           "and play\n\n"); 
  
    printf("\t\t\t   1   2   3   4   5   6   7   \n"); 
    printf("\t\t\t a _ | _ | _ | _ | _ | _ | _ \n"); 
    printf("\t\t\t  ---------------------------\n"); 
    printf("\t\t\t b _ | _ | _ | _ | _ | _ | _ \n"); 
    printf("\t\t\t  ---------------------------\n"); 
    printf("\t\t\t c _ | _ | _ | _ | _ | _ | _ \n");
    printf("\t\t\t  ---------------------------\n"); 
    printf("\t\t\t d _ | _ | _ | _ | _ | _ | _ \n");    
    printf("\t\t\t  ---------------------------\n");
    printf("\t\t\t e _ | _ | _ | _ | _ | _ | _ \n");
    printf("\t\t\t  ---------------------------\n");
    printf("\t\t\t f _ | _ | _ | _ | _ | _ | _ \n");
    printf("\t\t\t  ---------------------------\n");
    printf("\t\t\t g _ | _ | _ | _ | _ | _ | _ \n");
    printf("\t\t\t  ---------------------------\n\n");
    printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n"); 
} 
  
// Function to initialise the game 
void initialise(char board[][SIDE], int moves[]) 
{ 
    srand(time(NULL)); 
  
    // Initially, the board is empty 
    for (int i = 0; i < SIDE; i++) { 
        for (int j = 0; j < SIDE; j++) 
            board[i][j] = ' '; 
    } 
  
    // Fill the moves with numbers 
    for (int i = 0; i < SIDE * SIDE; i++) 
        moves[i] = i; 
  
    // Randomize the moves 
    for (int i = 0; i < SIDE * SIDE; i++) { 
        int randIndex = rand() % (SIDE * SIDE); 
        int temp = moves[i]; 
        moves[i] = moves[randIndex]; 
        moves[randIndex] = temp; 
    } 
} 
  
// Function to declare the winner of the game 
void declareWinner(int whoseTurn) 
{ 
    if (blank < 0){
        printf("COMPUTER has won\n");
		printf("Blank Value: %d\n",blank);
		printf("AI Score: %d\n",score); 
		printf("Turn Value: %d\n",turn); } 
    else if (blank > 0){
        printf("HUMAN has won\n");
        printf("Blank Value: %d\n",blank);
		printf("AI Score: %d\n",score); 
		printf("Turn Value: %d\n",turn); }
} 
  
int moreBlank(char board[][SIDE]) 
{
	if (turn > 9 && turn %2 == 0){
		if (blank != 0){
			return 1;}
		else{
			return 0;}
	}
	else {
    return 0;} 
} 
  
// Function to check if the game is over 
int gameOver(char board[][SIDE]) 
{ 
    return (moreBlank(board)); 
} 
  
// Function to play Tic-Tac-Toe 
void playTicTacToe(int whoseTurn) 
{ 
    // A 7*7 Tic-Tac-Toe board for playing 
    char board[SIDE][SIDE]; 
    int moves[SIDE * SIDE]; 
  
    // Initialise the game 
    initialise(board, moves); 
  
    // Show the instructions before playing 
    showInstructions(); 
  
    int moveIndex = 0, x, y; 
  
    // Keep playing until the game is over or it is a draw 
    while (!gameOver(board) && moveIndex != SIDE * SIDE) { 
        if (whoseTurn == COMPUTER) { 
  			printf("Blank Value: %d\n",blank);
			printf("AI Score: %d\n",score); 
			printf("Turn Value: %d\n",turn); 
            char tempBoard[7][7]; 
            for (int i = 0; i < 7; i++) { 
                for (int j = 0; j < 7; j++) { 
                    if (board[i][j] == 'X') { 
                        tempBoard[i][j] = 'x'; 
                    } 
                    else if (board[i][j] == 'O') { 
                        tempBoard[i][j] = 'o'; 
                    } 
                    else { 
                        tempBoard[i][j] = '_'; 
                    } 
                } 
            } 
            struct Move thisMove = findBestMove(tempBoard); 
            x = thisMove.row; 
            y = thisMove.col; 
  			if (x==0 && y==0){// Functions for blank and score detection
				if (board[x+1][y] != opponent){
					blank--;
					score+=10;}
				else if (board[x+1][y] == opponent){
					blank++;
					score-=10;
				}
				if (board[x][y+1] != opponent){
					blank--;
					score+=10;}
				else if (board[x][y+1] == opponent){
					blank++;
					score-=10;
				}
				else{
					continue;}}
			else if (x==0 && y==6){
				if (board[x+1][y] != opponent){
					blank--;
					score+=10;}
				else if (board[x+1][y] == opponent){
					blank++;
					score-=10;}
				if (board[x][y-1] != opponent){
					blank--;
					score+=10;}
				else if (board[x][y-1] == opponent){
					blank++;
					score-=10;
				}
				else{
					continue;}
				}
			else if (x==6 && y==6){
				if (board[x-1][y] != opponent){
					blank--;
					score+=10;}
				else if (board[x-1][y] == opponent){
					blank++;
					score-=10;
				}
				if (board[x][y-1] != opponent){
					blank--;
					score+=10;}
				else if (board[x][y-1] == opponent){
					blank++;
					score-=10;
				}
				else{
					continue;}
				}
			else if (x==6 && y==0){
				if (board[x-1][y] != opponent){
					blank--;
					score+=10;}
				else if (board[x-1][y] == opponent){
					blank++;
					score-=10;
				}
				if (board[x][y+1] != opponent){
					blank--;
					score+=10;}
				else if (board[x][y+1] == opponent){
					blank++;
					score-=10;
				}
				else{
					continue;}
				}
			else if ((x > 0 && x < 6) && y==0){
				if (board[x+1][y] != opponent){
					blank--;
					score+=10;}
				else if (board[x+1][y] == opponent){
					blank++;
					score-=10;
				}
				if (board[x-1][y] != opponent){
					blank--;
					score+=10;}
				else if (board[x-1][y] == opponent){
					blank++;
					score-=10;
				}
				if (board[x][y+1] != opponent){
					blank--;
					score+=10;}
				else if (board[x][y+1] == opponent){
					blank++;
					score-=10;
				}
				else{
					continue;}
				}
        	else if ((x > 0 && x < 6) && y==6){
				if (board[x+1][y] != opponent){
					blank--;
					score+=10;}
				else if (board[x+1][y] == opponent){
					blank++;
					score-=10;
				}
				if (board[x-1][y] != opponent){
					blank--;
					score+=10;}
				else if (board[x-1][y] == opponent){
					blank++;
					score-=10;
				}
				if (board[x][y-1] != opponent){
					blank--;
					score+=10;}
				else if (board[x][y-1] == opponent){
					blank++;
					score-=10;
				}
				else{
					continue;}
				}
        	else if (x==6 && (y > 0 && y < 6) ){
				if (board[x][y+1] != opponent){
					blank--;
					score+=10;}
				else if (board[x][y+1] == opponent){
					blank++;
					score-=10;
				}
				if (board[x][y-1] != opponent){
					blank--;
					score+=10;}
				else if (board[x][y-1] == opponent){
					blank++;
					score-=10;
				}
				if (board[x-1][y] != opponent){
					blank--;
					score+=10;}
				else if (board[x-1][y] == opponent){
					blank++;
					score-=10;
				}
				else{
					continue;}
				}
        	else if (x==0 && (y > 0 && y < 6)){
				if (board[x][y+1] != opponent){
					blank--;
					score+=10;}
				else if (board[x][y+1] == opponent){
					blank++;
					score-=10;
				}
				if (board[x][y-1] != opponent){
					blank--;
					score+=10;}
				else if (board[x][y-1] == opponent){
					blank++;
					score-=10;
				}
				if (board[x+1][y] != opponent){
					blank--;
					score+=10;}
				else if (board[x+1][y] == opponent){
					blank++;
					score-=10;
				}
				else{
					continue;}
				}
        	else if ((x > 0 && x < 6) && (y > 0 && y < 6)){
				if (board[x][y+1] != opponent){
					blank--;
					score+=10;}
				else if (board[x][y+1] == opponent){
					blank++;
					score-=10;
				}
				if (board[x][y-1] != opponent){
					blank--;
					score+=10;}
				else if (board[x][y-1] == opponent){
					blank++;
					score-=10;
				}
				if (board[x+1][y] != opponent){
					blank--;
					score+=10;}
				else if (board[x+1][y] == opponent){
					blank++;
					score-=10;
				}
				if (board[x-1][y] != opponent){
					blank--;
					score+=10;}
				else if (board[x-1][y] == opponent){
					blank++;
					score-=10;
				}
				else{
					continue;}
				}
            board[x][y] = COMPUTERMOVE; 
            printf("COMPUTER has put a %c in cell %d %d\n", 
                   COMPUTERMOVE, x, y); 
            showBoard(board); 
            moveIndex++;
			turn ++; 
            whoseTurn = HUMAN;
			 
        } 
        else if (whoseTurn == HUMAN) { 
            int move;
			printf("Blank Value: %d\n",blank);
			printf("AI Score: %d\n",score); 
			printf("Turn Value: %d\n",turn); 
            printf("Enter your move (1-49): "); 
            scanf("%d", &move);			 
            if (move < 1 || move > 49) { 
                printf("Invalid input! Please enter again "
                       "number between 1 and 49.\n"); 
                continue; 
            } 
            x = (move - 1) / SIDE; 
            y = (move - 1) % SIDE;
			if (x==0 && y==0){// Functions for blank and score detection
				if (board[x+1][y] != player ){
					blank++;
					score-=10;}
				else if (board[x+1][y] == player){
					blank--;
					score+=10;
				}
				if (board[x][y+1] != player){
					blank++;
					score-=10;}
				else if (board[x][y+1] == player){
					blank--;
					score+=10;
				}
				else{
					continue;}}
			else if (x==0 && y==6){
				if (board[x+1][y] != player){
					blank++;
					score-=10;}
				else if (board[x+1][y] == player){
					blank--;
					score+=10;
				}
				if (board[x][y-1] != player){
					blank++;
					score-=10;}
				else if (board[x][y-1] == player){
					blank--;
					score+=10;
				}
				else{
					continue;}
				}
			else if (x==6 && y==6){
				if (board[x-1][y] != player){
					blank++;
					score-=10;}
				else if (board[x-1][y] == player){
					blank--;
					score+=10;
				}
				if (board[x][y-1] != player){
					blank++;
					score-=10;}
				else if (board[x][y-1] == player){
					blank--;
					score+=10;
				}
				else{
					continue;}
				}
			else if (x==6 && y==0){
				if (board[x-1][y] != player){
					blank++;
					score-=10;}
				else if (board[x-1][y] == player){
					blank--;
					score+=10;
				}
				if (board[x][y+1] != player){
					blank++;
					score-=10;}
				else if (board[x][y+1] == player){
					blank--;
					score+=10;
				}
				else{
					continue;}
				}
			else if ((x > 0 && x < 6) && y==0){
				if (board[x+1][y] != player){
					blank++;
					score-=10;}
				else if (board[x+1][y] == player){
					blank--;
					score+=10;
				}
				if (board[x-1][y] != player){
					blank++;
					score-=10;}
				else if (board[x-1][y] == player){
					blank--;
					score+=10;
				}
				if (board[x][y+1] != player){
					blank++;
					score-=10;}
				else if (board[x][y+1] == player){
					blank--;
					score+=10;
				}
				else{
					continue;}
				}
        	else if ((x > 0 && x < 6) && y==6){
				if (board[x+1][y] != player){
					blank++;
					score-=10;}
				else if (board[x+1][y] == player){
					blank--;
					score+=10;
				}
				if (board[x-1][y] != player){
					blank++;
					score-=10;}
				else if (board[x-1][y] == player){
					blank--;
					score+=10;
				}
				if (board[x][y-1] != player){
					blank++;
					score-=10;}
				else if (board[x][y-1] == player){
					blank--;
					score+=10;
				}
				else{
					continue;}
				}
        	else if (x==6 && (y > 0 && y < 6) ){
				if (board[x][y+1] != player){
					blank++;
					score-=10;}
				else if (board[x][y+1] == player){
					blank--;
					score+=10;
				}
				if (board[x][y-1] != player){
					blank++;
					score-=10;}
				else if (board[x][y-1] == player){
					blank--;
					score+=10;
				}
				if (board[x-1][y] != player){
					blank++;
					score-=10;}
				else if (board[x-1][y] == player){
					blank--;
					score+=10;
				}
				else{
					continue;}
				}
        	else if (x==0 && (y > 0 && y < 6)){
				if (board[x][y+1] != player){
					blank++;
					score-=10;}
				else if (board[x][y+1] == player){
					blank--;
					score+=10;
				}
				if (board[x][y-1] != player){
					blank++;
					score-=10;}
				else if (board[x][y-1] == player){
					blank--;
					score+=10;
				}
				if (board[x+1][y] != player){
					blank++;
					score-=10;}
				else if (board[x+1][y] == player){
					blank--;
					score+=10;
				}
				else{
					continue;}
				}
        	else if ((x > 0 && x < 6) && (y > 0 && y < 6)){
				if (board[x][y+1] != player){
					blank++;
					score-=10;}
				else if (board[x][y+1] == player){
					blank--;
					score+=10;
				}
				if (board[x][y-1] != player){
					blank++;
					score-=10;}
				else if (board[x][y-1] == player){
					blank--;
					score+=10;
				}
				if (board[x+1][y] != player){
					blank++;
					score-=10;}
				else if (board[x+1][y] == player){
					blank--;
					score+=10;
				}
				if (board[x-1][y] != player){
					blank++;
					score-=10;}
				else if (board[x-1][y] == player){
					blank--;
					score+=10;
				}
					
				else{
					continue;}
				} 
            if (board[x][y] == ' ') { 
                board[x][y] = HUMANMOVE; 
                showBoard(board);
				turn ++; 
                moveIndex++; 
                if (gameOver(board)) { 
                    declareWinner(HUMAN); 
                    return; 
                } 
                whoseTurn = COMPUTER; 
            } 
            else { 
                printf("Cell %d is already occupied. Try "
                       "again.\n", move); 
            }
			
    }} 
  
    // If the game has drawn 
    if (!gameOver(board) && moveIndex == SIDE * SIDE) 
        printf("It's a draw\n"); 
    else { 
        // Toggling the user to declare the actual winner 
        if (whoseTurn == COMPUTER) 
            whoseTurn = HUMAN; 
        else if (whoseTurn == HUMAN) 
            whoseTurn = COMPUTER; 
  
        // Declare the winner 
        declareWinner(whoseTurn); 
    } 
} 
  
// Driver program 
int main() 
{ 
    playTicTacToe(HUMAN); 
  
    return 0; }
