class Solution {
public:
    int maxNumberOfBalloons(string text) {
      //  int ans=0;
        unordered_map<char,int> count;
        for(int i=0;i<text.size();i++) {
            count[text[i]]++;
        }

     
          int ans=min({count['b'],count['a'],count['l']/2,count['o']/2,count['n']});
    

        return ans;
    }
};