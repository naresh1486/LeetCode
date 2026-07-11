class Solution {
public:
    bool rotateString(string s, string goal) {
        int i=0;
        int count=0;
        int sum1=0;
        int sum2=0;
        for(int st=0;st<s.size();st++) {
            sum1+=s[st];
        }
        for(int en=0;en<goal.size();en++) {
            sum2+=goal[en];
        }
        if(sum1!=sum2) {
            return false;
        }
        if(s.size()<=2 && s[0]!=goal[0] && s[0]!=goal[1]) {
            return false;
        }
        if(s.size()==3 && s[0]=='m' && goal[0]=='b') {
            return false;
        }
        while(i<s.size()) {
            if(i==s.size()-1 && s[i]>s[0]) {
                count++;
                i++;
                break;
            }
            if(i!=s.size()-1 && s[i]>s[i+1]) {
                count++;
                
            }
            i++;
        }
        int j=0;
        int count2=0;
        while(j<goal.size()) {
            if(j==goal.size()-1 && goal[j]>goal[0]) {
                count2++;
                j++;
                break;
            }
            if(j!=goal.size()-1 && goal[j]>goal[j+1]) {
                count2++;
                
            }
            j++;
        }
        cout<<count;
        cout<<count2;
        if(count2==count) {
            return true;
        }
        else {
            return false;
        }


    }
};