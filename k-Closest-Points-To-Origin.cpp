class Solution {
public:
/*
* create a max heap of size k, where we will store current min k elements, and max element will be at top
* now if for the upcoming element distance is lesser than element at top then we can simply pop the top 
* element and push the new element
*/
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> maxHeap;
        for (auto& p : points) {
            int x = p[0], y = p[1];
            maxHeap.push({x*x + y*y, x, y});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        vector<vector<int>> ans(k);
        for (int i = 0; i < k; ++i) {
            vector<int> top = maxHeap.top();
            maxHeap.pop();
            ans[i] = {top[1], top[2]};
        }
        return ans;
    }
};