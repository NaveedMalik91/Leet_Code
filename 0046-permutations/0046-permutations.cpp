class Solution {
public:
    void Helper(vector<int>& nums, vector<vector<int>>& ans, int index) {
        if (index >= nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            Helper(nums, ans, index + 1);
            swap(nums[index], nums[i]); // Backtrack to restore original state
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        Helper(nums, ans, 0);
        return ans;
    }
};
