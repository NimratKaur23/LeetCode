class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {


       /* 
        vector<vector<int>> ans;

        for(int i=0;i<intervals.size();i=i+2) {
            for(int j=i+1;j<intervals.size();j++) {
                if(intervals[i][1]==intervals[j][0] || intervals[i][1]-1==intervals[j][0]) {
                    vector<int> temp;
                    temp.push_back(intervals[i][0]);
                    temp.push_back(intervals[j][1]);
                    ans.push_back(temp);
                }
                else if (intervals[i][0]==intervals[j][1]) {
                    vector<int> temp;
                    temp.push_back(intervals[j][0]);
                    temp.push_back(intervals[i][1]);
                    ans.push_back(temp);
                }
                else {
                   ans.push_back(intervals[i]);
                   ans.push_back(intervals[j]);
                }
            }
        }

        return ans;
        */

        sort(intervals.begin(),intervals.end());

        vector<vector<int>> ans;
        vector<int> prev=intervals[0];

        for(int i=1;i<intervals.size();i++) {
            if(intervals[i][0]<=prev[1]) {
                prev[1]=max(prev[1],intervals[i][1]);
            }
            else {
                ans.push_back(prev);
                prev=intervals[i];
            }
        }

        ans.push_back(prev);
        return ans;




    }

};