#https://leetcode.com/problems/diagonal-traverse-ii/editorial/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        // Used hint that row+col = same value for diagonals
        std::map<int,std::stack<int>> map;
        std::vector<int> res;
        
        int row_no = 0;
        for(auto& row : nums){
            int col_no = 0;
            for(auto& val : row){
                map[col_no+row_no].push(val);
                // std::cout << "D:" << col_no+row_no << " Val:" << val << std::endl; 
                col_no++;
            }

            row_no++;
        }
        // if we find max dim we can use an unordered map
        // int dims = max(nums.size(), nums)
        // for(int i = 0; i<2*(nums.size())-1 ; i++){
        //     // std::cout << i;
        //     for(; !map[i].empty() ; map[i].pop()){
        //         res.push_back(map[i].top());
        //         // std::cout << "Top: " << map[i].top();
        //     }
        // }
        for(auto& it : map){
            for(; !it.second.empty() ; it.second.pop()){
                res.push_back(it.second.top());
                // std::cout << "Top: " << map[i].top();
            }            
        }
        
        return res;
    }
};