#include<bits/stdc++.h>
using namespace std;

class stackOfStates {
int i = 0;
int th = 5;
int v_size = 5;
vector<stack<int>> v = vector<stack<int>>(v_size);
public:
  // stackOfStates(){
  //   v[i].top();
  // }

  void push(int val){
    if(i<0)
      i++;
    if(v[i].size()>=th){
      i++;
    }
    v[i].push(val);
    cout<<"Pushed value "<<val<<" in stack no "<<i<<"\n";
  }

  void pop(){
    if(v[i].empty() && i>=0)
      i--;
    if(i<0){
      cout<<"Not possible!! Stack is already empty\n";
      return;
    }
    else{
      int a = v[i].top();
      v[i].pop();
      cout<<"popped value "<<a<<" from stack "<<i<<"\n";
    }
  }

  void popAt(int idx){
    if(idx<0 || idx>=v_size || v[idx].empty()){
      cout<<"Not possible!! out of bound\n";
      return;
    }
    int d = v[idx].top();
    v[idx].pop();
    cout<<"Popped value "<<d<<" from stack no "<<idx<<"\n";
  }

};


int main(){
  stackOfStates s;
  int val;
  while(cin>>val){
    if(val == 0)
      break;
    s.push(val);
  }
  s.pop();
  s.pop();
  s.pop();
  s.popAt(0);
  s.pop();
  s.pop();
  s.pop();
  s.pop();
  s.popAt(1);
  while(cin>>val){
    if(val==0)
      break;
    s.push(val);
  }

}
