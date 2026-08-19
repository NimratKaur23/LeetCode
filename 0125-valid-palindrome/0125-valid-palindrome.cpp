class Solution {
private:
bool valid(char ch) {
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
      return true;
    else
       return false;
}

char toLowerCase(char ch) {
    if((ch>='a' && ch<='z') || (ch>='0' && ch<='9')) {
        return ch;
    }
    else {
        char c=ch-'A'+'a';
        return c;
    }
}

bool ispalindrome(string str) {
    int s=0;
    int e=str.length()-1;

    while(s<=e) {
        if(str[s]!=str[e]) {
            return false;
        }
        else {
            s++;
            e--;
        }
    }

    return true;
}
public:
    bool isPalindrome(string s) {

        string temp="";

        for(int i=0;i<s.length();i++) {
            if(valid(s[i])) {
                temp.push_back(s[i]);
            }
        }


        for(int i=0;i<temp.length();i++) {
            temp[i]=toLowerCase(temp[i]);
        }

        return ispalindrome(temp);
        
    }
};