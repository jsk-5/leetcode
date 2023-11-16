#https://leetcode.com/problems/subsets-ii/submissions/
class Solution {
public:
    vector<vector<int>> res;
    vector<int> subset;
    set<vector<int>> used;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(0,nums);

        return res;
    }

    void dfs(int i, vector<int>& nums){
        if (i >= nums.size()){
            if(used.find(subset) == used.end())
            {
                used.insert(subset);
                res.push_back(subset);
                return;
            }
            return;
            
        }

        subset.push_back(nums[i]);
        dfs(i+1,nums);

        subset.pop_back();
        dfs(i+1,nums);
    }
};