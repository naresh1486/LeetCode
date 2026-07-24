class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        vector<int> left(n);
        vector<int> right(n);
        //Next Smaller Right
        int i=n-1;
        while(i>=0) {
            if(st.empty()) {
                st.push(i);
                right[i]=n;
                i--;
            }else if(heights[i]<=heights[st.top()]) {
                st.pop();
            } else {
                right[i]=st.top();
                st.push(i);
                i--;
            }
        }
        while(!st.empty()) {
            st.pop();
        }
        i=0;
        while(i<n) {
            if(st.empty()) {
                st.push(i);
                left[i]=-1;
                i++;
            }else if(heights[i]<=heights[st.top()]) {
                st.pop();
            } else {
                left[i]=st.top();
                st.push(i);
                i++;
            }
        }
        i=0;
        int final=0;
        int ans=0;
        while(i<n) {
            int width=right[i]-left[i]-1;
            final=width*heights[i];
            ans=max(final,ans);
            i++;
        }
        return ans;
    }
};