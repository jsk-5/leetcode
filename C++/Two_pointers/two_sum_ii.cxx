//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>::iterator begin = numbers.begin();
        vector<int>::iterator end = numbers.end();
        end--;
        vector<int> result;
        while(std::distance(begin, end) > 0){
            if ((*begin + *end) == target ){
                result = {static_cast<int>(begin-numbers.begin()+1), static_cast<int>(end-numbers.begin()+1)};
                return result;
            }
            else if ((*begin + *end) > target){
                end--;
            }
            else {
                begin++;
            }
        }
        return result;
    }
};