class Solution {
public:

    struct TrieNode
    {
        int idx;
        int child[26];

        TrieNode()
        {
            idx = 0;

            for(int i = 0; i < 26; i++)
            {
                child[i] = -1;
            }
        }
    };

    vector<TrieNode> trie;

    void insertTrie(int wordIdx, vector<string>& wordsContainer)
    {
        string &word = wordsContainer[wordIdx];

        int n = word.size();

        int node = 0;

        for(int i = n - 1; i >= 0; i--)
        {
            int ch = word[i] - 'a';

            if(trie[node].child[ch] == -1)
            {
                trie[node].child[ch] = trie.size();

                TrieNode newNode;
                newNode.idx = wordIdx;

                trie.push_back(newNode);
            }

            node = trie[node].child[ch];

            if(wordsContainer[trie[node].idx].size() > n)
            {
                trie[node].idx = wordIdx;
            }
        }
    }

    int search(string &word)
    {
        int node = 0;

        int ans = trie[0].idx;

        int n = word.size();

        for(int i = n - 1; i >= 0; i--)
        {
            int ch = word[i] - 'a';

            if(trie[node].child[ch] == -1)
            {
                return ans;
            }

            node = trie[node].child[ch];

            ans = trie[node].idx;
        }

        return ans;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery)
    {
        trie.push_back(TrieNode());

        int m = wordsContainer.size();

        for(int i = 0; i < m; i++)
        {
            if(wordsContainer[trie[0].idx].size() > wordsContainer[i].size())
            {
                trie[0].idx = i;
            }

            insertTrie(i, wordsContainer);
        }

        vector<int> result;

        for(string &word : wordsQuery)
        {
            result.push_back(search(word));
        }

        return result;
    }
};