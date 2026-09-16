class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //insert
        vector<vector<int>> NewRange;
        bool insert=false;
        for(int i=0;i<intervals.size();i++) {
            if((intervals[i][0]>=newInterval[0]) && (insert==false) ) {
                NewRange.push_back({newInterval[0],newInterval[1]});
                insert=true;
            }
            NewRange.push_back({intervals[i][0],intervals[i][1]});
        }


        // If newInterval belongs at the end
        if(insert == false) {
            NewRange.push_back(newInterval);
        }
        

        //NOW MERGE
        int start1=NewRange[0][0];
        int end1=NewRange[0][1];

        vector<vector<int>> ans;

        for(int i=1;i<NewRange.size();i++) {
            int start2=NewRange[i][0];
            int end2=NewRange[i][1];

            if(end1>=start2) {
                //do merge
                start1=start1;
                end1=max(end1,end2);
                continue;
            }

            ans.push_back({start1,end1});
            start1=start2;
            end1=end2;
        }

        ans.push_back({start1,end1});

        return ans;

    }
};