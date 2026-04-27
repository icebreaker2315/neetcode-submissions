class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mapp;
        int count = -1;
        int ans;

        for(int val: nums){
            mapp[val]++;
        }
        
        for(auto it: mapp){
            if(count < it.second){
                count = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};