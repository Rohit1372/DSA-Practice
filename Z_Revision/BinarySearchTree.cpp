#include <bits/stdc++.h>
using namespace std;

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

// Inorder of BST is always Sorted
// Insertion Time Complexity in BST : O(logn)
// Deletion Time Complexity in BST : O(height) - in avg case  /  O(n) - in worst case

Node *buildTree(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = buildTree(root->right, data);
    }
    else
    {
        root->left = buildTree(root->left, data);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = buildTree(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL); // Insert NUll so that we identify where is level finished
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        // if queue front conatin null means previous level finished that means move to next line
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        // if queue front not null means print that data and left or right of data insert in to queue
        else
        {
            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

// Inorder traversal
// LNR  - Left Node Right
void inorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Preorder traversal
// NLR  - Node Left Right
void preorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder traversal
// LRN  - Left Right Node
void postorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int minValue(Node *root)
{

    Node *temp = root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp->data;
}

int maxValue(Node *root)
{

    Node *temp = root;

    while (temp->right != NULL)
    {
        temp = temp->right;
    }

    return temp->data;
}

Node *inorderSuccessorPredecessor(Node *root, int data)
{
    cout << endl;
    if (root == NULL)
    {
        return NULL;
    }

    Node *pred = NULL;
    Node *succ = NULL;

    if (root->data == data)
    {
        // For pred -- move to left and then right until reached to null
        if (root->left)
        {
            Node *p = root->left;
            while (p->right)
            {
                p = p->right;
            }
            pred = p;
            cout << "Predeccessor : "
                 << pred->data << endl;
        }

        // For succ -- move to right and then left until reached to null
        if (root->right)
        {
            Node *p = root->right;
            while (p->left)
            {
                p = p->left;
            }
            succ = p;
            cout << "Successor : "
                 << succ->data << endl;
        }
    }
    else if (root->data > data)
    {
        succ = root;
        inorderSuccessorPredecessor(root->left, data);
    }
    else
    {
        pred = root;
        inorderSuccessorPredecessor(root->right, data);
    }
}

Node *deleteInBST(Node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == data)
    {
        // zero nodes
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // one nodes
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // two nodes
        if (root->left != NULL && root->right != NULL)
        {
            // int mini = minValue(root->right);
            // root->data = mini;
            // root->right = deleteInBST(root->right, mini);
            // return root;

            int maxi = maxValue(root->left);
            root->data = maxi;
            root->left = deleteInBST(root->left, maxi);
            return root;
        }
    }
    else if (root->data > data)
    {
        root->left = deleteInBST(root->left, data);
        return root;
    }
    else
    {
        root->right = deleteInBST(root->right, data);
        return root;
    }
}

// 2nd way to find Successor Predecessor

void findSuccessorPredecessor(Node *root, int data, Node *&pred, Node *&succ)
{

    Node *temp = root;

    while (temp != NULL)
    {
        if (temp->data >= data)
        {
            temp = temp->left;
        }
        else
        {
            pred = temp;
            temp = temp->right;
        }
    }

    temp = root;

    while (temp != NULL)
    {
        if (temp->data <= data)
        {
            temp = temp->right;
        }
        else
        {
            succ = temp;
            temp = temp->left;
        }
    }
}

int main()
{
    Node *root = NULL;
    cout << "Enter data to create BST : " << endl;
    takeInput(root);

    cout << endl
         << "Printing the BST : " << endl;
    levelOrderTraversal(root);

    cout << endl
         << "Inorder : ";
    inorderTraversal(root);
    cout << endl
         << "Preorder : ";
    preorderTraversal(root);
    cout << endl
         << "Postorder : ";
    postorderTraversal(root);

    // cout << endl
    //      << "Minimum Value : " << minValue(root);

    // cout << endl
    //      << "Maximum Value : " << maxValue(root);

    // inorderSuccessorPredecessor(root, 5);
    // Node *pred = NULL;
    // Node *succ = NULL;
    // findSuccessorPredecessor(root, 5, pred, succ);

    // cout << "Predeccessor : " << pred->data << endl;
    // cout << "Successor : " << succ->data << endl;

    // cout << endl
    //      << "After deletion : " << endl;

    // deleteInBST(root, 12);

    // cout << endl
    //      << "Printing the BST : " << endl;
    // levelOrderTraversal(root);
}