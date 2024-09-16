class Solution {
public:
    void count_cases(vector<int> &v,int &n, int &ans,int currNum)
    {
        //base case
        //jo number hum rakh rahe hai woh last position pe pahunch gaya hai
        if(currNum == n+1)
        {
            ++ans;
            return;
        }
        for(int i = 1;i<=n;i++)
        {
            //agr vector me kisi position pe 0 hai aur koi ek
            //condition satisfy kr raha hai toh element place krdo
            //waaaki recursion sambhaal lega
            if(v[i] == 0 &&(currNum%i == 0 || i%currNum == 0))
            {
                v[i] = currNum;
                count_cases(v,n,ans,currNum+1);
                //agr curr num ko nahi rakh paye toh 0 krdo waapis
                v[i] = 0; //Backtracking
            }
        }
    }
    int countArrangement(int n) {
        //n+1 isliye kyuki vector 0-index se start hoga but hume
        //1-based indexing chahiye
        vector<int> v(n+1);
        int ans = 0;
        count_cases(v,n,ans,1);
        return ans;
        
    }
};