class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        // vector<int> ans;
        // for(int i=0;i<numbers.size();i++) {
        //     for(int j=i+1;j<numbers.size();j++) {
        //         if(numbers[i]+numbers[j]==target) {
        //             ans.push_back(i+1);
        //             ans.push_back(j+1);
        //         }
        //     }
        // }

        // return ans;

        vector<int> ans;
        int s=0;
        int e=numbers.size()-1;

        while(s<e) {
          //  int mid=(s+e)/2;

            // if(numbers[s]+numbers[e]==target) {
            //     ans.push_back(s+1);
            //     ans.push_back(e+1);
            //     break;
            // }
            // else if(numbers[s]+numbers[e]>target) {
            //     e=mid;
            // }
            // else {
            //     s=mid;
            // }

            if(numbers[s]+numbers[e]==target) {
                ans.push_back(s+1);
                ans.push_back(e+1);
                break;
            }
            else if(numbers[s]+numbers[e]>target) {
                e--;
            }
            else {
                s++;
            }
        }

        return ans;
        
    }
};