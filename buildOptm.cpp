#include<bits/stdc++.h>
using namespace std;

void downHeapify(vector<int> &heap, int ind){
  int leftChild = 2*ind+1;
  int rightChild = 2*ind+2;

  int l = heap.size()-1;
  if(leftChild > l && rightChild > l){
    return;
  }

  int minInd = ind;

  if(leftChild <= l && heap[leftChild] < heap[minInd]){
    minInd = leftChild;
  }

  if(rightChild <= l && heap[rightChild] < heap[minInd]){
    minInd = rightChild;
  }

  if(minInd != ind){
    swap(heap[minInd], heap[ind]);
    downHeapify(heap, minInd);
  }
  return;
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
    heap.push_back(temp);
  }

  int startInd=n/2-1;
  for(int i = startInd;i >= 0;i--){
    downHeapify(heap, i);
  }
  display(heap);
}