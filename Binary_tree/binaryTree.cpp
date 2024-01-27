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
        this->left = NULL;
        this->right = NULL;
    }
};

node *builBinaryTree(node *root)
{
    cout << endl;
    cout << "Enter data : ";
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new node(data);
    cout << "Enter element for inserting in left of " << data << " ";
    root->left = builBinaryTree(root->left);
    cout << "Enter element for inserting in right of " << data << " ";
    root->right = builBinaryTree(root->right);

    return root;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
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
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

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
            // cout << temp->data << " ";
            if (temp->right)
            {
                q.push(temp->right);
                st.push(temp->right);
            }
            if (temp->left)
            {
                q.push(temp->left);
                st.push(temp->left);
            }
        }
    }
    st.pop();
    while (!st.empty())
    {
        node *temp1 = st.top();
        st.pop();
        if (temp1 == NULL)
        {
            cout << endl;
        }
        else
        {
            cout << temp1->data << " ";
        }
    }
}

void inOrder(node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void buildTreeLevelOrderTraversal(node *&root)
{
    queue<node *> q;
    cout << "Enter Data : ";
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << "Enter data for insertion in left of " << temp->data << " ";
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        cout << "Enter data for insertion in right of " << temp->data << " ";
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

void inorderMorrisTraversal(node *root)
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
            node *pre = current->left;
            while (pre->right != NULL && pre->right != current)
            {
                pre = pre->right;
            }

            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
            else
            {
                pre->right = NULL;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}

void preOrderMorrisTraversal(node *root)
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
            node *pre = current->left;
            while (pre->right != NULL && pre->right != current)
            {
                pre = pre->right;
            }
            if (pre->right == current)
            {
                pre->right = NULL;
                current = current->right;
            }
            else
            {
                cout << current->data << " ";
                pre->right = current;
                current = current->left;
            }
        }
    }
}

void postOrderMorrisraversal(node *root)
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

int main()
{
    node *root = NULL;

    // buildTreeLevelOrderTraversal(root);
    // levelOrderTraversal(root);

    // Building Binary Tree
    root = builBinaryTree(root);

    // inorderMorrisTraversal(root);

    /*     // Level Order Traversal
        cout << endl;
        levelOrderTraversal(root);

        // Reverse Level Order Traversal
        reverseLevelOrderTraversal(root);

        // Inorder traversal
        cout << endl
             << "Inorder traversal : ";
        inOrder(root);

        // Preorder traversal
        cout << endl
             << "Preorder traversal : ";
        preOrder(root);

        // Postorder traversal
        cout << endl
             << "Postorder traversal : ";
        postOrder(root);
        */

    // Preorder traversal
    cout << endl
         << "PostOrder traversal : ";
    postOrder(root);

    cout << endl
         << "Morris Postorder traversal : ";
    postOrderMorrisraversal(root);
}