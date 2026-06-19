class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        int res=0;
        for(int i=0;i<gain.size();i++) {
            res=res+gain[i];
            if(res>0) {
                ans=max(ans,res);
            }

        }

        return ans;
    }
};