#include <bits/stdc++.h>
#include <queue>
using namespace std;

void explainQueue() {
  queue<int> q; // FIFO

  // insert elements
  q.push(10);    // {10}
  q.push(20);    // {10, 20}
  q.push(30);    // {10, 20, 30}
  q.push(40);    // {10, 20, 30, 40}
  q.emplace(50); // {10, 20, 30, 40, 50}

  // get last element
  cout << q.back(); // 50

  // get front element
  cout << q.front(); // 10

  // remove elements in FIFo order
  q.pop(); // removes 10

  // size swap same as size
}
