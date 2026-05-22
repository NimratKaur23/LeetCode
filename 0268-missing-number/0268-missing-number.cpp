class Solution {
public:
    int missingNumber(vector<int>& nums) {

/*----USING SUM PROPERTY-----
       int n=nums.size();

       int sum=(n*(n+1))/2;
       int elesum=0;

       for(int i=0;i<n;i++) {
        elesum+=nums[i];
       }

       int ans=sum-elesum;

       return ans;
       */


       //USING XOR

       int n=nums.size();
       int ans=0;

       for(int i=0;i<=n;i++) {
        ans=ans^i;
       }

       for(int i=0;i<n;i++) {
        ans=ans^nums[i];
       }

       return ans;
        
    }
};