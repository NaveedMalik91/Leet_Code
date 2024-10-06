class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        queue<int> q;
        vector<int> ans(deck.size());

        //push indices of deck in queue
        for(int i = 0;i<ans.size();i++)
        {
            q.push(i);
        }

        //simulation
        for(int i = 0;i<deck.size();i++)
        {
            //Reveal
            ans[q.front()] = deck[i];
            q.pop();

            //Push front at bottom
            if(!q.empty())
            {
                int front = q.front();
                q.pop();
                q.push(front);

            }
        }
        return ans;
    }
};