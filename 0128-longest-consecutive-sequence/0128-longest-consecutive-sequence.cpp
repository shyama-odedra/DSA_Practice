class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }
        int maxL = 0;
        for(auto it = st.begin(); it != st.end(); it++){
            int num = *it; 
            if(st.find(num-1) != st.end()) continue;

            int len = 1;
            num++;
            while(st.find(num) != st.end()){
                len++;
                num++;
            } 
            maxL = max(maxL, len);

        }
        return maxL;
    }
};