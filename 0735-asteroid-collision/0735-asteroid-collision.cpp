class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        
        for (int ast : asteroids) {
            bool destroyed = false;
            
            while (!st.empty() && st.back() > 0 && ast < 0) {
                if (abs(ast) > st.back()) {
                    st.pop_back();
                } else if (abs(ast) == st.back()) {
                    st.pop_back();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed) {
                st.push_back(ast);
            }
        }
        return st;
    }
};