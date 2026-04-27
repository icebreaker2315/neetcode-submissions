class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = (n*(n+1))/2;

        int temp = 0;
        for(int it : nums){
            temp += it;
        }

        return total-temp;
    }
};
