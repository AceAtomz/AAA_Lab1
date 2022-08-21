#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>
#include <Node.h>

using namespace std;

bool contains(std::queue<Node*> q, Node* n) {
  bool exist = false;
  while (!q.empty()) {
    if (q.front()->puzzle == n->puzzle)
      exist = true;
    q.pop();
  }
  return exist;
}
void traceSolution(vector<Node*> sol, Node* g) {
  Node* curr = g;
  sol.push_back(g);
  while (curr->parent != NULL) {
    curr = curr->parent;
    sol.push_back(curr);
  }
  std::reverse(sol.begin(), sol.end());
  cout << "printing solution" << endl;
  for (auto i : sol) {
    i->printPuzzle();
    cout << endl;
  }
}

void printToFile(std::queue<Node*> cl) {
  ofstream Nodes;
  Nodes.open("Nodes.txt");
  cl.pop();
  int nodeCount = 1;
  while (!cl.empty()) {
    int count = 0;
    Nodes << std::endl;
    Nodes << "Node number: " << nodeCount;
    for (auto i : cl.front()->puzzle) {
      if (count % 3 == 0)
        Nodes << std::endl;
      Nodes << i << ' ';
      count++;
    }
    Nodes << std::endl;
    Nodes << "Parent: ";
    for (auto i : cl.front()->parent->puzzle) {
      if (count % 3 == 0)
        Nodes << std::endl;
      Nodes << i << ' ';
      count++;
    }
    cl.pop();
    nodeCount++;
  }
  Nodes.close();
  }


int main() {
  std::vector<int> initial;
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
  std::queue<Node*> openList;
  std::queue<Node*> closedList;
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
        std::cout << "Goal Found." << endl;
        traceSolution(solution, currentChild);
        goalFound = true;

      }
      if (!contains(openList, currentChild)
          && !contains(closedList, currentChild)) {
        openList.push(currentChild);
      }

    }
    count++;
  }
  cout << "No. of nodes in closed list: " << count << endl;
//  printToFile(closedList);  // uncomment this line to print node in text file
}
