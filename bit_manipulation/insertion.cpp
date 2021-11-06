#include<bits/stdc++.h>
using namespace std;

int update_bits(int n, int m, int i, int j){
  int all_one = ~0;
  int left = all_one<<(j+1);

  int right = ((1<<i)-1);
  int mask = left|right;

  int n_cleared = n&mask;
  int m_shifted = m<<i;

  return n_cleared|m_shifted;
}

int main(){
  int n,m;
  int i,j;
  cin>>n>>m>>i>>j;
  cout<< update_bits(n,m,i,j);

}
