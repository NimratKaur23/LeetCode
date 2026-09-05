class Solution {
public:
int find(int arr[]) {
    //int n=arr.size();
    int maxi=INT_MIN;
    for(int i=0;i<256;i++) {
        maxi=max(maxi,arr[i]);
    }

    return maxi;
}


    int characterReplacement(string s, int k) {
        int low=0;
        int high=0;
       // map<char,int> m;
        int arr[256]={0};
        int ans=INT_MIN;

        while(high<s.length()) {
            arr[s[high]]++;
            int len=high-low+1;
            int maxcnt=find(arr);
            int diff=len-maxcnt;

            while(diff>k) {
                arr[s[low]]--;
                low++;
                maxcnt=find(arr);
                len=high-low+1;
                diff=len-maxcnt;
            }

            //diff<k || diff==k
            len=high-low+1;
            ans=max(ans,len);
            high++;             
        }

        return ans;
    }
};