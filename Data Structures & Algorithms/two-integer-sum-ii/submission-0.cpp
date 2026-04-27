class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      int l = 0;
      int r = numbers.size() - 1;
      vector<int> ans;


      while(l < r){
        int temp = numbers[l] + numbers[r];
        int checker = temp - target;

        if(checker == 0){
            ans.push_back(l+1);
            ans.push_back(r+1);
            break;
        }else if(checker > 0){
            r--;
        }else{
            l++;
        }
      }
      return ans;  
    }
};
