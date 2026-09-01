class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> c;
        c[0]=1;
        int pre=0;
        int t=0;

        for(int num: nums){
            pre +=num;

            if(c.find(pre-goal)!=c.end()){
                t += c[pre-goal];
            }
            c[pre]++;
        }
        return t;
    }
};