class compare{
    public:
    bool operator()(pair<int, int> a, pair<int, int>  b){
        return a.first > b.first;
    }
}; 
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int, char>, vector<pair<int, char> >, compare > pq;
        int tasksNum = tasks.size();
        unordered_map<char, bool> mp;
        for(int i=0;i<tasksNum;i++){
            if(mp.find(tasks[i]) == mp.end()){
                pq.push(make_pair(-1*n, tasks[i]));
                mp[tasks[i]] = true;
            }
        }

        int tasksExecuted = 0, currSeconds = 1;
        while(tasksExecuted < tasksNum){
            cout<<currSeconds<<" "<<pq.top().second<<" "<<pq.top().first<<endl;
            if(currSeconds - pq.top().first > n){
                char currTask = pq.top().second;
                cout<<currTask<<" "<<currSeconds<<endl;
                pq.pop();
                pq.push(make_pair(currSeconds, currTask));
                tasksExecuted++;
            }
            currSeconds++;
        }
        return currSeconds-1;
    }
};