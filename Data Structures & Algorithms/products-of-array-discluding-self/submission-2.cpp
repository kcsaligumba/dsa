class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_products(n), right_products(n);
        int left_product = 1, right_product = 1;
        for (int i = 0; i < n; i++) {
            int j = n - 1 - i;
            left_product *= nums[i];
            right_product *= nums[j];
            left_products[i] = left_product;
            right_products[j] = right_product;
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int l_p = 1, r_p = 1;
            if (i > 0) l_p = left_products[i - 1];
            if (i < n - 1) r_p = right_products[i + 1];
            res[i] = l_p * r_p;
        }
        return res;
    }
};
