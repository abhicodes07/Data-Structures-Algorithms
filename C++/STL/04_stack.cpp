#include <bits/stdc++.h>
#include <stack>
using namespace std;

void explainStack() {
  stack<int> st;

  // insert element in stack
  st.push(10); // {10}
  st.push(20); // {10, 20}
  st.push(30); // {10, 20, 30}
  st.push(40); // {10, 20, 30, 40}
  st.push(50); // {10, 20, 30, 40, 50}

  // top
  cout << st.top(); // 50

  // pop element from the stack
  st.pop(); // removes element at top: 50

  // size of stack
  cout << st.size();

  // is empty?
  cout << st.empty();

  // swap stacks
  stack<int> st2;
  st.swap(st2);
}
