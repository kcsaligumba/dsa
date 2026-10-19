class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        unordered_map<char, char> closed = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (const char & c : s) {
            if (!closed.count(c)) {
                open.push(c);
                continue;
            }
            
            if (open.empty() || open.top() != closed[c]) {
                return false;
            }
            
            open.pop();
        }

        return open.empty();
    }
};
