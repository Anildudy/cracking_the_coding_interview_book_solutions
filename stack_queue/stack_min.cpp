#include<bits/stdc++.h>
using namespace std;

#define MAX 1000

class node {
public:
  int value;
  int min;
};

class Stack {
  int top;
  int curr_min = INT_MAX;
public:
  node arr[MAX];
  Stack(){
    top = -1;
  }

  bool push(int x){
    if(top>= MAX-1){
      cout<<"Stack Overflow\n";
      return false;
    }
    arr[++top].value = x;
    curr_min = min(curr_min,x);
    arr[top].min = curr_min;
    cout<<"Pushed to arr "<<x<<"and min value is"<< arr[top].min<<"\n";
    return true;
  }

  int pop(){
    if(top<0){
      cout<<"Stack underflow\n";
      return 0;
    }
    return arr[top--].value;
  }

  int peek(){
    if(top<0){
      cout<<"Stack is empty\n";
      return 0;
    }
    return arr[top].value;
  }

  bool is_empty(){
    return top<0;
  }

  int min_value(){
    if(top<0){
      cout<<"no values\n";
      return 0;
    }
    return arr[top].min;
  }

};

int main(){
  class Stack s;
  s.push(1);
  s.push(0);
  s.push(3);
  //cout<<s.pop()<<endl;
  s.push(5);
  // cout<<s.is_empty()<<endl;
  // cout<<s.peek()<<endl;
  s.push(10);
  //cout<<s.pop()<<endl;
  cout<<s.min_value()<<"\n";
}
