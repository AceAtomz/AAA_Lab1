#include <iostream>
#include <cstring>
using namespace std;

string grid[3][3];

void printGrid(string grid[3][3]){
    string outputGrid;
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
}

void makeMove(string inputString,  int blank){
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
    }else if(inputString=="DOWN" && blank<6){
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
    }else if(inputString=="LEFT" && blank!=0 && blank!=3 && blank!=6){
        string temp1;
        if(blank==1 || blank==4 || blank==7){
            temp1 = grid[(blank-1)/3][0];
            grid[(blank-1)/3][1] = temp1;
            grid[(blank-1)/3][0] = "#";
        }else{
            temp1 = grid[(blank-2)/3][1];
            grid[(blank-2)/3][2] = temp1;
            grid[(blank-2)/3][1] = "#";
        }
    }else if(inputString=="RIGHT" && blank!=2 && blank!=5 && blank!=8){
        string temp1;
        if(blank==1 || blank==4 || blank==7){
            temp1 = grid[(blank-1)/3][2];
            grid[(blank-1)/3][1] = temp1;
            grid[(blank-1)/3][2] = "#";
        }else{
            temp1 = grid[(blank-2)/3][1];
            grid[(blank-2)/3][0] = temp1;
            grid[(blank-2)/3][1] = "#";
        }
    }
}

int main() {
    string inputGrid;
    string inputString;
    cin >> inputGrid >> inputString;
    string outputString;

    int blank = inputGrid.find("#");

    string moves[4] = {"UP", "DOWN", "LEFT", "RIGHT"};

    int counter =0;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            grid[i][j] = inputGrid[counter];
            counter++;
        }
    }

    makeMove(inputString, blank);

    printGrid(grid);
    return 0;
}

