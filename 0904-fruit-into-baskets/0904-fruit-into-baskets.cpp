#include<map>
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low=0;
        int high=0;
        int ans=INT_MIN;
        map<int,int> m;

        while(high<fruits.size()) {
            m[fruits[high]]++;
            while(m.size()>2) {
                m[fruits[low]]--;
                if(m[fruits[low]]==0)
                  m.erase(fruits[low]);
                low++;
            }

            // if(m.size()<=2) {
            //     int len=high-low+1;
            //     ans=max(ans,len);
            // }

            int len=high-low+1;
            ans=max(ans,len);

            high++;
        }

        return ans;
    }
};