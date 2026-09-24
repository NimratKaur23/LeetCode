class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int e=nums.size()-1;
        int s=0;
        int ans=-1;

        while(s<=e) {
            int mid=(e+s)/2;
            if(nums[mid]>nums[n-1]) {
                s=mid+1;
            }
            else {
                ans=nums[mid];
                e=mid-1;
            }
        }

        return ans;
    }
};