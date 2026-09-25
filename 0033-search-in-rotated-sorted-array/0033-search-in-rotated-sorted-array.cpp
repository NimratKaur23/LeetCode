class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int n=nums.size();

        while(s<=e) {
            int mid=(e+s)/2;

            if(nums[mid]==target) {
                return mid;
            }

            //is mid in part1
            if(nums[mid]>nums[n-1]) {
                if(nums[mid]<target) {
                  s=mid+1;
                }
                else{
                    if(nums[0]>target) {
                        //go right
                        s=mid+1;
                    }
                    else {
                        e=mid-1;
                    }
                }
            }
            //part2 mid lie there

            else {
                if(nums[mid]>target) {
                    e=mid-1;
                }
                else {
                    if(nums[n-1]<target)
                      e=mid-1;
                    else
                      s=mid+1;
                }

            }



        }

        return -1;
    }
};