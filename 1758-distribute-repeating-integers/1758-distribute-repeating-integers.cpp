class Solution {
public:
    bool Check_Function(vector<int>& counts, vector<int>& quantity,int currCust)
    {
        //base case
        if(currCust == quantity.size())
        {
            return true;
        }
        for(int i = 0;i<counts.size();i++)
        {
            //agr same values ith custome ki quantity se zyada hai toh woh value assign kardo
            //mtlb utna count/frequency value ki acual me se minus kardo
            if(counts[i] >= quantity[currCust])
            {
                counts[i] = counts[i] - quantity[currCust]; 
                //agr values assign ho jaati hai sabko toh return kardo true nahi toh back track
                if(Check_Function(counts,quantity,currCust+1))
                {
                    return true;
                }
                //backtrack
                counts[i]+=quantity[currCust];
            }
        }
        return false;


    }
    
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> countMap;
        //ek map banaya jo values aur unki frequency ko store karega
        for(auto val: nums)
        {
            countMap[val]++;
        }
        //ek vector banaya jo frequencies ko store karega sirf
        vector<int> counts;
        for(auto it:countMap)
        {
            counts.push_back(it.second);
        }
        sort(quantity.rbegin(),quantity.rend());

        return Check_Function(counts,quantity,0);
        
    }
};