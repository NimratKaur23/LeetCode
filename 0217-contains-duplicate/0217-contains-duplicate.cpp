class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> m;
        for(auto i:nums) {
            m[i]++;
        }

        for(auto ele:m) {
            if(ele.second>1) {
                return true;
            }
        }

        return false;
    }
};