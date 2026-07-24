class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int area = 0;
        vector<int> pre(n, 0);
        vector<int> suf(n, 0);

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, height[i]);
            pre[i] = maxi;
        }
        
        maxi = 0;
        for (int i = n - 1; i >= 0; i--){
            maxi = max(maxi, height[i]);
            suf[i] = maxi;
        }

        for (int i = 0; i < n; i++) {
            area += min(pre[i], suf[i]) - height[i];
        }

        return area;
    }
};
