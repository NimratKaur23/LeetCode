class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> name;
        vector<string> time;
        vector<string> amount;
        vector<string> city;

      for(auto s:transactions) {
        string na,ti,amt,ct;
        stringstream ss(s);

        getline(ss,na,',');
        getline(ss,ti,',');
        getline(ss,amt,',');
        getline(ss,ct);

        name.push_back(na);
        time.push_back(ti);
        amount.push_back(amt);
        city.push_back(ct);
      }

      vector<string> ans;
      int n=transactions.size();

      for(int i=0;i<n;i++) {
         if(stoi(amount[i])>1000) {
                ans.push_back(transactions[i]);
                continue;
            }
        
        int j=0;
        while(j<n) {

            if(abs(stoi(time[j])-stoi(time[i]))<=60 && name[i]==name[j] && city[i]!=city[j]) {
               ans.push_back(transactions[i]);
               // ans.push_back(transactions[j]);
               break;
            }
            j++;
        }
      }

      return ans;

    }
};