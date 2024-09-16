class Solution {
public:
    void Helper(vector<int>& nums, vector<vector<int>>& ans, int index) {
        if (index >= nums.size()) {
            ans.push_back(nums);
            return;
        }
        unordered_map<int, bool> visited;
        for (int i = index; i < nums.size(); i++) {
            if (visited.count(nums[i])) {
                continue;
            }
            visited[nums[i]] = true;

            swap(nums[index], nums[i]);
            Helper(nums, ans, index + 1);
            swap(nums[index], nums[i]); // Backtrack to restore original state
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        Helper(nums, ans, 0);
        return ans;
    }
};
