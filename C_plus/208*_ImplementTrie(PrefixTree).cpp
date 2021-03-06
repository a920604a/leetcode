class TrieNode
{
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode() : isWord(false)
    {
        for (auto &a : child)
            a = nullptr;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *p = root;
        for (auto &c : word)
        {
            int i = c - 'a';
            if (!p->child[i])
                p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *p = root;
        for (char c : word)
        {
            int i = c - 'a';
            if (p->child[i] == nullptr)
                return false;
            p = p->child[i];
        }
        return p->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *p = root;
        for (char c : prefix)
        {
            int i = c - 'a';
            if (p->child[i] == nullptr)
                return false;
            p = p->child[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */