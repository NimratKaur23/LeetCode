class Solution {
public:
    void sortColors(vector<int>& nums) {
       int zeros=0;
       int ones=0;
       int twos=0;
       
       for(int i=0;i<nums.size();i++) {
        if(nums[i]==0) {
            zeros++;
        }
        else if(nums[i]==1) {
            ones++;
        }
        else {
            twos++;
        }
       }

       int j=0;
       while(zeros) {
        nums[j]=0;
        zeros--;
        j++;
       }

       while(ones) {
        nums[j]=1;
        ones--;
        j++;
       }

       while(twos) {
        nums[j]=2;
        twos--;
        j++;
       }



    }
};