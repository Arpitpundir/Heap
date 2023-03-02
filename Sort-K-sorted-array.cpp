#include<bits/stdc++.h>
using namespace std;

vector<int> SortKSortedArray(vector<int> arr, int k){
  int n = arr.size();
  priority_queue<int, vector<int>, greater<int> > minHeap;
  vector<int> resultSortedArray;
  for(int i=0;i<n;i++){
    if(i<=k){
      minHeap.push(arr[i]);
    }else{
      resultSortedArray.push_back(minHeap.top());
      minHeap.pop();
      minHeap.push(arr[i]);
    }
  }
  while(!minHeap.empty()){
    resultSortedArray.push_back(minHeap.top());
    minHeap.pop();
  }
  return resultSortedArray;
}

int main(){
  vector<int> arr = {6,5,3,2,8,10,9};
  int n = 7, k = 3;
  vector<int> sortedArray = SortKSortedArray(arr, k);

  for(int i=0;i<n;i++){
    cout<<sortedArray[i]<<" ";
  }
  return 0;
}