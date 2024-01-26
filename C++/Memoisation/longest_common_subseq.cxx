#https://leetcode.com/problems/longest-common-subsequence/?envType=daily-question&envId=2024-01-25
#https://ics.uci.edu/~eppstein/161/960229.html
class Solution {
public:

    int helper(auto m, auto n, string &text1, string &text2, vector<vector<int>> &arr){
        // std::cout << m << "," << n << std::endl;
        if( m == text1.size() || n == text2.size()){
                // arr[m][n] = 0;
                return 0;
            } 
        if(arr[m][n] < 0){
            
            if (text1[m] == text2[n]){
                arr[m][n] = 1 + helper(m+1, n+1, text1, text2, arr);

            }
            else{
                arr[m][n] = max(helper(m+1, n, text1, text2, arr), helper(m, n+1, text1, text2, arr));
            } 
        }
        return arr[m][n];

    }
    int longestCommonSubsequence(string text1, string text2) {
        auto m = text1.size();
        auto n = text2.size();
        
        vector<vector<int>> subproblems;

        for(int i=0; i<m; i++){
            vector<int> subarr;
            for(int j=0; j<n; j++){
                subarr.push_back(-1);
            }
            subproblems.push_back(subarr);
        }


        return helper(0, 0, text1, text2, subproblems);
    }
};