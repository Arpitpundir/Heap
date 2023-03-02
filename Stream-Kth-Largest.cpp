class compare{
    public:
    bool operator()(int a, int b){
        return a > b;
    }
};
class KthLargest {
    int k;
    private:
    priority_queue<int, vector<int> , compare> pq;
public:
/*
* create min priority queue ans store kth largest element in it
* on add if size of element is larger then min element then pop it and push new element
*/
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(this->pq.size() < k){
                this->pq.push(nums[i]);
            }else if(this->pq.top() < nums[i]){
                this->pq.pop();
                this->pq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(this->pq.size() < this->k){
            this->pq.push(val);
        }
        else if(this->pq.top() < val){
                this->pq.pop();
                this->pq.push(val);
        }
        return this->pq.top();
    }
};