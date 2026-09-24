class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int e=nums.size()-1;
        int s=0;
        vector<int> ans(2,-1);

        //first occurecne
        while(s<=e) {
            int mid=(e+s)/2;
            if(nums[mid]<target) {
                s=mid+1;
            }
            else if(nums[mid]>target) {
                e=mid-1;
            }
            else {
                //equal
                ans[0]=mid;
                e=mid-1;
            }
        }

        s=0;
        e=nums.size()-1;
        while(s<=e) {
            int mid=(e+s)/2;
            if(nums[mid]<target) {
                s=mid+1;
            }
            else if(nums[mid]>target) {
                e=mid-1;
            }
            else {
                //equal
                ans[1]=mid;
                s=mid+1;
            }
        }

        return ans;
    }
};