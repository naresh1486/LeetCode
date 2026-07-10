class Solution {
public:
    string largestOddNumber(string num) {
        int j=num.size()-1;
        while(j>=0 && num[j]%2!=1) {
            j--;
        }
        if(j<0) {
            return "";
        }
        return num.substr(0,j+1);
    }
    
};