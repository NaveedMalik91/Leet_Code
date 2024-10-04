//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string str){
		    // Code here
		    string ans = "";
		    queue<char> q;
		    //size = total alphabets
		    int freq[26] = {0};
		    for(int i = 0;i<str.length();i++)
		    {
    		        char ch = str[i];
    		        //track freq of each char
    		        //int the order of alphabets maintained here
    		        freq[ch - 'a']++;
    		        
    		        q.push(ch);
    		    
    		    
    		    //answer find karo
    		    while(!q.empty())
    		    {
    		        char frontchar = q.front();
    		        //agr 1 se zayada hai toh mtlb repeating
    		        if(freq[frontchar - 'a'] > 1)
    		        {
    		            q.pop();
    		        }
    		        
    		        //mtlb non-repeating
    		        else
    		        {
    		            ans+=frontchar;
    		            break;
    		        }
    		    }
    		    if(q.empty())
    		    {
    		        ans+='#';
    		    }
		  }
		  return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends