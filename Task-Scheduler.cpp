class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        int numTasks = tasks.size();
        int ans = 0;
        for(int i=0;i<numTasks;i++){
            mp[tasks[i]]++;
        }

        priority_queue<pair<int, char> > pq;

        for(pair<char, int> cnt: mp){
            pq.push(make_pair(cnt.second, cnt.first));
        }

        while(!pq.empty()){
            vector<pair<int, char> > temp;
            int time = 0;
            for(int i=0;i<n+1;i++){
                if(!pq.empty()){
                    temp.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }



            for(pair<int, char> currTask:temp){
                if(--currTask.first){
                    pq.push(currTask);
                }
            }

            ans += !pq.empty()?n+1:time;
        }
        return ans;
    }
};