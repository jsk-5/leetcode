#https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2023-11-16
class Solution {
public:
    string subset;
    vector<string> res;
    bool dfs(int i, vector<string>& nums, int max_length){
        if(i == max_length){
            if(find(nums.begin(), nums.end(), subset) == nums.end()){
                res.push_back(subset);
                return true;
            }
            return false;
        }

        subset.push_back('0');
        if(dfs(i+1,nums,max_length)) return true;
        subset.pop_back();

        subset.push_back('1');
        if(dfs(i+1,nums,max_length)) return true;
        subset.pop_back();

        return false;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int max_length = nums[0].length();
        // std::cout << max_length << std::endl;
        // std::cout << subset << std::endl;
        dfs(0,nums,max_length);
        // for(auto &c : res){
        //     std::cout << c << std::endl;
        // }
        return res[0];
    }
};