class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi=INT_MIN;
        int s=0;
        int e=height.size()-1;
        int len=1;
        int breadth=1;

        while(s<e) {
            if(height[s]==height[e]) {
                len=height[s];
                breadth=e-s;
                maxi=max(maxi,len*breadth);
                if(height[s+1]>height[e-1]) {
                    s++;
                }
                else {
                    e--;
                }
            }
            else if(height[s]<height[e]) {
                len=min(height[s],height[e]);
                breadth=e-s;
                maxi=max(maxi,len*breadth);
                s++;
            }
            else {
                len=min(height[s],height[e]);
                breadth=e-s;
                maxi=max(maxi,len*breadth);
                e--;
            }
        }

        return maxi;
    }
};