class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size()==0) {
            return "";
        }
        string ans;

        int i=0;
        while(i<strs[0].size()) {
            for(int j=0;j<strs.size();j++) {
                if(strs[0][i]!=strs[j][i]) {
                    return ans;
                }
            }

            ans=ans+strs[0][i];
            i++;
        }

        return ans;
        
    }
};