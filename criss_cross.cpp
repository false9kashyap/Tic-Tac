#include<iostream>
using namespace std;

int current_player;
char current_marker;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void drawboard() {
    cout << "\n";
    for(int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
        if(i < 2) cout << "---|---|---\n";
    }
}

bool place(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return true;
    }
    return false;
}

int winner() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return current_player;
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return current_player;
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return current_player;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return current_player;

    return 0;
}

void swap_player_and_marker() {
    if (current_marker == 'X') {
        current_marker = 'O';
    } else {
        current_marker = 'X';
    }

    if (current_player == 1) {
        current_player = 2;
    } else {
        current_player = 1;
    }
}

void game() {
    cout << "Player 1, choose your symbol (X or O): ";
    char marker1;
    cin >> marker1;

    while (marker1 != 'X' && marker1 != 'O') {
        cout << "Invalid choice. Please enter X or O: ";
        cin >> marker1;
    }

    char marker2 = (marker1 == 'X') ? 'O' : 'X';
    current_player = 1;
    current_marker = marker1;

    drawboard();

    for (int i = 0; i < 9; i++) {
        cout << "Player " << current_player << "'s turn. Enter position (1-9): ";
        int position;
        cin >> position;

        if (position < 1 || position > 9) {
            cout << "Invalid input. Try again.\n";
            i--;
            continue;
        }

        if (!place(position)) {
            cout << "Position already occupied. Try again.\n";
            i--;
            continue;
        }

        drawboard();

        int player_won = winner();

        if (player_won == 1 || player_won == 2) {
            cout << "Player " << player_won << " wins!\n";
            return;
        }

        swap_player_and_marker();
    }

    cout << "It's a tie!\n";
}

int main() {
    game();
    return 0;
}