// https://leetcode.com/problems/search-in-rotated-sorted-array/
// Break this one down on a case by case basis 
// If we're on the left side of the disjoint compare mid with target and target with lpointer
// If we're on right side of the disjoint compare mid with target and target with rpointer 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int high = n-1;
        int low = 0;
        int arr_0 = nums[0];

        while(low <= high){
            int mid = (high - low) / 2.0 + low;
            cout << nums[mid] << endl;
            if(nums[mid] == target) return mid;
            if(nums[mid] >= nums[low]) {
                // Left portion
                if(nums[mid] <= target){
                    low = mid + 1;
                } else if (nums[mid] >= target && target >= nums[low]){
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                // Right portion
                if(nums[mid] >= target){
                    high = mid - 1;
                } else if (nums[mid] <= target && target <= nums[high]){
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};