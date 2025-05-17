#include <bits/stdc++.h>
#include <set>
using namespace std;

void explainSet() {
  // everything takes log n
  // stores in a sorted manner and stores only unique values
  set<int> s;

  // insert elements
  s.insert(1);  // {1}
  s.emplace(2); // {1, 2}
  s.insert(2);  // {1, 2} only unique

  s.insert(3); // {1, 2, 3}
  s.insert(4); // {1, 2, 3, 4}

  // functionality of insert in vector
  // can be used also, that only increases efficiency

  // begin(), end(), rbegin(), rend(), size(),
  // empty(), and swap() are same as those of vectors

  // {1, 2, 3, 4, 5}
  auto it = s.find(3);  // returns iterator
  auto it2 = s.find(6); // if element is not in set then this returns the
                        // address of one after end element

  // erase element
  // {1, 4, 5}
  s.erase(5); // erase 5: takes (log n) time

  // occurrence of element
  int cnt = s.count(1); // returns 1 if it is there else returns 0

  // erase element using address (iterator)
  auto it3 = s.find(3);
  s.erase(it3);

  // erase subset of elements from set
  // {1, 2, 3, 4, 5}
  auto it4 = s.find(2);
  auto it5 = s.find(5);
  s.erase(it4, it5); // last is exclusive

  // important
  auto it6 = s.lower_bound(2);
  auto it7 = s.lower_bound(3);
}
