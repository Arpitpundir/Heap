#include<bits/stdc++.h>
using namespace std;

void upHeapify(vector<int> &heap, int ind){
  if(ind == 0)
  return;

  int parInd = (ind-1)/2;
  if(heap[parInd] > heap[ind]){
    return;
  }

  int temp = heap[parInd];
  heap[parInd] = heap[ind];
  heap[ind] = temp;
  upHeapify(heap, parInd);
}

void insert(vector<int> &heap, int val){
  heap.push_back(val);
  upHeapify(heap, heap.size()-1);
}

void downHeapify(vector<int> &heap, int ind){
  int leftInd = 2*ind+1;
  int rightInd = 2*ind+2;
  int maxInd = heap.size();

  //when heap have only one element
  if(leftInd > maxInd && rightInd > maxInd){
    return;
  }

  int largest = ind;
  if(leftInd < maxInd && heap[leftInd] > heap[ind]){
    largest = leftInd;
  }

  if(rightInd <maxInd && heap[rightInd] > heap[ind]){
    largest = rightInd;
  }

  if(largest == ind){
    //we are right place
    return;
  }

  swap(heap[largest], heap[ind]);
  downHeapify(heap, largest);
}
void deletePeek(vector<int> &heap){
  int l = heap.size();
  swap(heap[0], heap[l-1]);
  heap.pop_back();
  downHeapify(heap, 0);
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
    insert(heap, temp);
  }
  display(heap);
  deletePeek(heap);
  display(heap);
}