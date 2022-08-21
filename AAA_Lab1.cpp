#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

//----------------------------------------------------class begin
class Node{
public:
    vector<Node*> children;
    vector<int> puzzle;
    Node *parent;
    Node(vector<int> _puzzle, Node *_parent) {
        puzzle = _puzzle;
        parent = _parent;
    }

    void printPuzzle(){
        int count = 0;
        for (auto i : puzzle) {
            if (count % 3 == 0){
                cout << std::endl;
            }
            cout << i << ' ';
            count++;
        }
    };

    int findZero(){
        vector<int>::iterator it;
        it = find(puzzle.begin(), puzzle.end(), 0);
        auto z = distance(puzzle.begin(), it);
        return (int) z;
    };

    void moveUp(){
        int zPos = findZero();
        vector<int> temp = puzzle;
        if (zPos != 0 && zPos != 1 && zPos != 2)
            swap(temp[zPos], temp[zPos - 3]);
        Node* child = new Node(temp, this);
        children.push_back(child);
    };

    void moveDown(){
        int zPos = findZero();
        vector<int> temp = puzzle;
        if (zPos != 6 && zPos != 7 && zPos != 8)
            swap(temp[zPos], temp[zPos + 3]);
        Node* child = new Node(temp, this);
        children.push_back(child);
    };

    void moveRight(){
        int zPos = findZero();
        vector<int> temp = puzzle;
        if (zPos != 2 && zPos != 5 && zPos != 8)
            swap(temp[zPos], temp[zPos + 1]);
        Node* child = new Node(temp, this);
        children.push_back(child);
    };

    void moveLeft(){
        int zPos = findZero();
        vector<int> temp = puzzle;
        if (zPos != 0 && zPos != 3 && zPos != 6)
            swap(temp[zPos], temp[zPos - 1]);
        Node* child = new Node(temp, this);
        children.push_back(child);
    };
};

//-----------------------------------------------------class end

bool contains(queue<Node*> q, Node* n) {
    bool exist = false;
    while (!q.empty()) {
        if (q.front()->puzzle == n->puzzle){
            exist = true;
        }
        q.pop();
    }
  return exist;
}

void traceSolution(vector<Node*> sol, Node* g) {
    int moves=0;
  Node* curr = g;
  sol.push_back(g);
  while (curr->parent != NULL) {
    curr = curr->parent;
    sol.push_back(curr);
  }
  std::reverse(sol.begin(), sol.end());
  //cout << "printing solution" << endl;
  for (auto i : sol) {
        moves++;
    //i->printPuzzle();
    //cout << endl;
  }
  cout << moves-1 << endl;
}

int main() {
    string initialGrid;
    string GoalGrid;
    cin >> initialGrid >> GoalGrid;

    vector<int> initial;
    vector<int> goalState;

    for(int i=0;i<9;i++){
        if(initialGrid[i]=='#'){
            initial.push_back(0);
        }else{
            int ia = initialGrid[i] - '0'; //convert char to int
            initial.push_back(ia);
        }
        if(GoalGrid[i]=='#'){
            goalState.push_back(0);
        }else{
            int ia = GoalGrid[i] - '0'; //convert char to int
            goalState.push_back(ia);
        }
    }



    Node init = Node(initial, NULL);
    queue<Node*> openList;
    queue<Node*> closedList;
    openList.push(&init);
    bool goalFound = false;
    int count = 0;
    vector<Node*> solution;
    //cout << "Searching for solution..." << endl;
    while (!openList.empty() && !goalFound) {
        Node* currentNode = openList.front();
        closedList.push(currentNode);
        openList.pop();
        currentNode->moveUp();
        currentNode->moveDown();
        currentNode->moveRight();
        currentNode->moveLeft();

        for (auto i : currentNode->children) {
            Node* currentChild = i;
            if (currentChild->puzzle == goalState) {
                //cout << "Goal Found." << endl;
                traceSolution(solution, currentChild);
                goalFound = true;

            }
            if (!contains(openList, currentChild)&& !contains(closedList, currentChild)) {
                openList.push(currentChild);
            }

        }
        count++;
    }
  //cout << "No. of nodes in closed list: " << count << endl;
}


