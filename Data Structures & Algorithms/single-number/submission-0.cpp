class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int temp = nums[0];

        for(int i=1; i<n; i++){
            temp ^= nums[i];
        }
        
        return temp;
    }
};
