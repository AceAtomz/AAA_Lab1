#include <iostream>
using namespace std;

int main() {
    string grid[3][3];
    string inputGrid;
    cin >> inputGrid;
    string outputGrid;
    int counter =0;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            grid[i][j] = inputGrid[counter];
            outputGrid += grid[i][j] + " ";
            counter++;
        }
        outputGrid += "\n";
    }
    //outputGrid = grid[0][0] + " " + grid[0][1] + " " + grid[0][2] + "\n" + grid[1][0] + " " + grid[1][1] + " " + grid[1][2] + "\n" + grid[2][0] + " " + grid[2][1] + " " + grid[2][2];
    cout << outputGrid;

    return 0;
}
