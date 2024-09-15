class Solution {
public:
    void mergeInplace(vector<int>& v, int start, int mid, int end) {
        int total_len = end - start + 1;
        int gap =(total_len/2)+(total_len%2);
        while (gap > 0) {
            int i = start;
            int j = gap + start;
            while (j <= end) {
                if (v[i] > v[j]) {
                    swap(v[i], v[j]);
                }
                ++i;
                ++j;
            }
            gap = gap<=1?0:(gap/2)+(gap%2);
        }
    }
    void mergeSort(vector<int>& v, int start, int end) {
        if (start >= end) {
            return;
        }
        int mid = (start + end) / 2;
        // Divide
        mergeSort(v, start, mid);
        mergeSort(v, mid + 1, end);
        // Conquer or merge sorted arrays
        mergeInplace(v, start, mid, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};