#https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        sort(nums.begin(), nums.end());

        auto start_ptr = nums.begin();
        auto end_ptr = nums.end() -1;
        int max_pair = -1;

        for(int i = 0; i<(nums.size()/2); i++){
            if((*start_ptr + *end_ptr) > max_pair) max_pair = *start_ptr + *end_ptr;
            // std::cout << *start_ptr << "," << *end_ptr << std::endl;
            start_ptr++;
            end_ptr--;
        }
        return max_pair;
    }
};