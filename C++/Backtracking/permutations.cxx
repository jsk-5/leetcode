//https://leetcode.com/problems/permutations/submissions/
class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, vector<int> &v){
        if(nums.empty()){
            res.push_back(v);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            int erased = nums[i];
            v.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            dfs(nums,v);
            nums.insert(nums.begin()+i, erased);
            v.pop_back();
        }
        

    }
    

    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<int> v;
        dfs(nums, v);
        return res;
    }
};

