//https://leetcode.com/problems/evaluate-reverse-polish-notation/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> symbols;
        int result;

        bool first_result = true;
        for(auto& c : tokens){
            string s = c;

            if(c=="+" || c=="-" || c=="*" || c=="/"){
                int num1;
                num1 = symbols.top();
                symbols.pop();
                int num2;
                num2 = symbols.top();
                symbols.pop();
                if(c=="+"){
                    result = num1+num2;
                } else if(c=="-"){
                    result = num2-num1;
                } else if(c=="/"){
                    result = num2/num1;
                } else if(c=="*"){
                    result = num1*num2;   
                } 
                symbols.push(result);
            }
            else {
                symbols.push(stoi(c));
            }
        }
        return symbols.top();
    }
};