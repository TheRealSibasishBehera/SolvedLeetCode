/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node *, Node *> mpp;

    void helper(Node *node)
    {

        //i could not think this
        if (!node || mpp.find(node) != mpp.end())
        {
            return; // base condition or already visited
        }

        Node *newp = new Node(node->val);
        mpp[node] = newp; 

        // make neighbors
        for (auto newc : node->neighbors)
        {
            helper(newc);
            newp->neighbors.push_back(mpp[newc]);
        }
    }

    Node* cloneGraph(Node *node)
    {
        if (!node)
        {
            return nullptr; // handle edge case when the input graph is empty
        }

        // initiate the DFS cloning
        helper(node);
        return mpp[node];
    }
};