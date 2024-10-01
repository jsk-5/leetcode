//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// had issues deciding the point where to finish 
// because mid would equal arr_0 and it would time out 
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int high = n-1;
        int low = 0;
        int arr_0 = nums[0];
        int result = 0;
        while(low<=high){
            int mid = (high-low / 2.0) + low;


            if(nums[mid] < arr_0){
                high = mid - 1;
            } else if (nums[mid] >= arr_0){
                low = mid + 1;
            } 
            result = nums[(mid+1)%n];
        }

        return result;
    }
};