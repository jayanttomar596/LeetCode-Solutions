class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "" ;

        for (auto &word : words)
            {
                int sum = 0 ;

                for (char ch : word)
                    {
                        sum += weights[ch - 'a'] ;
                    }

                int Val = sum % 26 ;
                char mapped = 'z' - Val ;

                ans.push_back(mapped) ;
            }

        return ans ;
    }
};