class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
       vector<int> ans(2,-1);
       int s=0;
       int e=nums.size()-1;
      // int mid=s+(e-s)/2;

       //FIRST
        while(s<=e) {
          int  mid=s+(e-s)/2;

        if(nums[mid]<target) {
            s=mid+1;
        }

        else if(nums[mid]>target) {
            e=mid-1;
        }

        else {
            if(mid==s || nums[mid]!=nums[mid-1]) {
                ans[0]=mid;
                break;
            }
            else {
                e=mid-1;
                ans[0]=mid-1;

            }
        }
    }



    //SECOND
    s=0;
    e=nums.size()-1;
    while(s<=e) {
        int mid=s+(e-s)/2;

        if(nums[mid]<target) {
            s=mid+1;
        }

        else if(nums[mid]>target) {
            e=mid-1;
        }
        else {
            if(mid==e || nums[mid]!=nums[mid+1]) {
                ans[1]=mid;
                break;
            }
            else {
                s=mid+1;
                ans[1]=mid+1;
            }
        }
    }


        return ans;
        
    }
};