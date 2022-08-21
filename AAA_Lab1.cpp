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
    //void printPuzzle();

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

int main() {
    cin <<
    vector<int> initial;
    initial.push_back(1);
    initial.push_back(2);
    initial.push_back(3);
    initial.push_back(4);
    initial.push_back(0);
    initial.push_back(5);
    initial.push_back(6);
    initial.push_back(7);
    initial.push_back(8);
    vector<int> goalState = { 1, 2, 3, 4, 5, 6, 7, 8, 0 };
    Node init = Node(initial, NULL);
    queue<Node*> openList;
    queue<Node*> closedList;
    openList.push(&init);
    bool goalFound = false;
    int count = 0;
    vector<Node*> solution;
    cout << "Searching for solution..." << endl;
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
                cout << "Goal Found." << endl;
                //traceSolution(solution, currentChild);
                goalFound = true;

            }
            if (!contains(openList, currentChild)&& !contains(closedList, currentChild)) {
                openList.push(currentChild);
            }

        }
        count++;
    }
  cout << "No. of nodes in closed list: " << count << endl;
}


