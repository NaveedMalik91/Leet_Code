class Solution {
public:
    int max_profit_finder(vector<int>& prices, int day, int &min_price,int &max_profit)
    {
        //saare prices dekh liye
        {
            if(day == prices.size())
            {
                return 0;
            }
            //minimum price dekho
            if(prices[day] < min_price)
            {
                min_price = prices[day];
            }

            //min price pe behne pe day profit
            int today_profit = prices[day] - min_price;

            //max profit nikaloo
            if(today_profit > max_profit)
            {
                max_profit = today_profit;
            }
            int ans = max_profit_finder(prices,day+1,min_price,max_profit);
            return ans;
        }
    }
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = INT_MIN;
        int day = 0;
        max_profit_finder(prices,day,min_price,max_profit);
        return max_profit;

        
    }
};