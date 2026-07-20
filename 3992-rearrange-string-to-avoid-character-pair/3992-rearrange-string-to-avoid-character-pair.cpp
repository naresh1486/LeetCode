class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int i=0;
        int j=0;
        while(j<s.size() && i<s.size()) {
            if(s[i]!=y) {
                i++;
            }
            if(s[j]!=x) {
                j++;
            }
            if(s[i]==y && s[j]==x) {
                if(j<i) {
                    swap(s[i],s[j]);
                    i++;
                    j++;
                    continue;
                }
                i++;

            }
        }
        return s;
    }
};