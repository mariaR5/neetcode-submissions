class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> v1;
        vector<int> v2;
        int pdt1 = 1, pdt2 = 1;

        int left = 0, right = n - 1;
        while(left < n && right >= 0) {
            pdt1 *= nums[left];
            v1.push_back(pdt1);
            left++;

            pdt2 *= nums[right];
            v2.push_back(pdt2);
            right--;
        }

        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int i1 = n + i - (n+1);
            int i2 = n - i - 2;

            int prod = 1;
            if (i1 >= 0) prod *= v1[i1];
            if (i2 >= 0) prod *= v2[i2];

            result[i] = prod;
        }

        return result;
    }
};
