// https://leetcode.com/problems/frequency-of-the-most-frequent-element/submissions/
// Remember application of the sliding window
// I forgot to account for the fact if a new window isnt valid, 
// we may have to move the left pointer up more than once to account for the new right ptr
// also got caught out my integer over flow in total.
class Solution {
public:
    // int maxFrequency(vector<int>& nums, int k) {
    //     sort(nums.begin(),nums.end());
    //     int max_freq = 0;
    //     for(int i = 0; i<nums.size(); i++){
    //         int target = nums[i];
    //         int changes_left = k;
    //         int freq = 0;
    //         for(int j = i; j>=0 && changes_left > 0; j--){
    //             int diff = target - nums[j];
    //             if(diff <= changes_left){
    //                 changes_left -= diff;
    //                 freq++;
    //             }
    //         }
    //         max_freq = max(max_freq, freq);
    //     }

    //     return max_freq;
    // }
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left_ptr = 0;

        long total = 0;
        int max_window = 0;
        for(int right_ptr = 0; right_ptr<nums.size(); ++right_ptr){
            total = total + nums[right_ptr];
            
            while((long) nums[right_ptr] * (right_ptr - left_ptr + 1) > total + k){
                total = total - nums[left_ptr];
                left_ptr++;
            }
            

            max_window = max(right_ptr - left_ptr + 1, max_window);
            
        }

        return max_window;
    }
};