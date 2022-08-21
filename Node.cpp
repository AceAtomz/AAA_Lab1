#include <Node.h>

using namespace std;

void Node::printPuzzle() {
  int count = 0;
  for (auto i : puzzle) {
    if (count % 3 == 0)
      std::cout << std::endl;
    std::cout << i << ' ';
    count++;
  }
  }
int Node::findZero() {
  std::vector<int>::iterator it;
  it = find(puzzle.begin(), puzzle.end(), 0);
  auto z = std::distance(puzzle.begin(), it);
  return (int) z;
}


void Node::moveUp() {
  int zPos = findZero();
  vector<int> temp = puzzle;
  if (zPos != 0 && zPos != 1 && zPos != 2)
    std::swap(temp[zPos], temp[zPos - 3]);
  Node* child = new Node(temp, this);
  children.push_back(child);

}

void Node::moveDown() {
  int zPos = findZero();
  vector<int> temp = puzzle;
  if (zPos != 6 && zPos != 7 && zPos != 8)
    std::swap(temp[zPos], temp[zPos + 3]);
  Node* child = new Node(temp, this);
  children.push_back(child);
}

void Node::moveRight() {
  int zPos = findZero();
  vector<int> temp = puzzle;
  if (zPos != 2 && zPos != 5 && zPos != 8)
    std::swap(temp[zPos], temp[zPos + 1]);
  Node* child = new Node(temp, this);
  children.push_back(child);
}

void Node::moveLeft() {
  int zPos = findZero();
  vector<int> temp = puzzle;
  if (zPos != 0 && zPos != 3 && zPos != 6)
    std::swap(temp[zPos], temp[zPos - 1]);
  Node* child = new Node(temp, this);
  children.push_back(child);
    }
