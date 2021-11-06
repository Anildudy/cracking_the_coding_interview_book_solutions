#include<bits/stdc++.h>
using namespace std;

int priority_value(char c){
    if(c=='+' || c=='-')
        return 1;
    else
        return 2;
}

vector<string> postfix(string s){
    stack<char>stk;
    vector<string>v;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='*' || s[i]=='/' || s[i]=='+' || s[i]=='-'){
            while(!stk.empty() && priority_value(stk.top())>=priority_value(s[i])){
                string st(1,stk.top());
                v.push_back(st);
                stk.pop();
            }
            stk.push(s[i]);
        }
        else{
            string st;
            while(i<s.length() && isdigit(s[i])){
                st += s[i];
                i++;
            }
            v.push_back(st);
            i--;
        }
    }
    while(!stk.empty()){
        string st(1,stk.top());
        v.push_back(st);
        stk.pop();
    }
    return v;
}

double solve_postfix(vector<string>& v){
    stack<double> st;
    for(int i=0; i<v.size(); i++){
        if(v[i].size()>1 || isdigit(v[i][0])){
            st.push(stoi(v[i]));
        }
        else{
            double n1 = st.top();
            st.pop();
            double n2 = st.top();
            st.pop();
            //cout<<n1<<" "<<n2<<"\n";
            switch(v[i][0]){
                case '+': st.push(n1+n2);
                break;
                case '-': st.push(n2-n1);
                break;
                case '*': st.push(n1*n2);
                break;
                case '/': st.push(n2/n1);
                break;
            }
        }
    }
    return st.top();
}

double solve(string s){
    vector<string>v = postfix(s);
    double val = solve_postfix(v);

    return val;
}

int main(){
    string s;
    cin>>s;
    cout<<solve(s)<<"\n";

    return 0;
}