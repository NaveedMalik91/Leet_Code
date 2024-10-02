class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size() > 1)
        {
            sort(stones.begin(),stones.end());
            int L1 = stones.size()-1;
            int L2 = stones.size()-2;
            if(stones[L1] == stones[L2])
            {
                stones.pop_back();
                stones.pop_back();
            }
            else if(stones[L1] != stones[L2] && stones[L2] < stones[L1])
            {
                stones[L2] = stones[L1] - stones[L2];
                stones.pop_back();
            }
        }
        return stones.empty() ? 0 : stones[0];
        
    }
};