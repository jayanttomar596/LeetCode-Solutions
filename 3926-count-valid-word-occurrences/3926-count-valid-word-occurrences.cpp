class Solution {
    bool isLetter(char c) {
        return c >= 'a' && c <= 'z';
    }
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s = "";

        for (auto &x : chunks)
            s += x;

        unordered_map<string,int> freq;

        int n = s.size();
        int i = 0;

        while (i < n) {

            if (!isLetter(s[i])) 
            {
                i++;
                continue;
            }

            string word = "";

            while (i < n) 
            {

                if (isLetter(s[i])) 
                {
                    word += s[i];
                    i++;
                }
                else if (
                    s[i] == '-' &&
                    i - 1 >= 0 &&
                    i + 1 < n &&
                    isLetter(s[i - 1]) &&
                    isLetter(s[i + 1])
                ) 
                {
                    word += s[i];
                    i++;
                }
                else
                {
                    break;
                }
            }

            freq[word]++;
        }

        vector<int> ans;

        for (auto &q : queries)
            ans.push_back(freq[q]);

        return ans;
    }
};