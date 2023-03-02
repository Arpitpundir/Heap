#include<bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int> > cp;

vector<int> mergeKSorted(vector<vector<int> > a){
  vector<int> result;
  priority_queue<cp, vector<cp>, greater<cp> > pq;

  for(int i = 0;i < a.size() ;i++){
    pq.push({a[i][0], {i, 0}});
  }

  while(!pq.empty()){
    cp curr = pq.top();
    pq.pop();

    result.push_back(curr.first);
    int x = curr.second.first;
    int y = curr.second.second;

    if(y+1 < a[x].size()){
      pq.push({a[x][y+1], {x, y+1}});
    }
  }
  return result;
}

int main(){
  int n, m;
  cin>>n;
  cin>>m;

  vector<vector<int> > a(n);
  for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
      int temp;
      cin>>temp;
      a[i].push_back(temp);
    }
  }

  vector<int> res = mergeKSorted(a);

  int l = res.size();
  for(int i = 0;i < l;i++){
    cout<<res[i]<<" ";
  }
}
