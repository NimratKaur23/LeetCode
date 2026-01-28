class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int k=0;
        int t=0;
        int m=nums1.size();
        int n=nums2.size();

        vector<int> temp;
    


        while(k<m && t<n) {
            if(nums1[k]<nums2[t]) {
                    temp.push_back(nums1[k]);
                    k++;
            }
            else {
                    temp.push_back(nums2[t]);
                    t++;
            }
        }

        while(k<m) {
            temp.push_back(nums1[k]);
            k++;
        }

        while(t<n) {
            temp.push_back(nums2[t]);
            t++;
        }

        int l=temp.size() ;
        if (l % 2 != 0) {
            return temp[l / 2];
        } else {
            return (temp[l / 2 - 1] + temp[l / 2]) / 2.0;
        }
    }
};