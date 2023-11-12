//https://leetcode.com/problems/combination-sum/


// The trick seems to be for back tracking to break the problem down into a binary tree
// One case with a yes another case with a no
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates,target,0);

        return res;
        
    }

private:
    vector<vector<int>> res;
    vector<int> current;
    void dfs(vector<int>& cands, int target, int i){
        if(i >= cands.size() || target < 0){
            return;
        }
        if(target==0){
            res.push_back(current);
            return;
        }

        current.push_back(cands[i]);
        dfs(cands, target - cands[i], i);

        current.pop_back();

        dfs(cands, target, i+1);
    }
};