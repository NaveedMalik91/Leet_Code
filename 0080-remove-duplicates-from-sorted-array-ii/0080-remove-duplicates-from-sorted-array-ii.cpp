class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 1)
        {
            return 1;
        }
        int i = 0;
        int j = 1;
        int k = 2;
        while(k<nums.size())
        {
            if(nums[i]== nums[k])
            {
                k++;
            }
            else
            {
                j++;
                nums[j] = nums[k];
                i++;
                k++;
            }
        }
        return j+1;
        
    }
};