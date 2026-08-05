class Solution {
public:
    bool isValid(string s) {
        stack<char> c;

        for(int i = 0; i< s.length(); i++){
            
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){  //opening
                c.push(s[i]);
            }
            else{//closing
                if(c.size() == 0){
                    return false;
                }
                if((c.top() == '(' && s[i] == ')') || (c.top() == '{' && s[i] == '}') || (c.top() == '['&& s[i] == ']')){
                    c.pop();
                }
                else{//no match
                    return false;
                }
            }
            
            
        }

        return c.size() == 0;
    
    }
};