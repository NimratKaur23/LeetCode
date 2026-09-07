class Solution {
public:
bool correct(vector<int> &S,vector<int> &T) {
    for(int i=0;i<S.size();i++) {
        if(S[i]<T[i])
          return false;
    }

    return true;
}

    
string minWindow(string s, string t) {
        int low=0;
        int high=0;
        int start=0;
        vector<int> S(256,0);
        vector<int> T(256,0);

        for(int i=0;i<t.length();i++) {
            T[t[i]]++;
        }

        int len=INT_MAX;

        while(high<s.length()) {
            S[s[high]]++;

            while(correct(S,T)) {
                int currlen=high-low+1;

                if(currlen<len) {
                    len=currlen;
                    start=low;
                }

                S[s[low]]--;
                low++;
            }
            high++;
        }

        if(len == INT_MAX)
            return "";

        return s.substr(start,len);
    }
};