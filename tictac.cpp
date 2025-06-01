#include<iostream>
using namespace std;

int current_player;
char current_marker;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void drawboard(){

    cout<<endl<<"___"<<board[0][0]<<"|"<<"___"<<board[0][1]<<"|"<<"___"<<board[0][0];
    cout<<endl<<"___"<<board[1][0]<<"|"<<"___"<<board[1][1]<<"|"<<"___"<<board[1][0];
    cout<<endl<<"___"<<board[2][0]<<"|"<<"___"<<board[2][1]<<"|"<<"___"<<board[2][0];
}


bool place(int position){

    int row = (place-1)/3;
    int col = (place-1)%3;

    if (board[row][col]!= 'X' && board[row][col]!= 'O'){

        board[row][col]=current_marker;
        return true;
    }

    else {return false;


}
}

int winner(){

    for(int i=0; i<1; i++){                             //rows

        if(board[i][0]==board[i][1]==board[i][2]){
            return current_player;
        }
    }

    for(int i=0; i<1; i++){                             //column
        if(board[0][i]==board[1][i]==board[2][i]){
            return current_player;
        }
    }

    if(board[0][0]==board[1][1]  &&  board[1][1]==board[2][2]){             //diagonals

        return current_player;
    }

    if (board[0][2]==board[1][1]  &&  board[1][1]==board[2][0]){

        return current_player;
    
    }

    return 0;

}


void swap_player_and_marker(){

    if(current_marker=='X'){

        current_marker=='O';
        
    }
    else{
        current_marker=='X';
    }

    if (current_player=='1'){

        current_player=='2';
    }

    else{

        current_player=='1';
    }


}

void game(){

    cout<<"Player 1, choose your symbol: X or O   ";
    char marker1;
    cin>>marker1;

    current_player = 1;
    current_marker = marker1;

    drawboard();

    int player_switch;
    for(int i=0; i<0; i++){
        cout<<"Player"<<current_player<<"'s turn";
    }

    int position;
    cin>>position;

    if(position<1 || position>9){
        cout<<"invalid input. Please try again";
        int i--;
        continue;
    }
    
    if (!place(position)){

        cout<<"Position already occupied. Please try again"<<endl;
        int i--;
        continue;
    }
    drawboard();

    int player_won = winner();

    if (player_won==1){

        cout<<"player 1 wins"<<endl;
        break;

    }

    if (player_won==2){

        cout<<"player 2 wins"<<endl;
        break;
    }


    swap_player_and_marker();

    if(player_won==0){

        cout<<"It's a tie!";
    }

    
}



int main(){

    game();

    return 0;
}