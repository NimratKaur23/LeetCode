class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++) {
            m[nums[i]]++;
        }

        for(auto ele:m) {
            if(ele.second>1) {
                return true;
            }
        }

        return false;
    }
};