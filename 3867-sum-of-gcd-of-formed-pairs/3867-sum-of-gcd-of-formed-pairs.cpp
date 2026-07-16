class Solution {
public:
int gcd(int x,int y) {
    while(x!=0) {
        int temp=x;
        x= y%x;
        y=temp;
    }

    return y;
}
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd;
        int n=nums.size();
        int maxi=INT_MIN;

        for(int i=0;i<n;i++) {
            maxi=max(nums[i],maxi);
            int pre= gcd(nums[i],maxi);
            prefixGcd.push_back(pre);
        }

        sort(prefixGcd.begin(),prefixGcd.end());

        int m=prefixGcd.size();
        int s=0;
        int e=m-1;
        long long sum=0;

        while(s<e) {
            sum=sum+gcd(prefixGcd[s],prefixGcd[e]);
            s++;
            e--;
        }

        return sum;
    }
};