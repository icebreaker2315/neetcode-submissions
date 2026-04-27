class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int itr1 = 0;
        int itr2 = 0;
        vector<int> ans;

        while(itr1 < m && itr2 < n){
            if(nums1[itr1] > nums2[itr2]){
                ans.push_back(nums2[itr2++]);
            }else{
                ans.push_back(nums1[itr1++]);
            }
        }

        while(itr1 < m){
            ans.push_back(nums1[itr1++]);
        }

        while(itr2 < n){
            ans.push_back(nums2[itr2++]);
        }

        for(int i=0; i<nums1.size(); i++){
            nums1[i] = ans[i];
        }
    }
};