class Solution {
public:
int fun(vector<vector<int>>& matrix,int n,int m,int mid) {
    int row=n-1;
    int col=0;
    int ans=0;

    while(row>=0 && col<m) {
        if(matrix[row][col]<=mid) {
            ans=ans+row+1;
            col++;
        }
        else {
            row--;
        }

    }

    return ans;
}
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();

        int s=matrix[0][0];
        int e=matrix[n-1][m-1];
        int res=-1;

        while(s<=e) {
            int mid=(s+e)/2;
            int count=fun(matrix,n,m,mid);

            if(count<k) {
                s=mid+1;
            }
            else{
                res=mid;
                e=mid-1;
            }
        }

        return res;
    }
};