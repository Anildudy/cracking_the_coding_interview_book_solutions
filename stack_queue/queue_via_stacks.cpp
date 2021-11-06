#include<bits/stdc++.h>
using namespace std;

class myQueue {
stack<int> ph;
stack<int> pp;
    public:

    void push_back(int val){
        ph.push(val);
    }

    int pop_back(){
            if(!pp.empty()){
                int v = pp.top();
                pp.pop();
                return v;
            }
            if(pp.empty() && ph.empty()){
                cout<<"Queue is empty ";
                return -1;
            }
            else{
                while(!ph.empty()){
                    pp.push(ph.top());
                    ph.pop();
                }
                return pop_back();
            }
    }
};

int main(){
    myQueue obj;
    obj.push_back(1);
    obj.push_back(2);
    obj.push_back(3);
    obj.push_back(4);
    obj.push_back(5);
    cout<<obj.pop_back()<<endl;
    cout<<obj.pop_back()<<endl;
    cout<<obj.pop_back()<<endl;
    cout<<obj.pop_back()<<endl;
    cout<<obj.pop_back()<<endl;
    cout<<obj.pop_back()<<endl;
    obj.push_back(6);
    obj.push_back(7);
    cout<<obj.pop_back()<<"\n";
    cout<<obj.pop_back()<<"\n";

    return 0;
}