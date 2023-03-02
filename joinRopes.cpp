#include<bits/stdc++.h>
using namespace std;

int joinRopes(vector<int> ropes){
  int l = ropes.size();
  priority_queue<int, vector<int>, greater<int> > pq(ropes.begin(), ropes.end());

  int cost = 0;
  for(int i = 0;i < l-1;i++){
    int r1 = pq.top();
    pq.pop();
    int r2 = pq.top();
    pq.pop();

    cost+=(r1+r2);

    pq.push(r1+r2);
  }

  return cost;
}

int main(){
  int n;
  cin>>n;
  vector<int> ropes;
  
  for(int i = 0;i < n;i++){
    int temp;
    cin>>temp;
    ropes.push_back(temp);
  }

  cout<<joinRopes(ropes);
}