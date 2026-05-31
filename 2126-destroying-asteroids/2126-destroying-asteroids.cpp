class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin() , asteroids.end()) ;
        long long curr = mass ;
        for (int &i : asteroids)
        {
            if (i > curr) return false ;
            else curr += i ;
        }

        return true ;
    }
};