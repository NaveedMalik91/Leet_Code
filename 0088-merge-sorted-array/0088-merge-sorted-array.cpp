class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /*int i = 0;
        int j = 0;
        int k = 0;
        int arr[n+m];
       while(i<m && j<n)
       {
            if (nums1[i]<=nums2[j])
            {
                arr[k] = nums1[i];
                k++;
                i++;
            }
            else
            {
                arr[k] = nums2[j];
                j++;
                k++;
            }
       }
        while (i < m)
        {
            arr[k++] = nums1[i++];
        }
        while (j < n) {
            arr[k++] = nums2[j++];
        }
        for(int i = 0;i<n+m;i++)
        {
            nums1[i] = arr[i];
            
        }*/

        //Optimum approach

       int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }



    }
};