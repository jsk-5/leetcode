// https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        if(s.length() % 2 == 1) return false;

        for(auto& c : s){
            // cout << c;
            if(c == '(' || c== '{' || c == '['){
                st.push(c);
            } else {
                if(!st.empty()){
                    if(st.top() == '(' && c == ')'){ st.pop();}
                    else if(st.top() == '{' && c == '}'){ st.pop();}
                    else if(st.top() == '[' && c == ']'){ st.pop();}
                    else if(st.top() != c) { return false;}
                } else return false;
            }
        }
        return st.empty();
    } 
};