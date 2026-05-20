class Solution {
    void reverse(vector<int>&nums, int start) {
        int i=start;
        int j=nums.size()-1;

        while(i<j) {
            swap(nums,i,j);
            i++;
            j--;
        }
    }


    void swap(vector<int>& nums,int i,int j) {
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
public:
    void nextPermutation(vector<int>& nums) {

        int index1=-1;
        int index2=-1;

        //finding breaking point
        for(int i=nums.size()-2;i>=0;i--) {
            if(nums[i]<nums[i+1]) {
                index1=i;
                break;
            }
        }
     
     //there is no breaking point
        if(index1==-1) {
            reverse(nums,0);
        }
        else {
            //find next greate elem 
            for(int i=nums.size()-1;i>=0;i--) {
                if(nums[i]>nums[index1]) {
                    index2=i;
                    break;
                }
            }

            swap(nums,index1,index2);
            //reversing the right half
            reverse(nums,index1+1);
        }
        
    }
};