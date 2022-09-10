#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(int data)
{
    // base case
    if (data == -1)
        return NULL;

    // creating a node
    Node *newnode = new Node(data);

    // recursive calls for left and right
    cout << "Enter the left child for " << data << ": ";
    int d;
    cin >> d;
    newnode->left = buildTree(d);

    cout << "Enter the right child for " << data << ": ";
    cin >> d;
    newnode->right = buildTree(d);

    return newnode;
}

// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
// top view of the tree.
// dont think that this can be just achieved by traversing the right and left boundary .
// as there may be a inner bulde in the tree and then our function will stop there.
/*
approach:
    Similar to the vertical order question we will make a mapping of the number on
    the number line with the node occuring. But But..here we will not store all
    the node occuring in that number of the no. line instead we will store the first
    of those which would be on the upper level and hence would be seen from top.
*/

vector<int> topView(Node *root)
{

    map<int, int> ansmap; // only int, int bcoz one node is to be stored here
    queue<pair<Node *, int>> q;

    pair<Node *, int> p = make_pair(root, 0);
    q.push(p);

    while (!q.empty())
    {

        // retrieve level and node data.
        Node *currNode = q.front().first;
        int xcoord = q.front().second;

        // store in the map if not occured before
        if (!ansmap[xcoord]) //we can also use .find function here. ansmap.find(xcoord)==ansmap.end() like this.
        {
            ansmap[xcoord] = currNode->data;
        }

        // pop current node from the queue.
        q.pop();

        // check for left and right and push to queue.
        if (currNode->left)
        {
            pair<Node *, int> temp;
            temp.first = currNode->left;
            temp.second = xcoord - 1;
            q.push(temp);
        }
        if (currNode->right)
        {
            pair<Node *, int> temp;
            temp.first = currNode->right;
            temp.second = xcoord + 1;
            q.push(temp);
        }
    }

    //  o(n) not o(nlogn), because we using map data structure we have to find value in map so
    // finding time o(logn) + overall o(n) ...logn can be ignored so Final TC = o(n) SC = o(n)

    // now ans map is ready: and since this is an ordered map so it will be automatically arranged acc.
    // to the ascending order.
    vector<int> ans;

    map<int, int>::iterator it;

    for (it = ansmap.begin(); it != ansmap.end(); it++)
    {
        ans.push_back(it->second);
    }

    return ans;
}

int main()
{

    Node *root;

    root = buildTree(10);
    // 20 40 -1 -1 60 -1 -1 30 -1 -1

    vector<int> ans = topView(root);
    cout << endl;
    cout << "Top view is: ";
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}