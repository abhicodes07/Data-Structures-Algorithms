#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <utility>
using namespace std;

// comparater
bool comp(pair<int, int> p1, pair<int, int> p2) {
  if (p1.second < p2.second)
    return true;
  if (p1.second > p2.second)
    return false;
  // if same
  if (p1.first > p2.first)
    return true;
  return false;
}

void explainExtras() {
  // sort using sort function
  sort(a,
       a + n); // for linear data where a is start and a + n is end (exclusive)
  sort(v.begin(), v.end()); // for vectors

  // sort certain portion of the liner data structures like vectors and arrays
  sort(a + 2, a + 5);

  // sort in descending order
  sort(a, a + n, greater<int>);

  pair<int, int> a[] = {{1, 2}, {2, 3}, {4, 5}};
  // sort it according to second element
  // if second element is same, then sort
  // it according to first element but in descending
  // see comp function

  sort(a, a + n, comp);

  int num = 7;
  int cnt = __builtin_popcount(num)
      n; // how mnany set bits are their, here 3 bits as 7 is 111 in binagry

  // permutation
  string s = "123";

  do {
    // prints all the permutation of the string
    cout << s << endl;
  } while (next_permutation(s.begin(), s.end()));

  int maxi = *max_element(a, a + n);
}
