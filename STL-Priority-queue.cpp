#include<queue>
#include<iostream>
using namespace std;
class Compare{
  public: 
  operator()(int a, int b){
    return a < b;
  }
};

int main(){
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int> > minHeap;
  priority_queue<int, vector<int>, Compare> customHeap;
  vector<int> arr = {1,2,3,4,5};

  for(int i=0;i<arr.size();i++){
    maxHeap.push(arr[i]);
  }
  cout<<maxHeap.top()<<endl;
  maxHeap.pop();
  return 0;
}