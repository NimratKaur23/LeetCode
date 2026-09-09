class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minbest=nums[0];
        int maxbest=nums[0];
        int ans=abs(nums[0]);

        for(int i=1;i<nums.size();i++) {
           int v1=nums[i];
           int v2=maxbest+nums[i];
           int v3=minbest+nums[i];

           maxbest=max(v1,v2);
           minbest=min(v1,v3);

          ans=max(ans,max(abs(maxbest),abs(minbest)));
        }

        return ans;
    }
};