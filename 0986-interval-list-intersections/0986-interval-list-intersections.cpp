class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        int i=0;
        int j=0;
        vector<vector<int>> ans;

        while(i<firstList.size() && j<secondList.size()) {
            int start1=firstList[i][0];
            int end1=firstList[i][1];

            int start2=secondList[j][0];
            int end2=secondList[j][1];

            if(start1<start2) {
                //normal case
                //check overlap
                if(end1>=start2) {
                    int s=max(start1,start2);
                    int e=min(end1,end2);
                    ans.push_back({s,e});
                }
            }
            else {
                //rev case
                //chehck overlap
                if(end2>=start1) {
                    int s=max(start1,start2);
                    int e=min(end1,end2);
                    ans.push_back({s,e});
                }
            }

            if(end1<=end2) 
              i++;
            else
              j++;
        }


        return ans;
    }
};