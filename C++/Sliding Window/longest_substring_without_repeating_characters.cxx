//https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> prev_chars;
        int j = 0;
        int result = 0;
        for(int i = 0; i<s.size(); i++){

            while(prev_chars.find(s[i])!=prev_chars.end()){ // if we can find it in the set 
                prev_chars.erase(s[j]);
                j++;
            }
            if(prev_chars.find(s[i])==prev_chars.end()){
                prev_chars.insert(s[i]);
                
            } 
            


            result = max(result, i-j+1);
        }
        return result;
    }
};