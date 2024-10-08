class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        unordered_map<int,int> freq;
        for(int i = 0;i<n;i++)
        {
            freq[nums[i]]++;
        }
        for(int i = 0;i < n;i++)
        {
            if(freq[nums[i]] > nums.size() /2)
            {
                return nums[i];
            }
        }
        return -1;
    }
};