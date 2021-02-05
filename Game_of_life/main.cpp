//
//  main.cpp
//  Game of life Assignment P6.10
//  Rules:
//  1. A new cell is born on an empty square is it surrounded by exactly three occupied neighbors cells.
//  2. A cell dies of overcrowding if it is surrounded by four or more neighbors.
//  3. A cell dies of loneliness if it is surrounded by zero or one neighbor.
//  4. 8 neigbors: TOP: left, center, right, CENTER: left, right, BOTTOM: left, center, right
//  5  [i - 1][j - 1], [i - 1][j], [i - 1][j + 1],
//       [i][j -1],   Self[i][j],     [i][j + 1],
//     [i + 1][j - 1], [i + 1][j], [i + 1][j + 1]
//  6. 0 = dead , 1 = alive
//
//  Created by Rosita Emakpo on 11/8/20.
//


#include <ctime>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

const int ROWS = 18;
const int COLUMNS = 22;

void duplicate_board(int game_board1[ROWS + 2][COLUMNS + 2], int game_board2[ROWS + 2][COLUMNS + 2]);
void gen1_board(int gen0_board[ROWS + 2][COLUMNS + 2]);
void show_board(int gen_board[ROWS + 2][COLUMNS + 2]);

int main(){
    srand(time(NULL));
    int game_of_life[ROWS + 2][COLUMNS + 2];

    // Initialize game board with random 1 and 0
    for (int i = 0; i < ROWS + 2; i++){
        for(int j = 0; j < COLUMNS + 2; j++){
            game_of_life[i][j] = rand() % 2;
            //cout << setw(2) << game_of_life[i][j]; testing to see if it works
        }
        //cout << endl;
    }
    
    int generation_count = 0;
    int user_count;
    cout << "How many generations would you like to see? (enter an int):  ";
    cin >> user_count;
    
    for(int k = 0; k < user_count; k++){
        cout << "\nGeneration:  " << generation_count << "\n";
        show_board(game_of_life);
        gen1_board(game_of_life);
        generation_count++;
        cout << "\n";
    }
    return 0;
}





// Copy the board
void duplicate_board(int game_board1[ROWS + 2][COLUMNS + 2], int game_board2[ROWS + 2][COLUMNS + 2]){
    for(int i = 0; i < ROWS + 2; i++){
        for (int j = 0; j < COLUMNS; j++){
            game_board2[i][j] = game_board1[i][j];
        }
    }
}





// Next generation - use the rules to decide who lives and who dies
void gen1_board(int gen0_board[ROWS + 2][COLUMNS + 2]){
    int next_gen[ROWS + 2][COLUMNS + 2];
    
    // This variable will be used to total surrouding cells or game rule 1, 2, or 3.
    int surrounding_cells;
    
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS; j++){
            // If done searching
            if(i == 0 || j == 0 || i == ROWS + 2 || j == COLUMNS + 2){
                next_gen[i][j] = 0;
            }else{
                // Examing surrounding cells, see rule 5.
                surrounding_cells =
                gen0_board[i - 1][j - 1] + gen0_board[i - 1][j] + gen0_board[i - j][j + 1] +
                gen0_board[i][j - 2] + gen0_board[i][j + 1] +
                gen0_board[i + 1][j - 1] + gen0_board[i + 1][j] + gen0_board[i + 1][j + 1];
                
                
                // See rule 2 & 3, cell dies of loneliness /over crowding.
                if(gen0_board[i][j] == 1){
                    if(surrounding_cells < 2 || surrounding_cells > 3){
                        next_gen[i][j] = 0; // Death
                    }
                }else{ // Rule 1, life happens with exactly 3 cells
                    if(surrounding_cells == 3){
                        next_gen[i][j] = 1; // Life
                    }
                }
            }
        }
    }
    duplicate_board(next_gen, gen0_board);
}



void show_board(int gen_board[ROWS + 2][COLUMNS + 2]){
    for(int i = 0; i < ROWS + 1; i++){
        for(int j = 0; j < COLUMNS + 1; j++){
            if(gen_board[i][j] == 1){
                cout << setw(2) << " 1 "; // 1 = alive
            }else{
                cout << setw(2) << " 0 "; // 0 = dead
            }
            
        }
        cout << endl;
    }
}




