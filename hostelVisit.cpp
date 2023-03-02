#include<bits/stdc++.h>
using namespace std;

int main(){
  int q, k;
  cin>>q>>k;
  priority_queue<int> pq;

  while(q--){
    int type;
    cin>>type;
    if(type == 1){
      
      int x, y;
      cin>>x>>y;
      int temp = pow(x, 2)+pow(y, 2);

      if(pq.empty() || pq.size() < k){

        pq.push(temp);
      }else if(pq.top() > temp){

        pq.pop();
        pq.push(temp);
      }
    }else{

      cout<<pq.top()<<endl;
    }
  }
}