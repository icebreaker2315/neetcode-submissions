class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> mapp;

        for(int num: nums){
            if(mapp.find(num) != mapp.end()){
                return true;
            }
            mapp.insert(num);
        }
        return false;
    }
};