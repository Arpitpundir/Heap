#include<bits/stdc++.h>
using namespace std;

void contMedian(){
  int n;
  cin>>n;
  priority_queue<int, vector<int> > left;//maxHeap
  priority_queue<int, vector<int>, greater<int> > right; //minHeap

  int curr;
  cin>>curr;
  left.push(curr);
  cout<<curr<<" ";
  n--;
  int median = curr;

  while(n--){
    cin>>curr;

    if(left.size() == right.size()){

      if(curr < median){
        left.push(curr);
        median = left.top();
      }else{

        right.push(curr);
        median = right.top();
      }
    }else if(left.size() > right.size()){

      //we have to insert an elment in right tree to balance things
      if(curr < median){

        //so max elemnt of left tree is bigger that curr so curr should be inserted in left, to balance we 
        //will first give top of left to right and then insert curr to left
        int leftTop = left.top();
        left.pop();
        right.push(leftTop);
        left.push(curr);

        median = (left.top()+right.top())/2;
      }else{

        //now we can just insert curr to right tree
        right.push(curr);
        median = (left.top()+right.top())/2;
      }
    }else{
      if(curr < median){

        left.push(curr);
        median = (left.top()+right.top())/2;
      }else{

        int rightTop = right.top();
        right.pop();
        left.push(rightTop);
        right.push(curr);

        median = (left.top()+right.top())/2;
      }
    }

    cout<<median<<" ";
  }
}

int main(){
  contMedian();
}