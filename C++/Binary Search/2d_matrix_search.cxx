//https://leetcode.com/problems/search-a-2d-matrix/submissions/1406463313/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int top = matrix.size() * matrix[0].size()-1;
        int bottom = 0;

        // cout << top << "," << top / cols << "," << top % cols << endl;

        while(bottom<=top){
            int middle = (top-bottom) / 2 + bottom;
            if(matrix[middle/cols][middle%cols] < target){
                bottom = middle + 1;
            } else if (matrix[middle/cols][middle%cols] > target){
                top = middle - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};