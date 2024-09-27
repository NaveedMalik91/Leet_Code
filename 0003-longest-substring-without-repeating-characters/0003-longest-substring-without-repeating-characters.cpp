class Solution {
public:
    int helper(string &s, int i, unordered_map<char,bool> mpp)
    {
        //this function will give current length for a window
        //base cases
        int len = 0;
        if(i>=s.length())
        {
            return 0;
        }
        if(mpp[s[i]])
        {
            return 0;
        }
        while(i<s.length() && !mpp[s[i]])
        {
            mpp[s[i]] = true;
            i++;
            len++;
        }
        return len;

    }
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
        {
            return 0;
        }
        int max_len = INT_MIN;
        for(int i = 0;i<s.length();i++)
        {
            unordered_map<char,bool> mpp;
            int len = helper(s,i,mpp); // sliding window
            max_len = max(max_len,len);
        }
        return max_len;
    }
};