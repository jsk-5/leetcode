// https://leetcode.com/problems/minimum-window-substring/
// remember s.substr
// and be careful with calling substr every time or we can cause memory exceeded
class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length()) return "";
        unordered_map<char, int> required;
        unordered_map<char, int> window;
        int char_count = 0;
        for(auto& c: t){
            required[c]++;
        }
        int need_char_count = required.size();
        int i = 0;
        int j = 0;
        int min_len = INT_MAX;
        int start = 0;
        string min_substring = "";

        while(j<s.size()){
            window[s[j]]++;
            if(required.find(s[j])!=required.end() && window[s[j]]==required[s[j]]){
                char_count++;
            }
            while(char_count==need_char_count){
                
                if(j-i+1 < min_len){
                    start = i;
                    min_len = j-i+1;
                }
                window[s[i]]--;
                if(required.find(s[i])!=required.end() && window[s[i]]<required[s[i]]){
                    char_count--;
                }
                i++;
            }
            j++;
        }
        return min_len == INT_MAX ? "" : s.substr(start,min_len);

    }
};
};