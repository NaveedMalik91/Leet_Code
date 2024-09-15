class Solution {
public:
    int max_sum_subarray(vector<int> &nums, int start, int end)
    {
        if(start == end){
            return nums[start];
        }
        int maxleftBordersum = INT_MIN;
        int maxrightBordersum = INT_MIN;
        int leftBordersum = 0;
        int rightBordersum = 0;


        int mid = start + (end-start)/2;
        //left and right sum
        int maxleftsum = max_sum_subarray(nums,start,mid);
        int maxrightsum  = max_sum_subarray(nums,mid+1,end);
       
        //left border sum
        for(int i = mid; i>=start;i--)
        {
            leftBordersum+=nums[i];
            if(leftBordersum > maxleftBordersum)
            {
                maxleftBordersum = leftBordersum;
            }

        }

        //Right border sum
        for(int i = mid+1; i<=end;i++)
        {
            rightBordersum+=nums[i];
            if(rightBordersum > maxrightBordersum)
            {
                maxrightBordersum = rightBordersum;
            }

        }
        int crossBordersum = maxrightBordersum+maxleftBordersum;
        return max(crossBordersum,max(maxrightsum,maxleftsum));


    }
    int maxSubArray(vector<int>& nums) {
        return max_sum_subarray(nums,0,nums.size()-1);
        
    }
};