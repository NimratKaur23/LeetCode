class Solution {
public:
    string removeDuplicates(string s) {
        string str;
        stack<char> st;
        st.push(s[0]);

        for(int i=1;i<s.length();i++) {
            if((!st.empty()) && (st.top()==s[i])) {
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        }

        while(!st.empty()) {
            str.push_back(st.top());
            st.pop();
        }

        reverse(str.begin(),str.end());

        return str;


    }
};