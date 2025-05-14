#include <bits/stdc++.h>
#include <vector>
using namespace std;

void explainVectors() {
  // vectors are dynamic arrays that can increase their size at runtime

  // declare a vector
  vector<int> v;

  // creates an empty container and push the passed value in vector
  v.push_back(1);

  // similar to push_back but faster & efficient
  // it appends the passed value at the end of the vector
  v.emplace_back(2);

  // create a vector using pairs
  vector<pair<int, int>> vec;
  vec.push_back({1, 2});
  // much efficient as it automatically assumes it as pair
  vec.emplace_back(1, 2);

  // vector with size and by default values
  // creates vector of size 5 and all the 5 places filled with 100
  // {100, 100, 100, 100, 100}
  vector<int> vec1(5, 100);

  // declare vector with size but without default values
  vector<int> vec2(5);

  // copy vectors
  vector<int> vec3(5, 20);
  vector<int> vec4(vec3); // stores a copy of vec3

  /* access vector values */
}
