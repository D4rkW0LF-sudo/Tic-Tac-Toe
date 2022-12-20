#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;


char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char player1 = 'X' , player2 = 'O';
int choice;
bool draw = false;

enum turn{player1_chance =1, player2_chance = 2};
turn t = player1_chance;


void display_board(){

    //Rander Game Board LAYOUT

    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[0][0]<<"  | "<<board[0][1]<<"   |  "<<board[0][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[1][0]<<"  | "<<board[1][1]<<"   |  "<<board[1][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[2][0]<<"  | "<<board[2][1]<<"   |  "<<board[2][2]<<" \n";
    cout<<"\t\t     |     |     \n";
}

void Input(string playerName1, string playerName2){

    if(t == player1_chance){
        cout << playerName1 << " turn :" << endl;
        cout << "Please enter a number from [1-9] : ";
        cin >> choice;
        t = player2_chance;
    }
    else if(t == player2_chance){
        cout << playerName2 << " turn :" << endl;
        cout << "Please enter a number from [1-9] : ";
        cin >> choice;
        t = player1_chance;
    }
}

void ChangeBoard(string playerName1, string playerName2){

    int row, column;

    switch(choice){
        case 1: row=0, column=0;
                break;
        case 2: row=0, column=1;
                break;
        case 3: row=0, column=2;
                break;
        case 4: row=1, column=0;
                break;
        case 5: row=1, column=1;
                break;
        case 6: row=1, column=2;
                break;
        case 7: row=2, column=0;
                break;
        case 8: row=2, column=1;
                break;
        case 9: row=2, column=2;
                break;

        default: cout << "Please enter valid number (1-9) : " << endl;
                 Input(playerName1, playerName2);
    }

    if(t == player1_chance && board[row][column]!= 'X' && board[row][column]!= 'O'){
        board[row][column] = 'O';
    }
    else if(t == player2_chance && board[row][column]!= 'X' && board[row][column]!= 'O'){
        board[row][column] = 'X';
    }
    else{
        cout << endl << "The block is already been taken , enter other box" << endl;
        Input(playerName1, playerName2);
    }
   
}

bool GameState(){
    
    //check horizontally & vetically
    for(int i=0; i<3; i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false;
    }    

    //check diagonally
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0]){
        return false;
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] == 'X' || board[i][j] == 'O'){
                draw = true;
            }
            else{
                draw = false;
                break;
            }
            
        }
    }

    if(draw == true){
        return false;
    }
    else{
        return true;
    }
    
    return true;
}



int main(){

    string playerName1, playerName2;

    cout << "Hi , Lets play Tic-Tac-toe !!" << endl;
    cout << "Player1 name : ";
    cin >> playerName1;
    cout << "Player2 name : ";
    cin >> playerName2;

    cout << "Rules of the game are : ";
    cout << "Player 1 are X, the Player 2 is O ; \nYou have to place 3 X or O horizontally , vertically or diagonally ;\n";
    cout << endl;

    do{

        display_board();
        Input(playerName1, playerName2);
        ChangeBoard(playerName1, playerName2);

    }while(GameState());

    display_board();

    cout << endl << endl << endl;

    if(t == player1_chance && draw == false)//since chance is changed at last of func
        cout << "Congo!!!" << playerName2 << " won!!!";

    else if(t == player2_chance && draw == false)   
        cout << "Congo!!!" << playerName1 << " won!!!";
        
    else if(draw == true){
        cout << " Its a draw !!!" << endl;
    }

    cout << endl;

    return 0;
}