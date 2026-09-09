class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int Nodelete=arr[0];
        int Onedelete=INT_MIN;
        int ans=arr[0];

        for(int i=1;i<arr.size();i++) {
            int prevNoDel=Nodelete;
            int prevOneDel=Onedelete;

            Nodelete=max(prevNoDel+arr[i],arr[i]);
            int v1=0;
            if(prevOneDel==INT_MIN) 
               v1=arr[i];
            else
               v1=prevOneDel+arr[i];
            
            Onedelete=max(v1,prevNoDel);

            ans=max(ans,max(Nodelete,Onedelete));
        }

        return ans;
    }
};