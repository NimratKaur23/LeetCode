class Solution {
public:
bool possibleSol(vector<int>& piles, int h,int mid) {
     long long count=0;

     for(int i=0;i<piles.size();i++) {
        if(piles[i]<=mid)
          count++;
        else {
            if(piles[i]%mid==0)
              count+=piles[i]/mid;
            else
              count+=(piles[i]/mid)+1;
        }
     }

     if(count<=h)
       return true;
    else
      return false;
}

    int minEatingSpeed(vector<int>& piles, int h) {
      int low=1;
      int high=INT_MIN;
      for(int i=0;i<piles.size();i++) {
       // low=min(low,piles[i]);
        high=max(high,piles[i]);
      }


   int ans=0;

      while(low<=high) {
        int mid=(low+high)/2;
        if(possibleSol(piles,h,mid)) {
            ans=mid;
            high=mid-1;
        }
        else {
            low=mid+1;
        }
      }

      return ans;
    }
};