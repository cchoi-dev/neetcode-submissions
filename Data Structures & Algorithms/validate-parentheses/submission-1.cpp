class Solution {
public:
    bool isValid(string s) {
        // What's of note with brackets is that opening brackets can
        // be added at any time, but closed brackets must always match
        // the last one open bracket added at any given time.
        // Thus, we can use a stack.

        // Catch edge cases
        if (s.length() == 0) {
            return true;
        }

        stack<char> validStack;
        for (auto c : s) {
            if (isOpeningBracket(c)) {
                // printf("Opening bracket %c\n", c);
                validStack.push(c);
            }
            else {
                // printf("Closing bracket %c\n", c);
                // Closed bracket on an empty stack means no preceding open
                if (validStack.empty()) {
                    return false;
                }
                auto t = validStack.top();
                if (c == ']' && t != '[') {
                    return false;
                }
                else if (c == '}' && t != '{') {
                    return false;
                }
                else if (c == ')' && t != '(') {
                    return false;
                }
                validStack.pop();
            }
        }
        return (validStack.empty());
    }

    bool isOpeningBracket(char c) {
        if (c == '[' || c == '(' || c == '{') {
            return true;
        }
        return false;
    }
    
    bool isClosingBracket(char c) {
        if (c == ']' || c == ')' || c == '}') {
            return true;
        }
        return false;
    }
};
