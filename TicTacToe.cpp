#include<iostream>
using namespace std;

char space[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
int row, column;
char token = 'x';
string player1, player2;

void drawBoard() {
    cout<<"      |      |      "<<endl;
    cout<<"  "<<space[0][0]<<"   |   "<<space[0][1]<<"  |  "<<space[0][2] << endl;
    cout<<"______|______|______"<<endl;
    cout<<"      |      |      "<<endl;
    cout<<"  "<<space[1][0]<<"   |   "<<space[1][1]<<"  |  "<<space[1][2] << endl;
    cout<<"______|______|______"<<endl;
    cout<<"      |      |      "<<endl;
    cout<<"  "<<space[2][0]<<"   |   "<<space[2][1]<<"  |  "<<space[2][2] << endl;
    cout<<"      |      |      "<<endl;
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if ((space[i][0] == space[i][1] && space[i][1] == space[i][2]) ||
            (space[0][i] == space[1][i] && space[1][i] == space[2][i])) {
            return true;
        }
    }

    if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) ||
        (space[0][2] == space[1][1] && space[1][1] == space[2][0])) {
        return true;
    }

    return false;
}

bool isBoardFull() {
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (space[i][j] != 'x' && space[i][j] != '0') {
                return false;
            }
        }
    }
    return true;
}

void takeInput() {
    int digit;
    if(token == 'x'){
        cout << player1 << ", please enter (1-9): ";
    } else {
        cout << player2 << ", please enter (1-9): ";
    }

    cin >> digit;

    if(digit < 1 || digit > 9){
        cout << "Invalid input! Try again." << endl;
        takeInput();
        return;
    }

    row = (digit - 1) / 3;
    column = (digit - 1) % 3;

    if(space[row][column] != 'x' && space[row][column] != '0'){
        space[row][column] = token;
    } else {
        cout << "Space already taken! Try again." << endl;
        takeInput();
        return;
    }

    drawBoard();
}

int main() {
    cout << "Enter the name of the first player: ";
    getline(cin, player1);

    cout << "Enter the name of the second player: ";
    getline(cin, player2);

    cout << player1 << " is Player 1 and will play first (x)" << endl;
    cout << player2 << " is Player 2 and will play second (0)" << endl;

    drawBoard();

    while (true) {
        takeInput();

        if (checkWin()) {
            if (token == 'x') {
                cout << player1 << " wins!" << endl;
            } else {
                cout << player2 << " wins!" << endl;
            }
            break;
        }

        if (isBoardFull()) {
            cout << "It's a draw!" << endl;
            break;
        }

        // 换人
        if(token == 'x'){
            token = '0';
        } else {
            token = 'x';
        }
    }

    return 0;
}