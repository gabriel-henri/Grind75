/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false


*/

#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> pilha;

        for(char item: s){
            if(item == '(' || item == '{' || item == '['){
                pilha.push(item);
            }else{
                if(pilha.empty()){
                    return false;
                }
                else if(item == ')'){
                    if(pilha.top() == '('){
                        pilha.pop();
                    }else{
                        return false;
                    }
                }
                else if(item == '}'){
                    if(pilha.top() == '{'){
                        pilha.pop();
                    }else{
                        return false;
                    }
                }
                else if(item == ']'){
                    if(pilha.top() == '['){
                        pilha.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        return pilha.empty();
    }
};