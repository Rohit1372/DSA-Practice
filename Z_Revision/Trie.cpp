#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }

    // O(length of word)
    void insert(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index] == NULL)
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        else
        {
            child = root->children[index];
        }
        insert(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insert(root, word);
    }

    // O(length of word)
    bool search(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        return search(child, word.substr(1));
    }

    bool searchWord(string word)
    {
        return search(root, word);
    }

    // O(length of word)
    void remove(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = false;
            return;
        }

        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return;
        }

        remove(child, word.substr(1));
    }

    void removeWord(string word)
    {
        remove(root, word);
    }
};

int main()
{
    Trie *t = new Trie();
    t->insertWord("ABCD");
    t->insertWord("AB");

    cout << "Present or not: " << t->searchWord("ABCD") << endl;
    cout << "Present or not: " << t->searchWord("AB") << endl;

    cout << endl;

    t->removeWord("ABCD");

    cout << "Present or not: " << t->searchWord("ABCD") << endl;
    cout << "Present or not: " << t->searchWord("AB") << endl;

    return 0;
}