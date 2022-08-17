#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string grid[3][3];
    string inputGrid;
    string inputString;
    cin >> inputGrid >> inputString;
    string outputString;
    string outputGrid;

    int blank = inputGrid.find("#");

    //string moves[4] = {"UP", "DOWN", "LEFT", "RIGHT"};

    int counter =0;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            grid[i][j] = inputGrid[counter];
            counter++;
        }
    }

    if(inputString=="UP" && blank>2){
        string temp1;
        if(blank>5){
            temp1 = grid[1][blank-6];
            grid[2][blank-6] = temp1;
            grid[1][blank-6] = "#";
        }else{
            temp1 = grid[0][blank-3];
            grid[1][blank-3] = temp1;
            grid[0][blank-3] = "#";
        }
    }else if(inputString=="DOWN" && blank<5){
        string temp1;
        if(blank<2){
            temp1 = grid[1][blank];
            grid[0][blank] = temp1;
            grid[1][blank] = "#";
        }else{
            temp1 = grid[2][blank-3];
            grid[1][blank-3] = temp1;
            grid[2][blank-3] = "#";
        }
    }


    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            outputGrid += grid[i][j];
            if(j!=2){
                outputGrid += " ";
            }
        }
        outputGrid += "\n";
    }

    cout << "1\n" << outputGrid;
    return 0;
}
