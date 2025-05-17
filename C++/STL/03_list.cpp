#include <bits/stdc++.h>
#include <list>
using namespace std;

void explainList() {
  // list are same as vectors
  // however they provide front operations too
  list<int> ls;
  ls.push_back(2);    // {2}
  ls.emplace_back(4); // {2, 4}

  ls.push_front(5);       // {5, 2, 4}
  ls.emplace_front(6, 7); // {6, 7, 5, 2, 4}

  // rest funcitons are same as vector
  // begin, end, rbegin, rend, clear, insert, size, swap
}
