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
  // iterator
  vector<int>::iterator it =
      v.begin(); // points to the memory of the first element
  it++;          // move to the next memory
  cout << *(it) << " ";

  // shift by two values
  it += 2;
  cout << *(it) << " ";

  // more methods
  vector<int>::iterator it1 = v.end(); // points to the memory location right
                                       // after the last element in the vector

  vector<int>::iterator it = v.rend();   // reverse iteration
  vector<int>::iterator it = v.rbegin(); // reverse iteration

  // more acessibility
  cout << v[0] << " " << v.at(0);

  // returns the last element in the vector
  cout << v.back() << " ";

  // access values
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *(it) << " ";
  }

  // automatically assign data type using atuo keyword
  for (auto it = v.begin(); it != v.end(); it++) {
    cout << *(it) << " ";
  }

  // for each
  for (auto it : v) {
    cout << it << " ";
  }

  /* DELTETION IN VECTORS */

  // {10, 20, 30, 40, 50}
  v.erase(v.begin());     // deletes 10
  v.erase(v.begin() + 1); // deletes 20

  // delete mulitple elments from the vector
  v.erase(v.begin(), v.begin() + 3); // removes: 10, 20, 30 as 3 is exclusive

  /* INSERT FUNCTIONS */
  vector<int> v(2, 100); // {100, 100}

  // insert at beginning
  v.insert(v.begin(), 300);   // {300, 100, 200}
  v.insert(v.begin() + 1, 5); // {300, 5, 100, 100};

  // insert multiple occurences of single element at single position
  v.insert(v.begin() + 1, 2, 20); // {300, 20, 20, 5, 100, 100}

  // insert vectors in vector
  vector<int> copy(2, 58);
  v.insert(v.begin(), copy.begin(), copy.end());

  // size of a vector
  cout << v.size() << endl;

  v.pop_back(); // pops out the last element

  // swap two vectors
  vector<int> v2;
  v2.swap(v);

  // erase entire vector
  v.clear();

  // returns true if empty else returns false
  cout << v.empty();
}
