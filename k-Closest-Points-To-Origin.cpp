class Solution {
public:
    bool compare(vector<int> &a,vector<int> &b){
        return (a[0]*a[0]+a[1]*a[1])<(b[0]*b[0]+b[1]*b[1]);
    }
    int quickSelect(vector<vector<int> > &a,int &l,int &r){
        if(l==r)
            return l;
        int i=l+1;
        for(int j=l+1;j<=r;j++){
            if(compare(a[j],a[l])){
                swap(a[i++],a[j]);
            }
        }
        swap(a[i-1],a[l]);
        return i-1;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int l=0,r=points.size()-1;
        while(l<=r){
            int mid=quickSelect(points,l,r);
           // cout<<l<<" "<<mid<<" "<<r<<endl;
            if(mid==K){
                break;
            }else if(mid<K){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        vector<vector<int> > ans;
        for(int i=0;i<K;i++){
            ans.push_back(points[i]);
        }
        return ans;
    }
};