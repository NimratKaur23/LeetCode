class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // map<string,string> m;
        // for(int i=0;i<strs.size();i++) {
        //     m[strs[i]]=sort(strs[i].begin(),strs[i].end());
        // }

        unordered_map<string,vector<string>> m;
       vector<string> ans;
       for(auto i:strs) {
        string word=i;
        sort(word.begin(),word.end());
        m[word].push_back(i);
       }

       vector<vector<string>> result;
       for(auto i:m) {
        result.push_back(i.second);
       }

       return result;



  
        
    }
};