class Solution {
public:
    void combination_sum_helper(vector<int> &candidates,int target,vector<int> &vec,vector<vector<int>> &ans,int index)
    {
        //base cas:- pehle element ko consider karte karte target
        // zero yaa negative ho gya
        if(target == 0)
        {
            ans.push_back(vec);
            return;
            
        }
        if(target < 0)
        {
            return;
        }
        for(int i = index; i<candidates.size();i++)
        {
            vec.push_back(candidates[i]);
            combination_sum_helper(candidates,target-candidates[i],vec,ans,i);
            //negative hone pe backtrack karenge aur jo b current element hai use consider nahi karenge
            vec.pop_back(); //yaha pr hum back track kr rahe hai. jo b elements solution bna rahe hai yaa nahi b toh unhe pop kr do and then baaki ke solutions explore karo

        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans; //fro storing the actual vector of values that make up target sum
        vector<int> curr; //For including all values of candidates each time or exclude them
        //Ek index se multiple index ki possibilities check karne k liye
        combination_sum_helper(candidates,target,curr,ans,0); 
        return ans;
    }
};