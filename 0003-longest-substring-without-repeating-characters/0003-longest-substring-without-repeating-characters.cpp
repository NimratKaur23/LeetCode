class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       // vector<int> ans;
        string str="";
        int res=0;
        //int len=0;
        for(int i=0;i<s.size();i++) {
            char ch=s[i];
            if(str.find(ch)==string::npos) {
                str.push_back(ch);
               // len++;
            }
            else {
                res=max(res,(int)str.size());
                int pos=str.find(ch);
                str.erase(0,pos+1);
                str.push_back(ch);
            }
        }

         res = max(res, (int)str.size());

    

        return res;
    }
};