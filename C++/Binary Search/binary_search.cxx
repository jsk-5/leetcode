// https://leetcode.com/problems/binary-search/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int top = nums.size()-1;
        int bottom = 0;

        while(bottom <= top){
            int middle = ((top - bottom) / 2 + bottom);
            if(nums[middle] < target){
                bottom = middle + 1;
            } else if (nums[middle] > target){
                top = middle - 1;
            } else {
                return middle;
            }
        }
        return -1;
    }
};