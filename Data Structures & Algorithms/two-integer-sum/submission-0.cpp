class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> mp;
        vector<int> ans;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int check = target - nums[i]; 
            if(mp.find(check) != mp.end()) {
                auto it = mp.find(check);
                ans.push_back(it -> second);
                ans.push_back(i);
            }else {
                mp[nums[i]] = i;
            }
        }
        return ans;
    }
};
