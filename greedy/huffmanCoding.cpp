// Given a string S of distinct character of size N and their corresponding frequency f[ ] i.e. character S[i] has f[i] frequency. Your task is to build the Huffman tree print all the huffman codes in preorder traversal of the tree.
// Note: While merging if two nodes have the same value, then the node which occurs at first will be taken on the left of Binary Tree and the other one to the right, otherwise Node with less value will be taken on the left of the subtree and other one to the right.

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class cmp
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    void preOrder(Node *root, vector<string> &ans, string temp)
    {
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(temp);
            return;
        }

        preOrder(root->left, ans, temp + '0');
        preOrder(root->right, ans, temp + '1');
    }

    vector<string> huffmanCodes(string S, vector<int> f, int N)
    {
        // Code here
        priority_queue<Node *, vector<Node *>, cmp> pq;

        for (auto x : f)
        {
            pq.push(new Node(x));
        }

        while (pq.size() > 1)
        {
            Node *left = pq.top();
            pq.pop();
            Node *right = pq.top();
            pq.pop();

            Node *newNode = new Node(left->data + right->data);

            newNode->left = left;
            newNode->right = right;
            pq.push(newNode);
        }

        Node *root = pq.top();
        vector<string> ans;
        string temp = "";
        preOrder(root, ans, temp);
        return ans;
    }