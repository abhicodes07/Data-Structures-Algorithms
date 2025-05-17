#include <bits/stdc++.h>
#include <queue>
using namespace std;

void explainPriority() {
  // the element with the largest value stays at the top
  // inside of a priority_queue, a tree data structure is maintained not linear
  // data structure
  // MAX HEAP
  priority_queue<int> pq;

  // insert elements
  pq.push(10);
  pq.push(20);
  pq.push(30);
  pq.emplace(5);

  // get top
  cout << pq.top() << endl;

  // pop elements
  pq.pop(); // 30
  cout << pq.top() << endl;

  // size swap empty same as others

  // MIN HEAP
  // the element with the smallest value stays at the top

  priority_queue<int, vector<int>, greater<int>> p;
  p.push(5);
  p.push(2);
  p.push(10);
  p.push(6);

  cout << p.top() << endl; // 2
}

int main(int argc, char *argv[]) {
  explainPriority();
  return 0;
}
