class Solution {
public:
    bool isPalindrome(int x) {
        long long reverse_num = 0;
        long long actual = x;
        if(x<0)
        {
            return false;
        }
        while(x>0)
        {
            reverse_num =  reverse_num*10 + x%10;
            x = x/10;
        }
        if(actual == reverse_num)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};