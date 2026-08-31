class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
          return 0;

        int unique=1;
        int officer=0;
        for(int i=1;i<nums.size();i++) {
            if(nums[i]!=nums[i-1]) {
                nums[officer+1]=nums[i];
                unique++;
                officer++;
            }
        }

        return unique;
    }
};