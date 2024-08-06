//https://leetcode.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for(vector<int>::iterator slow_pointer = nums.begin(); slow_pointer < nums.end(); slow_pointer++){
            vector<int>::iterator begin = slow_pointer+1;
            vector<int>::iterator end = nums.end()-1;

            while(distance(begin, end)>0){
                // cout << *begin << " " << *end << " " << *slow_pointer << endl;
                if(*begin + *end + *slow_pointer < 0){
                    begin++;
                } else if(*begin + *end + *slow_pointer > 0){
                    end--;
                } else {
                    vector<int> res = {*begin, *end, *slow_pointer};
                    result.push_back(res);
                    while(distance(begin, end)>0 && *begin == res[0]) begin++;
                    while(distance(begin, end)>0 && *end == res[1]) end--;
                }
            }
            while(slow_pointer+1<nums.end()&& *slow_pointer == *(slow_pointer+1)){
                // cout << "inc slow" << endl;
                slow_pointer++;
            }
        }
        return result;
    }
};