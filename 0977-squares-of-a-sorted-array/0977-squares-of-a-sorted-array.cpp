class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;

        for(int i=0;i<nums.size();i++) {
            if(nums[i]>=0)
               pos.push_back(nums[i]);
            else
              neg.push_back(nums[i]);
        }

        //no negtive ele
        if(neg.size()==0) {
            for(int i=0;i<pos.size();i++) {
                pos[i]=pos[i]*pos[i];
            }
            return pos;
        }

        //no positive ele
        if(pos.size()==0) {
            for(int i=0;i<neg.size();i++) {
                neg[i]=neg[i]*neg[i];
        }

        reverse(neg.begin(),neg.end());
        return neg;
    }


    //both positve and negative exist
    int i=0,j=0;
    int id=0;
    int n=neg.size();
    int m=pos.size();
    vector<int> ans(n+m);

    for(int i=0;i<n;i++) {
        neg[i]=neg[i]*neg[i];
    }
    reverse(neg.begin(),neg.end());

    for(int i=0;i<m;i++) {
        pos[i]=pos[i]*pos[i];
    }

    while(i<n && j<m) {
        if(neg[i]<=pos[j]) {
            ans[id]=neg[i];
            i++;
            id++;
        }
        else {
            ans[id]=pos[j];
            id++;
            j++;
        }
    }

    while(i<n) {
        ans[id]=neg[i];
        id++;
        i++;
    }

    while(j<m) {
        ans[id]=pos[j];
        id++;
        j++;
    }

    return ans;
    }

};