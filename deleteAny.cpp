#include<bits/stdc++.h>
using namespace std;

void downHeapify(vector<int> &heap, int ind){
  int left = 2*ind+1;
  int right = 2*ind+2;
  int l = heap.size()-1;
  if(left > l && right > l){
    return;
  }

  int minInd = ind;

  if(left <= l && heap[left] < heap[minInd]){
    minInd = left;
  }

  if(right <= l && heap[right] < heap[minInd]){
    minInd = right;
  }

  if(minInd == ind)
  return;

  swap(heap[minInd], heap[ind]);
  downHeapify(heap, minInd);
}

void deleteAny(vector<int> &heap, int ind){
  swap(heap[ind], heap[heap.size()-1]);
  heap.pop_back();

  if(ind < heap.size()){
    downHeapify(heap, ind);
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

  for(int i = n-1;i >= 0;i--){
    downHeapify(heap, i);
  }

  display(heap);
  deleteAny(heap, 5);
  display(heap);
}