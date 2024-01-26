#https://leetcode.com/problems/out-of-boundary-paths/?envType=daily-question&envId=2024-01-26
class Solution {
public:
    int helper(int m, int n, int maxMove, int startRow, int startColumn, vector<vector<vector<int>>> & subproblems){
        int M = 1e9 + 7;
        
        if(startRow < 0 || startColumn < 0 || startRow > m-1 || startColumn > n-1) return 1;
        if(maxMove == 0 ) return 0;
        if(subproblems[startRow][startColumn][maxMove] != -1) return subproblems[startRow][startColumn][maxMove];
        
        int u=0,d=0,l=0,r=0;

        u=helper(m, n, maxMove-1, startRow-1, startColumn, subproblems);
        d=helper(m, n, maxMove-1, startRow+1, startColumn, subproblems);
        l=helper(m, n, maxMove-1, startRow, startColumn-1, subproblems);
        r=helper(m, n, maxMove-1, startRow, startColumn+1, subproblems);
        
        return subproblems[startRow][startColumn][maxMove] = ((u+d)%M + (l+r)%M)%M;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> subproblems;
        subproblems = vector<vector<vector<int>>>(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
      
        return helper(m, n, maxMove, startRow, startColumn, subproblems);
    }
};