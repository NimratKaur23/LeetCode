class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans=0;
        int e=arr.size()-1;
        int s=0;

        while(s<=e) {
            int mid=(e+s)/2;
            if(arr[mid]>arr[mid+1]) {
                ans=mid;
                e=mid-1;
            }
            else {
                s=mid+1;
            }
        }

        return ans;
    }
};