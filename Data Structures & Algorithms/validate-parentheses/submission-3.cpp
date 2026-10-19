class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for (const char & c : s) {
            if (c == '(' || c == '{' || c == '[') {
                brackets.push(c);
                continue;
            }
            
            if (c == ')') {
                if (brackets.empty() || brackets.top() != '(') {
                    return false;
                }

                brackets.pop();
                continue;
            }
            if (c == '}') {
                if (brackets.empty() || brackets.top() != '{') {
                    return false;
                }

                brackets.pop();
                continue;
            }
            if (c == ']') {
                if (brackets.empty() || brackets.top() != '[') {
                    return false;
                }

                brackets.pop();
                continue;
            }
        }

        return brackets.empty();
    }
};
