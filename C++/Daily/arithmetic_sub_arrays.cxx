#https://leetcode.com/problems/arithmetic-subarrays/description/
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        std::vector<bool> res;
        for(int i = 0; i<l.size(); i++){
            
            int begin = l[i];
            int end = r[i];
            // std::cout << "B: " << begin << end << std::endl;
            std::vector<int> new_vec(nums.begin()+begin,nums.begin()+end+1);
            std::sort(new_vec.begin(), new_vec.end());
            int gap = new_vec[1] - new_vec[0];
            res.push_back(true);
            // std::cout << "S: " << new_vec.size() << std::endl;
            for(int j=0; j<new_vec.size()-1; j++){
                // std::cout << "j: " << j << std::endl;
                // std::cout << new_vec[j+1]-new_vec[j] << std::endl;
                if(new_vec[j+1]-new_vec[j] != gap){
                    res.pop_back();
                    res.push_back(false);
                    break;
                }
            }

        }
        return res;
    }
};