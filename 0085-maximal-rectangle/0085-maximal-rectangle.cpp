class Solution {

public:
    int maxArea(vector<int> passed) {
        //next smaller element
        stack<int> s;
        int n=passed.size();
        vector<int> left(n);
        vector<int> right(n);
        int i=n-1;
        while(i>=0) {
            if(s.empty()) {
                s.push(i);
                right[i]=n;
                i--;
            } else if(passed[i]<=passed[s.top()]) {
                s.pop();
            } else {
                right[i]=s.top();
                s.push(i);
                i--;
            }
        }
        while(!s.empty()) {
            s.pop();
        }
        //left next smaller element
        i=0;
        while(i<n) {
            if(s.empty()) {
                s.push(i);
                left[i]=-1;
                i++;
            } else if(passed[i]<=passed[s.top()]) {
                s.pop();
            } else {
                left[i]=s.top();
                s.push(i);
                i++;
            }            
        }
        i=0;
        int width=0;
        int area=0;
        int ans=0;
        while(i<left.size()) {
            width=right[i]-left[i]-1;
            area=passed[i]*width;
            ans=max(ans,area);
            i++;
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> mat(matrix.size(),vector<int> (matrix[0].size()));
        for(int k=0;k<matrix.size();k++) {
            for(int l=0;l<matrix[0].size();l++) {
                mat[k][l]=matrix[k][l]-'0';
            }
        }
        int area=maxArea(mat[0]);
        for(int i=1;i<mat.size();i++) {
            for(int j=0;j<mat[0].size();j++) {
                if(mat[i][j]!=0) {
                    mat[i][j]=mat[i][j]+mat[i-1][j];
                } else {
                    mat[i][j]=0;
                }
            }
            area=max(area,maxArea(mat[i]));
        }
        return area;
    }
};