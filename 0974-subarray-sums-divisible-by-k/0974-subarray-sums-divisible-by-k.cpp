class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0;
        int res=0;
        unordered_map<int,int> m;
        m[0]=1; //empty subarray

        for(int i=0;i<nums.size();i++) {
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0)
              rem=rem+k;
            
            int freq=m[rem];
            res+=freq;
            m[rem]++;
             

        }

        return res;

    }
};