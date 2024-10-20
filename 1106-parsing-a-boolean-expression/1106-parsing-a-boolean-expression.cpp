class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;  // Stack to store characters of the expression

        for (char ch : expression) {
            if (ch == ',' || ch == '(') {
                continue;  // Ignore commas and opening parentheses
            } 
            else if (ch == ')') {
                // We've encountered a closing parenthesis, evaluate the sub-expression
                vector<char> subExpr;
                
                // Pop all operands (t, f) until we reach an operator
                while (stk.top() == 't' || stk.top() == 'f') {
                    subExpr.push_back(stk.top());
                    stk.pop();
                }
                
                // Pop the operator
                char op = stk.top();
                stk.pop();
                
                // Evaluate the sub-expression based on the operator
                char result = evaluateSubExpr(op, subExpr);
                
                // Push the result back onto the stack
                stk.push(result);
            } 
            else {
                // Push operands (t, f) and operators (!, &, |) onto the stack
                stk.push(ch);
            }
        }
        
        // The final result will be the top of the stack
        return stk.top() == 't';
    }

private:
    // Function to evaluate the sub-expression based on the operator
    char evaluateSubExpr(char op, vector<char>& subExpr) {
        if (op == '!') {
            // NOT operation, negates a single value
            return subExpr[0] == 't' ? 'f' : 't';
        } 
        else if (op == '&') {
            // AND operation, all values must be true
            for (char c : subExpr) {
                if (c == 'f') {
                    return 'f';
                }
            }
            return 't';
        } 
        else if (op == '|') {
            // OR operation, at least one value must be true
            for (char c : subExpr) {
                if (c == 't') {
                    return 't';
                }
            }
            return 'f';
        }
        return 'f';  // Default case (shouldn't occur)
    }
};
