class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low=0;
        int high=0;
        int ans=0;
       // int count=0;
        map<char,int> m;

        if(s.length()==1)
          return 1;

        while(high<s.length()) {
            m[s[high]]++;

            while(m[s[high]]>1) {
                // int len=high-low;
                // ans=max(ans,len);
                m[s[low]]--;
                if(s[low]==0)
                 m.erase(s[low]);
                low++;
            }

            int len=high-low+1;
            ans=max(ans,len);
            high++;
        }

        return ans;
    }
};