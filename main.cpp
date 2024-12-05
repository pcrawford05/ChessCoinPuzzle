#include <iostream>
using namespace std;
struct Location {
    int r;
    int c;
    Location(){
        r = -1;
        c = -1;
    }
};
//Prints board using H's and T's by converting from 1's and 0's
void printBoard(int** board, int size, Location key);
//Initializes board with random values between 0 and 1
void initBoard(int*** boardPtr, int size);
//Flips one of the values
void flipCoin(int*** boardPtr, Location flip);
//H is 1, T is 0
int main(){
    bool done = false;
    while(!done){
        int size;
        Location key, flip, guess;
        cout << "How big of \"chessboard\" would you like to play on? (n X n): ";
        cin >> size;
        cout << endl;
        int **board;
        initBoard(&board, size);
        cout << "For Player 1's eyes only (lowercase is where the key is):" << endl;
        key.r = rand() % (size);
        key.c = rand() % (size);
        printBoard(board, size, key);
        cout << "Where do you want to flip? (enter two numbers, row and column where top left is 1 1): ";
        cin >> flip.r >> flip.c;
        flip.r--;
        flip.c--;
        flipCoin(&board, flip);
        for(int i = 0; i < 100; i++){
            cout << endl;
        }
        Location notKey;
        printBoard(board, size, notKey);
        cout << "You better not have talked to Player 1. Where is the key? (enter two numbers, row and column where top left is 1 1): ";
        cin >> guess.r >> guess.c;
        guess.r--;
        guess.c--;
        if(key.r == guess.r && key.c == guess.c)
            cout << "Well done! You win!" << endl;
        else
            cout << "Oh no! You were wrong. The key was in row " << ++key.r << " and column " << ++key.c << "." << endl;
        cout << "Play again? (y for yes, anything else for no): ";
        char answer;
        cin >> answer;
        if (answer != 'y')
            done = true;
    
    }
    return 0;

}

void printBoard(int** board, int size, Location key){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(board[i][j] == 1){
                if(key.r == i && key.c == j) //Checks if it's in the key spot
                    cout << "h ";
                else
                    cout << "H ";
            } else {
                if(key.r == i && key.c == j) // ^^
                    cout << "t ";
                else 
                    cout << "T ";
            }
        }
        cout << endl;
    }
}

void initBoard(int*** boardPtr, int size){
    *boardPtr = new int*[size];
    for(int i = 0; i < size; i++){
        (*boardPtr)[i] = new int[size];
    }
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            (*boardPtr)[i][j] = rand() % 2;
        }
    }
}

void flipCoin(int*** boardPtr, Location flip){
    (*boardPtr)[flip.r][flip.c] = ((*boardPtr)[flip.r][flip.c] + 1) % 2;
}