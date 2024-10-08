class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans(nums.size());
        for(int i = 0;i<nums.size();i++)
        {
            int newindex = (i+k) % nums.size();
            ans[newindex] = nums[i];
        }
        nums = ans;
    }
};