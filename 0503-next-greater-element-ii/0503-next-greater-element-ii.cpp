class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> ans(nums.size());
        int i=2*nums.size()-1;
        while(i>=0) {
            int j=i%nums.size();
            if(st.empty()) {
                if(i<nums.size()) {
                    ans[i]=-1;
                }
                st.push(nums[j]);
                i--;
            } else if(nums[j]>=st.top()) {
                st.pop();
            } else {
                if(i<nums.size()) {
                    ans[i]=st.top();
                }
                st.push(nums[j]);
                i--;
            }
        }
        return ans;
    }
};