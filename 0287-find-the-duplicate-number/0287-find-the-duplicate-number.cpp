class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      /*  
      sort(nums.begin(),nums.end());

      for(int i=0;i<nums.size();i++) {
        if(nums[i]==nums[i+1]) {
            return nums[i];
        }
      }
      
      return -1;
    }*/

    int ans;

    for(int i=0;i<nums.size();i++) {
        if(nums[abs(nums[i])-1]<0) {
            ans=abs(nums[i]);
            break;
        }

        nums[abs(nums[i])-1] =-1* nums[abs(nums[i])-1] ;
    }

    return ans;
    }
};