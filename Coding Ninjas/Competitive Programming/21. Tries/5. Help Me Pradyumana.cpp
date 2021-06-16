/* Pradyumn is tired of using auto - correct feature in his smartphone. 
He needs to correct his auto - correct more times than the auto - correct corrects him. 
Pradyumn is thinking to make his own app for mobile which will restrict auto - correct feature, 
instead it will provide auto - completion. 
Whenever Pradyumn types factorial, auto - correct changes it to fact. 
Pradyumn's App will show options such as fact, factorial, factory. 
Now, he can chose from any of these options. 
As Pradyumn is busy with his front - end work of his App. 
He asks you to help him. 
He said "You will be given set of words(words may repeat too but counted as one only). 
Now, as user starts the app, he will make queries(in lowercase letters only). 
So, you have to print all the words of dictionary which have the prefix same as given by user as input. 
And if no such words are available, add this word to your dictionary." 
As you know, Pradyumn want this app to be as smart as him :P 
So, implement a program for him such that he can release it on Fun Store. */

#include <bits/stdc++.h>

using namespace std;

class trieNode
{
public:
    trieNode **children;
    bool isLeaf = false;

    trieNode()
    {
        children = new trieNode *[26];
        isLeaf = false;

        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

void insert(string s, trieNode *root)
{
    if (s.length() == 0)
    {
        root->isLeaf = true;
        return;
    }

    trieNode *current;

    int index = s[0] - 'a';

    if (root->children[index] != NULL)
    {
        current = root->children[index];
    }
    else
    {
        current = new trieNode();
        root->children[index] = current;
        current = root->children[index];
    }

    insert(s.substr(1), current);
}

void helper(trieNode *current, string prefix)
{
    bool checker = true;

    if (current->isLeaf)
    {
        cout << prefix << endl;
    }

    for (int i = 0; i < 26; i++)
    {
        trieNode *temp = current;

        if (temp->children[i] != NULL)
        {
            char suffix = (int)i + (int)'a';
            helper(current->children[i], prefix + suffix);
        }
    }
}

void printer(trieNode *root, string s)
{
    trieNode *current = root;

    for (int i = 0; i < s.length(); i++)
    {
        int index = s[i] - 'a';

        if (current->children[index] != NULL)
        {
            current = current->children[index];
        }
        else
        {
            cout << "No suggestions" << endl;
            insert(s, root);
            return;
        }
    }

    helper(current, s);
}

int main()
{
    int n;
    cin >> n;

    trieNode *root = new trieNode();

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        insert(s, root);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        string s;
        cin >> s;

        printer(root, s);
    }

    return 0;
}
