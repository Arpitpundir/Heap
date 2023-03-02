#include<bits/stdc++.h>
using namespace std;

void downHeapify(vector<int> &heap, int ind, int size){
  int left = 2*ind+1;
  int right = 2*ind+2;
  int l = size;
  if(left > l && right > l){
    return;
  }

  int minInd = ind;

  if(left <= l && heap[left] > heap[minInd]){
    minInd = left;
  }

  if(right <= l && heap[right] > heap[minInd]){
    minInd = right;
  }

  if(minInd == ind)
  return;

  swap(heap[minInd], heap[ind]);
  downHeapify(heap, minInd, size);
}


void display(vector<int> heap){
  int l = heap.size();
  for(int i = 0;i < l;i++){
    cout<<heap[i]<<" ";
  }
  cout<<endl;
}

void heapSort(vector<int> &heap){
  int l = heap.size()-1;

  for(int i = l;i >= 0;i--){
    downHeapify(heap, i, l);
  }

  for(int i = l;i >= 1;i--){
    swap(heap[0], heap[i]);
    downHeapify(heap, 0, i-1);
  }
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

  display(heap);
  heapSort(heap);
  display(heap);

}