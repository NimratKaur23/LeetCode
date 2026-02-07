class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        //int ans;

        while(s<=e) {
            if(nums[mid]==target) {
                return mid;
            }

/*
            if(s==e && nums[s]<target) { 
                
               
                return mid+1;
                
            }
            
            if(s==e && nums[s]>target) {
                if(s==0 || s==nums.size()-1) {
                    return mid;
                }
                
                else {
                return mid-1;
                }
            }
*/

            if(target<nums[mid]) {
                e=mid-1;
            }
            else {
                s=mid+1;
            }

            mid=s+(e-s)/2;

        }

        return mid;
    }
};