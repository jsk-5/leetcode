//https://neetcode.io/problems/is-palindrome
class Solution {
public:
    bool isPalindrome(string s) {
        string::iterator begin = s.begin();
        string::reverse_iterator end = s.rbegin();
        bool one_alphanum_flag = false;
        while(std::distance(string::reverse_iterator{begin}, end) < 0){
            
            if (one_alphanum_flag == false){
                if(isalnum(*begin) || isalnum(*end)){
                    one_alphanum_flag = true;
                }
            }
            while(!isalnum(*begin)){
                begin++;
                if(begin == s.end() && one_alphanum_flag == false){
                    return true;
                }
                else if(begin == s.end()){
                    return false;
                }
            }
            while(!isalnum(*end)){
                end++;
                if(end == s.rend() && one_alphanum_flag == false){
                    return true;
                }
                else if(end == s.rend()){
                    return false;
                }
            }
            if(tolower(*begin) != tolower(*end)){
                return false;
            }
            begin++;
            end++;
        }
        return true;
    }
};