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
        this->left = NULL;
        this->right = NULL;
    }
};

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

int minVal(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

int maxVal(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

Node *deletionInBST(Node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->data == val)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

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

        if (root->left != NULL && root->right != NULL)
        {
            int mini = minVal(root->right);
            root->data = mini;
            root->right = deletionInBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > val)
    {
        root->left = deletionInBST(root->left, val);
        return root;
    }
    else
    {
        root->right = deletionInBST(root->right, val);
        return root;
    }
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
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

Node *buildBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = buildBST(root->right, data);
    }
    else
    {
        root->left = buildBST(root->left, data);
    }

    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = buildBST(root, data);
        cin >> data;
    }
}

void inorderMorrisTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Node *current = root;

    while (current != NULL)
    {
        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            Node *pre = current->left;
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

int main()
{

    Node *root = NULL;

    cout << endl;
    cout << "ENter data : ";
    takeInput(root);

    cout << endl
         << "Printing the BST : " << endl;
    levelOrderTraversal(root);

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

    cout << endl
         << "Morris Inorder traversal : ";
    inorderMorrisTraversal(root);

    cout << endl;
    // Minimum value in binary search tree
    cout << "Minimum value is : " << minVal(root) << endl;

    // Maximum value in binary search tree
    cout << "Maximum value is : " << maxVal(root) << endl;

    /*   // deletion in binary search tree
      root = deletionInBST(root, 10);

      cout << endl
           << "Printing the BST : " << endl;
      levelOrderTraversal(root); */

    // cout << "Answer is : " << inorderPredecessor(root, 9)->data << endl;
}