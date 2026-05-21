class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {


/*--------TLE (O^3)----------------------------------------------------------------------
        vector<vector<int>> ans;
        set<vector<int>> s;
        int n=nums.size();

        for(int i=0;i<=nums.size()-3;i++) {
            int start=i+1;
            int end=i+2;
        
        while(start<n-1) {
        end=start+1;

        while(end<nums.size()) {
            if((nums[i]+nums[start]+nums[end])==0) {
                 vector<int> temp = {nums[i], nums[start], nums[end]};
                 sort(temp.begin(), temp.end());
                 s.insert(temp);
            }
            end++;
        }
        start++;
        }

        }

        for(auto x:s) {
            ans.push_back(x);
        }

        return ans;
       ------------------------------------------------------------------ */

       int n=nums.size();
       vector<vector<int>> ans;
       sort(nums.begin(),nums.end());

       for(int i=0;i<n;i++) {

        //to remove dupicates
        if(i>0 && nums[i]==nums[i-1]) continue;

        int s=i+1;
        int e=n-1;

        while(s<e) {

            int sum= nums[i]+nums[s]+nums[e];

            if(sum<0) {
                s++;
            }
            else if(sum>0) {
                e--;
            }
            else {
                ans.push_back({nums[i],nums[s],nums[e]});
                s++;
                e--;

                while(s<e && nums[s]==nums[s-1]) s++;
                while(s<e && nums[e]==nums[e+1]) e--;
            }


        }

       }

return ans;

    
    }
};