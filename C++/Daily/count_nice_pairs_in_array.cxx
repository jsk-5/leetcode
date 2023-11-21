//https://leetcode.com/problems/count-nice-pairs-in-an-array/submissions/
//Optimised reverse function - casting to string and reversing etc was far slower than this method
//Remember how int,int maps initialie to 0 so if statement isnt needed
//note how adding the number of pairs each time effectively wraps the geometric sum in. Avoids second loop through the 
//map
class Solution {
public:
    // int rev(int x) {
    //     std::string xs = std::to_string(x);
    //     std::reverse(xs.begin(), xs.end());
    //     return std::stoi(xs);
    // }
    int rev(int num) {
        int result = 0;
        while (num > 0) {
            result = result * 10 + num % 10;
            num /= 10;
        }
        
        return result;
    }
    // nums[i]-rev(nums[i]) == nums[j] - rev(nums[j])
    int countNicePairs(vector<int>& nums) {
        long nicePairs = 0;
        int mod = 1000000007;
        std::unordered_map<int,int> exists;

        for(const auto &c : nums){

            int pair = c - rev(c);
            // if(exists.find(pair) == exists.end()){
            //     // std::cout << "INSERT: " << pair << std::endl;
            //     exists[pair] = 1;
            // } else {
            //     // std::cout << pair << std::endl;
            //     exists[pair]++;
            // }
            nicePairs = (nicePairs + exists[pair]) % mod;
            exists[pair]++;
        }

        
        // for(const auto &c : exists){
        //     nicePairs += (long) (c.second)*(c.second-1)/2;
        // }
    
    // return nicePairs % mod;
    return nicePairs;
        

        
    }
};