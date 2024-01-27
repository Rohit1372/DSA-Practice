#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Build Binary Tree
node *buildBinaryTree(node *root)
{
    int data;
    cout << endl;
    cout << "Enter data : ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    root = new node(data);
    cout << "Enter data inserting in left of " << data << " -> ";
    root->left = buildBinaryTree(root->left);
    cout << "Enter data inserting in right of " << data << " -> ";
    root->right = buildBinaryTree(root->right);

    return root;
}

// void levelOrderTraversal(node *root)
// {
//     queue<node *> q;
//     q.push(root);
//     while (!q.empty())
//     {
//         node *temp = q.front();
//         q.pop();
//         cout << temp->data << " ";
//         if (temp->left != NULL)
//         {
//             q.push(temp->left);
//         }
//         if (temp->right != NULL)
//         {
//             q.push(temp->right);
//         }
//     }
// }

// Level to level print elements
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL); // Insert NUll so that we identify where is level finished
    while (!q.empty())
    {
        node *temp = q.front();
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

// Level to level print elements in reverse order
void reverseLevelOrderTraversal(node *root)
{

    queue<node *> q;
    stack<node *> st;

    q.push(root);
    q.push(NULL);
    st.push(root);
    st.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
                st.push(NULL);
            }
        }
        else
        {
            if (temp->right != NULL)
            {
                q.push(temp->right);
                st.push(temp->right);
            }
            if (temp->left != NULL)
            {
                q.push(temp->left);
                st.push(temp->left);
            }
        }
    }

    st.pop();

    while (!st.empty())
    {
        node *temp = st.top();
        st.pop();
        if (temp == NULL)
        {
            cout << endl;
        }
        else
        {
            cout << temp->data << " ";
        }
    }
}

// Inorder traversal
// LNR  - Left Node Right
void inorderTraversal(node *root)
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
void preorderTraversal(node *root)
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
void postorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

// Build tre eform level order traversal
void buildTreeFromLevelOrderTraversal(node *&root)
{
    queue<node *> q;
    int data;
    cout << "Enter data : ";
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter data insert at left for " << temp->data << " : ";
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter data insert at right for " << temp->data << " : ";
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

// Morris Inorder Traversal TC -> O(N)  SC -> O(1)
void morrisTraversalInorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    node *current = root;

    while (current != NULL)
    {
        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            node *prev = current->left;
            while (prev->right != NULL && prev->right != current)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = current;
                current = current->left;
            }
            else
            {
                prev->right = NULL;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}

// Morris Preorder Traversal TC -> O(N)   Sc -> O(1)
void morrisTraversalPreorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    node *current = root;

    while (current != NULL)
    {
        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            node *prev = current->left;
            while (prev->right != NULL && prev->right != current)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = current;
                cout << current->data << " ";
                current = current->left;
            }
            else
            {
                prev->right = NULL;
                current = current->right;
            }
        }
    }
}

// Morris Postorder Traversal TC -> O(N)   Sc -> O(1)
void morrisraversalPostorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    vector<int> res;

    node *current = root;

    while (current != NULL)
    {
        if (current->right == NULL)
        {
            // cout << current->data << " ";
            res.push_back(current->data);
            current = current->left;
        }
        else
        {
            node *pred = current->right;

            while (pred->left != NULL && pred->left != current)
            {
                pred = pred->left;
            }

            if (pred->left == NULL)
            {
                pred->left = current;
                // cout << current->data << " ";
                res.push_back(current->data);
                current = current->right;
            }
            else
            {
                pred->left = NULL;
                current = current->left;
            }
        }
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}

// Simple traverse for check ele inserted or not
void traverseTree(node *root)
{
    if (root == NULL)
    {
        cout << "-1 ";
        return;
    }
    cout << root->data << " ";
    traverseTree(root->left);
    traverseTree(root->right);
}

int main()
{

    node *root = NULL;

    // buildTreeFromLevelOrderTraversal(root);
    // levelOrderTraversal(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildBinaryTree(root);

    // // traverseTree(root);
    // cout << endl;
    // levelOrderTraversal(root);

    // reverseLevelOrderTraversal(root);

    // cout << endl
    //      << endl;
    // cout << "Inorder Traversal : ";
    // inorderTraversal(root);
    // cout << endl;
    // cout << "Preorder Traversal : ";
    // preorderTraversal(root);
    cout << endl;
    cout << "Postorder Traversal : ";
    postorderTraversal(root);

    // cout << endl
    //      << endl;
    // cout << "Morris Inorder Traversal : ";
    // morrisTraversalInorder(root);

    cout
        << endl;
    cout << "Morris PostOrder Traversal : ";
    morrisraversalPostorder(root);
}