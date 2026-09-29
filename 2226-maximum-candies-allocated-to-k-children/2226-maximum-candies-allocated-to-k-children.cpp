class Solution {
public:
bool isPossible(vector<int>& candies,long long mid,long long k) {
    long long count=0;

    for(int i=0;i<candies.size();i++) {
        if(candies[i]>=mid) {
            count+=candies[i]/mid;

            if(count>=k)
              return true;
        }
    }

      return false;

}

    int maximumCandies(vector<int>& candies, long long k) {
        
        // int mini=INT_MAX;
        // for(int i=0;i<candies.size();i++) {
        //     mini=min(mini,candies[i]);
        // }

        long long sum=0;
        for(int i=0;i<candies.size();i++) {
            sum+=candies[i];
        }

        long long s=1;
        long long e=sum;
        long long ans=0;

        if(sum<k) {
            return 0;
        }

        while(s<=e) {
            long long mid=(s+e)/2;
            if(isPossible(candies,mid,k)) {
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }

        return ans;
    }
};