//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        int celebrity = -1;

        // Step 1: Identify a potential celebrity
        for (int rows = 0; rows < n; rows++) {
            bool knowsSomeone = false;

            for (int cols = 0; cols < n; cols++) {
                if (mat[rows][cols] == 1) { // If current person knows someone
                    knowsSomeone = true;
                    break; // No need to check further
                }
            }
            // If this person knows no one, they could be a celebrity
            if (!knowsSomeone) {
                celebrity = rows; // Set potential celebrity
                break; // Found a potential celebrity
            }
        }

        // Step 2: Verify if the identified person is indeed a celebrity
        if (celebrity != -1) {
            for (int cols = 0; cols < n; cols++) {
                if (cols != celebrity && mat[cols][celebrity] == 0) {
                    return -1; // Not a celebrity if someone doesn't know them
                }
            }
            return celebrity; // Return the celebrity index
        }

        return -1; // No celebrity found
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends