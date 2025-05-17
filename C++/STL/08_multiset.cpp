#include <bits/stdc++.h>
#include <set>
using namespace std;

void explainMultiset() {
  // everything same as set
  // however it can store duplicate values in sorted manner

  multiset<int> m;
  m.insert(3);
  m.insert(1);
  m.insert(1);
  m.insert(1);

  int cnt = m.count(1);

  m.erase(1); // erases all occurence of 1

  // erase only single occurence of an element
  m.erase(m.find(1));

  m.erase(m.find(1), m.find(2));

  // rest functions same as set
}
