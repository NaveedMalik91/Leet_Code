class Solution {
public:
void merge(vector<int> &v, vector<int> &temp, int start, int mid, int end)
{
    //first array = start -> mid
    //second array = mid+1 -> end
    //merged array = start -> end
    int i = start,j = mid+1;
    int  k = start;
    while(i<= mid && j<= end)
    {
        if(v[i]<v[j])
        {
            temp[k++] = v[i++];
            
        }
        else
        {
            temp[k++] = v[j++];
        }
    }

    //Agr arays ka size differ ho
    //toh waaki ke elements ko handle kro
    while(i <=mid)
    {
        temp[k++] = v[i++];
    }
    while(j <= end)
    {
        temp[k++] = v[j++];
    }

    // merged data ko copy karo temp vector se original vector k amdhar
    while(start <= end)
    {
        v[start] = temp[start];
        start++; 
    }
}
void mergeSort(vector<int> &v, int start,vector<int> &temp,int end)
{
    if(start >= end)
    {
        return;
    }
    int mid = (start+end)/2;
    //Divide
    mergeSort(v,start,temp,mid);
    mergeSort(v,mid+1,temp,end);
    //Conquer or merge arrays
    merge(v,temp,start,mid,end);
}
    vector<int> sortArray(vector<int>& nums) {
        //temp storage to store sorted array
        vector<int> temp(nums.size(),0);
        mergeSort(nums,0,temp,nums.size()-1);
        return nums;
        
    }
};