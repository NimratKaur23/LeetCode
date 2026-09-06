#include<vector>
class Solution {
public:
bool correct(vector<int> &arrS,vector<int> &arrT) {
    for(int i=0;i<256;i++) {
        if(arrS[i]<arrT[i])
          return false;
    }

    return true;
    
}

    string minWindow(string s, string t) {
        int low=0;
        int high=0;
        int start=0;
       

        vector<int> arrS(256,0);
        vector<int> arrT(256,0);
        
        int res=INT_MAX;

        for(int i=0;i<t.length();i++) {
            arrT[t[i]]++;
        }
        

        while(high<s.length()) {
            arrS[s[high]]++;

            while(correct(arrS,arrT)) {
                int len=high-low+1;
                if(res>len) {
                    res=len;
                    start=low;
                }
                arrS[s[low]]--;
                low++;
            }
            high++;
        }

        if(res==INT_MAX)
          return "";

        return s.substr(start,res);
    }
};