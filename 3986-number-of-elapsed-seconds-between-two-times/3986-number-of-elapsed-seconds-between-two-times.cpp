class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int temp1=startTime.size()-1;
        int ans1=0;
        int val=1;
        bool check=false;
        while(temp1>=0) {
            ans1+=(startTime[temp1]-'0')*val;
            temp1--;
            if(check==true) {
                val=val*6;
                check=false;
                temp1--;
            } else {
                val=val*10;
                check=true;
            }
        }
        int temp2=endTime.size()-1;
        int ans2=0;
        val=1;
        check=false;
        while(temp2>=0) {
            ans2+=(endTime[temp2]-'0')*val;
            temp2--;
            if(check==true) {
                val=val*6;
                check=false;
                temp2--;
            } else {
                val=val*10;
                check=true;
            }
        }
        return ans2-ans1;
    }
};