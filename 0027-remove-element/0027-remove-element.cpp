class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for(int j = 0;j<nums.size();j++)
        {
            if(nums[j]!=val)
            {
                swap(nums[j],nums[i]);
                i++;
            }
           
        }
        // yaha pe i mtlb last index of elemnet without values = val
        // i.e size of updated array itself
        return i;
        
        
    }
};