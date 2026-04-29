#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto &c: s) {
            if (st.empty() || (c == '(' || c == '{' || c == '[')) {
                st.push(c);
                continue;
            }

            char top = st.top();
            if ((c == ')' && top != '(')
                || (c == '}' && top != '{')
                || (c == ']' && top != '[')) {
                return false;
            }
            st.pop();
        }
        return st.empty();
    }
};

int main() {
    Solution().isValid("(]");
    return 0;
}
