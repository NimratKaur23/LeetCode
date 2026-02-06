class Solution {
public:
    bool isPowerOfTwo(int n) {

        /*
        bool ans=false;
        for(int i=0;i<=n;i++) {
            if(n==pow(2,i)) {
                ans=true;
                break;
            }
        }
        return ans;
        */

        int ans = 1;
        for (int i = 0; i <= 30; i++) {
            if (ans == n) {
                return true;
            }
            if (ans < INT_MAX / 2)
                ans = ans * 2;
        }
        return false;
    }
};