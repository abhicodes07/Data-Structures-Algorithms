#include <bits/stdc++.h>
#include <map>
#include <utility>
using namespace std;

void explainMap() {
  // map stores data in key:value pair format and sorted manner
  // it stores unique keys in sorted order something similar to sets

  // declaration
  map<int, int> m1; // here key is int and value to be stores is int
  map<int, pair<int, int>>
      m2; // here key is int and values to be stored are pairs

  // storing values
  m1[1] = 2;        // stores 2 with key as 1: {1, 2}
  m1.emplace(3, 1); // stores 1 with key as 3: {3, 1}
  m1.insert({4, 5});

  m2[5] = {7, 8}; // stores {7, 8} with key 5

  // iterate over maps
  for (auto it : m1) {
    cout << it.first << " " << it.second << endl;
  }

  // accessing keys
  cout << m1[0];
  cout << m1[1];

  auto it = m1.find(1);
  cout << it->first;

  auto it2 = m1.find(4);

  // lower and upper bounds
  auto it3 = m1.lower_bound(2);
  auto it4 = m1.lower_bound(3);
}
