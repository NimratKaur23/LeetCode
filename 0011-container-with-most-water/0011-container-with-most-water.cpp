class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n=height.size();
        int i=0;
        int j=n-1;
        int Maxarea=0;

        while(i<j) {
           int currarea= min(height[i],height[j]) * (j-i);
           Maxarea=max(Maxarea,currarea);

        if(height[i]<height[j]) {
            i++;
        }
        else {
            j--;
        }
        }


        return Maxarea;
        
    }
};