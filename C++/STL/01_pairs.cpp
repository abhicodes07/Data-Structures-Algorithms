#include <bits/stdc++.h>
#include <utility> // library that stores pairs

using namespace std;

// Pairs is a part of uitility library
void explainPairs() {
  // pairs are used for storing couple of integers single variable
  pair<int, int> pair1 = {1, 3};

  // access pairs values
  cout << pair1.first << " " << pair1.second;

  // nested pairs
  pair<int, pair<int, int>> pair2 = {1, {2, 3}};

  // acccessing nested pairs values
  cout << pair2.first << pair2.second.second << " " << pair2.second.first;

  // declare a pair array
  pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};

  // accessing pairs in array
  cout << arr[1].second;
}
