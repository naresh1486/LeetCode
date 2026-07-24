class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> lmax(n,0);
        vector<int> rmax(n,0);
        lmax[0]=height[0];
        rmax[n-1]=height[n-1];
        int i=1;
        while(i<n) {
            lmax[i]=max(height[i],lmax[i-1]);
            i++;
        }
        i=n-2;
        while(i>=0) {
            rmax[i]=max(height[i],rmax[i+1]);
            i--;
        }
        i=0;
        int ans=0;
        while(i<n) {
            ans+=min(lmax[i],rmax[i])-height[i];
            i++;
        }
        return ans;
    }
};