class Solution {
public:
    // void rotate(vector<int>& nums, int k) {
    //     /* vector<int> ans(nums.size());
    //      for(int i = 0;i<nums.size();i++)
    //      {
    //          int newindex = (i+k) % nums.size();
    //          ans[newindex] = nums[i];
    //      }
    //      nums = ans;*/
    // }


    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n; // if k is much greater
        reverse(nums, 0, n - 1); // Step 1: Reverse the entire array
        reverse(nums, 0, k - 1); // Step 2: Reverse the first k elements
        reverse(nums, k, n - 1); // Step 3: Reverse the remaining n - k elements
    }
};