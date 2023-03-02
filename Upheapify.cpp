#include<bits/stdc++.h>
using namespace std;

void upHeapify(vector<int> &heap, int ind){

  if(ind == 0){
    // only one node so this is root
    return;
  }

  int parInd = (ind-1)/2;

  if(heap[parInd] > heap[ind]){
    return;
  }

  int temp = heap[parInd];
  heap[parInd] = heap[ind];
  heap[ind] = temp;
  upHeapify(heap, parInd);
}

void display(vector<int> heap){
  int l = heap.size();
  for(int i = 0;i < l;i++){
    cout<<heap[i]<<" ";
  }
  cout<<endl;
}

int main(){
  int n;
  cin>>n;
  vector<int> heap;
  for(int i = 0;i < n;i++){
    int temp;
    cin>>temp;
  heap.push_back(val);
  upHeapify(heap, heap.size()-1);  }
  display(heap);
}