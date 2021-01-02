#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        char data;
        int wordEnd;
        TrieNode *child[26];
};

// TrieNode nodepool[100000];  //Pool of 100K Trienodes
// TrieNode *root;    //Root of Trie
// int poolcount;  //Always points to next free Trienode

// void init()
// {
//     poolcount = 0;
//     root = &nodepool[poolcount++];
//     root->data = '/';
//     for(int i = 0; i < 26; i++)
//     {
//         root->child[i] = NULL;
//     }
// }


TrieNode *getNode(char c)
{
    TrieNode *newNode = new TrieNode();
    
    for(register int i=0;i<26;++i)
        newNode->child[i] = NULL;
    newNode->wordEnd=0;
    newNode->data = c;
    return newNode;
}

// Inserts the word onto the Trie
void Insert(TrieNode* root, char *s)
{
    TrieNode *curr = root;
    int index;

    for(int i = 0; s[i] != '\0'; ++i)
    {
        index = s[i] - 'a';     // Get the relative position in the alphabet list
        if(curr->child[index] == NULL)  // If the corresponding child doesn't exist,simply create that child!
        {
            curr->child[index] = getNode(s[i]);
        }
        else
        {
            // Do nothing. The node already exists
        }
        curr->child[index]->wordEnd += 1;
        curr = curr->child[index];
    }
}


bool search(TrieNode* root,char *s)
{
    TrieNode *curr = root;
    int index;

    for(int i = 0; s[i] != '\0'; ++i)
    {
        index = s[i] - 'a';
        if(curr->child[index] == NULL || curr->child[index]->wordEnd == 0)
        {
            return false;
        }
        curr = curr->child[index];
    }
    return true;
}

bool Triedelete(TrieNode* root, char *s)
{
    if(search(root,s))
    {
        TrieNode *curr = root;
        int index;

        for(int i = 0; s[i] != '\0'; ++i)
        {
            index = s[i] - 'a';
            curr->child[index]->wordEnd -= 1;
            curr = curr->child[index];
        }
    }
}

int countPrefix(TrieNode* root,string s)
{
    TrieNode *curr = root;
    int index;
    for(int i = 0; s[i] != '\0'; ++i)
    {
        index = s[i] - 'a';
        if(curr->child[index] == NULL ||curr->child[index]->wordEnd == 0)
        {
            return 0;
        }
        curr = curr->child[index];
    }
    return curr->wordEnd;
}

int main()
{
   //init();
   TrieNode *root = getNode('\0');

    char a[5] = {'a','r','m','y'};
    char b[5] = {'a','r','m'};
    char c[5] = {'a','r','m','s'};
    char d[5] = {'a','r','y'};
    char e[5] = {'a','m','y'};
    char f[5] = {'a','p','i'};
    char g[5] = {'a','t','i'};


    Insert(root,a);
    Insert(root,b);
    Insert(root,c);
    Insert(root,d);
    Insert(root,e);
    Insert(root,f);

    cout<<search(root,b)<<"\n";
    cout<<search(root,g)<<"\n";

    printf("No of strings with given prefix = %d\n",countPrefix(root,"a"));
    printf("No of strings with given prefix = %d\n",countPrefix(root,"ar"));
    printf("No of strings with given prefix = %d\n",countPrefix(root,"arm"));
    printf("No of strings with given prefix = %d\n",countPrefix(root,"army"));
    printf("No of strings with given prefix = %d\n",countPrefix(root,"armi"));
    printf("No of strings with given prefix = %d\n",countPrefix(root,"ary"));


    cout<<"Deletion...STARTED\n";
    Triedelete(root, a);
    Triedelete(root, d);
    cout<<"DONE...\n\n";


    printf("No of strings with given prefix = %d\n",countPrefix(root,"a"));
    printf("No of strings with given prefix = %d\n",countPrefix(root,"ar"));
    printf("No of strings with given prefix = %d\n",countPrefix(root,"arm"));
    printf("No of strings with given prefix = %d\n",countPrefix(root,"army"));
    printf("No of strings with given prefix = %d\n",countPrefix(root,"armi"));
    printf("No of strings with given prefix = %d\n",countPrefix(root,"ary"));

    
    return 0;
}