class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficit = 0;
        int balance  = 0;
        int start = 0;

        for(int i = 0;i < gas.size();i++)
        {
            //har point pe kitni gas bachi hui hai
            balance = balance + gas[i] - cost[i];

            //agr balance negative hai mtlb
            //gas distance se km hai
            if(balance < 0)
            {
                //kitni gas kam hai
                deficit += abs(balance);

                //next station se start karo
                start = i+1;
                //balanxce ko waapis zero kro
                balance = 0;
            }
        }

        //kya travel possible hai
        if(balance - deficit >= 0)
        {
            return start;
        }
        else
        {
            return -1;
        }

        
    }
};