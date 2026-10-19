class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        string s;
        int op1, op2, res;
        for (int i = 0; i < tokens.size(); i++) {
            s = tokens[i];
            if (s == "+") {
                op1 = nums.top();
                nums.pop();
                op2 = nums.top();
                nums.pop();
                res = op1 + op2;
                nums.push(res);
            }
            else if (s == "-") {
                op1 = nums.top();
                nums.pop();
                op2 = nums.top();
                nums.pop();
                res = op2 - op1;
                nums.push(res);
            }
            else if (s == "*") {
                op1 = nums.top();
                nums.pop();
                op2 = nums.top();
                nums.pop();
                res = op1 * op2;
                nums.push(res);
            }
            else if (s == "/") {
                op1 = nums.top();
                nums.pop();
                op2 = nums.top();
                nums.pop();
                res = op2 / op1;
                nums.push(res);
            }
            else {
                nums.push(stoi(s));
            }
        }
        if (!nums.empty()) return nums.top();
        return 0;
    }
};
