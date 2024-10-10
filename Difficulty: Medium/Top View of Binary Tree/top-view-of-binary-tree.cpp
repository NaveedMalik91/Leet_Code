//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends


/*Logic yeh hai ki hum level order traversal krenge but nodes ka track rakhenge
ki agr kisi horizontal distance pe humne node push kiya hai toh waapis push nahi karenge*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //ek map banao jo nodes aur  unke horz. distance ka track rakhe
        map<int , int> horizontal_dis;
        //ek queue banao jo pairs me data store kare
        queue<pair<Node*,int>> q;
        
        //push root node first inside queue
        q.push(make_pair(root, 0));
          
         //level order traversal karo  
        while(!q.empty())
        {
            pair<Node* , int> temp = q.front();
            q.pop();
            
            Node* frontnode = temp.first;
            int hd = temp.second;
            
            //agr map ke andhar pehle se hd nahi hai mila toh iski entry krdo
            if(horizontal_dis.find(hd) == horizontal_dis.end())
            {
                horizontal_dis[hd] = frontnode->data;
            }
            
            //agr left node hai toh left node aur uska horizontal distance push krdo
            if(frontnode->left !=NULL)
            {
                q.push(make_pair(frontnode->left,hd-1));
            }
            //agr right node hai toh right node aur uska horizontal dist. push krdo
            if(frontnode->right !=NULL)
            {
                q.push(make_pair(frontnode->right,hd+1));
            }
        }
        vector<int> v;
        for(auto val : horizontal_dis)
        {
            v.push_back(val.second);
        }
        return v;
    }

};



//{ Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends