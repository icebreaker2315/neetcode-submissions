class Solution {
public:
    int maxArea(vector<int>& arr) {
       int left = 0;
       int right = arr.size() - 1;
       int total_area = 0;

       while(left < right){
        int ht = min(arr[left], arr[right]);
        int temp = ht * (right - left);

        if(total_area < temp){
            total_area = temp;
        }

        if(arr[left] < arr[right]){
            left++;
        }else{
            right--;
        } 
        }
        return total_area;
    }
};
