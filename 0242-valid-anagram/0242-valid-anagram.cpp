class Solution {
public:
    bool isAnagram(string s, string t) {
        vector <int> alphabets(150,0);
        vector <int> alphabett(150,0);
        int ch;
        for(int i=0;i<s.size();i++) {
            ch=s[i];
            alphabets[ch]++;
        }
        for(int j=0;j<t.size();j++) {
            ch=t[j];
            alphabett[ch]++;
        }
        for(int k=0;k<150;k++) {
            if(alphabets[k]!=alphabett[k]) {
                return false;
            }
        }
        return true;
    }
};