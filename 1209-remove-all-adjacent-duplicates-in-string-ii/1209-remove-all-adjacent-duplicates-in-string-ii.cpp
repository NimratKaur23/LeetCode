class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.length();
        stack<pair<char,int>> st;

        for(int i=0;i<n;i++) {
            char c=s[i];

            if(st.empty()) {
                st.push({c,1});
                continue;
            }

            if(st.top().first!=c) {
                st.push({c,1});
                continue;
            }

            //top is matching
            //check k-1 times
            if(st.top().second<k-1){
                pair<char,int> p=st.top();
                st.pop();
                st.push({p.first,p.second+1});
                continue;
            }

            //k-1 satisifed
            st.pop();
        }

        string ans="";
        while(!st.empty()) {
            pair<char,int> p=st.top();
            st.pop();

            while(p.second--) {
                ans.push_back(p.first);
            }
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};