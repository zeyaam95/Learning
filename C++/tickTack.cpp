#include <iostream>
#include <vector>
//efgefews
using namespace std;

bool playerWin(vector< vector<char> > board, char player);
bool playerTie(vector< vector<char> > board);
void boardPrint(vector< vector<char> > board);

int main() {
    char players[2] = {'X','O'};
    int row, col, gameState=0;
    vector< vector<char> > board (3, vector<char>(3,'*'));
    while (gameState!=1) {
        for (int player = 1; player<3; player++) {
            bool turn = false;
            do {
                cout << "Player #" << player << ", please enter the row number and the column number: ";
                cin >> row >> col;
                if (board[row-1][col-1] == '*') {
                    board[row-1][col-1] = players[player-1];
                    turn = true;
                }
                else {
                cout << "That position is already taken!" << endl;
                }
            }
            while (turn == false);
            if (playerWin(board, players[player-1])) {
                cout << "Player #" << player << " wins!" << endl;
                gameState =1;
                break;
            }
            if (playerTie(board)) {
                cout << "The match is a tie!"<<endl;
                gameState = 1;
                break;
            }
            boardPrint(board);
            }
        }
    boardPrint(board);
    return 0;
}

void boardPrint(vector< vector<char> > board){
    cout<<"||||"<<endl;
    for (int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cout<<board[i][j];
        }
        cout<<endl;
    }
    cout<<"||||"<<endl;
}

bool playerWin(vector< vector<char> > board, char player) {
    for(int row=0;row<board[0].size();row++) {
        if (player == board[row][0] && board[row][0] == board[row][1] && board[row][0] == board[row][2]){
            return true;
        }
    }
    for(int col=0;col<board[0].size();col++) {
        if (player == board[0][col] && board[0][col] == board[1][col] && board[0][col] == board[2][col]){
            return true;
        }
    }
    if (player == board[0][0] && board[0][0] == board[1][1] && board[0][0] == board[2][2]){
        return true;
    }
    if (player == board[0][2] && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return true;
    }
    return false;
}

bool playerTie(vector< vector<char> > board) {
    for (int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if (board[i][j]=='*'){
                return false;
            }
        }
    }
    return true;
}
