class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low=0;
        int high=0;
        int ans=0;
        map<char,int> m;

        while(high<s.length()) {
            m[s[high]]++;
            int k=high-low+1;

            while(m.size()<k) {
                m[s[low]]--;
                if(m[s[low]]==0)
                  m.erase(s[low]);
                low++;
                k=high-low+1;
            }

            //come out if size equal
            //greater size of map is not possible
            int len=high-low+1;
            ans=max(ans,len);
            high++;
        }

        return ans;
    }
};