//https://leetcode.com/problems/permutation-in-string/
// Remember the -'a' trick for when theres all upper or lowercase letters
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> chars_count;
        // {s1_char : char_occurences}
        for(int i = 0; i<s1.size(); i++){
            if(chars_count.find(s1[i])==chars_count.end()){
                chars_count[s1[i]] = 1;
            } else {
                chars_count[s1[i]]++;
            }
        }

        int fixed_window_size = s1.size();

        int left = 0;
        int right = fixed_window_size-1;

        for(int right=0; right<s2.size(); right++){
            // keep fixed window size
            // check if chars_count is all 0's
            if(chars_count.find(s2[right])==chars_count.end()){
                chars_count[s2[right]] = -1;
            } else {
                chars_count[s2[right]]--;
            }

            if(right - left + 1 > fixed_window_size){
                chars_count[s2[left]]++;
                left++;
            }

            if(checkPermutation(chars_count)) return true;
        }

        return false;
        
    }

private:
    bool checkPermutation(unordered_map<char,int> chars_count){
        for(auto& [key, value]: chars_count){
            if(value!=0) return false;
        }
        
        return true;
    }
};