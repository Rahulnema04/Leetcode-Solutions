class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();

        for (int i = 0; i < n; i++) {
            string ch = tokens[i];

            if (!(ch == "+" || ch == "-" || ch == "*" || ch == "/")) {
                st.push(stoi(ch));
            }
            else if (ch == "+") {
                int E2 = st.top(); st.pop();
                int E1 = st.top(); st.pop();
                st.push(E1 + E2);
            }
            else if (ch == "-") {
                int E2 = st.top(); st.pop();
                int E1 = st.top(); st.pop();
                st.push(E1 - E2);
            }
            else if (ch == "*") {
                int E2 = st.top(); st.pop();
                int E1 = st.top(); st.pop();
                st.push(E1 * E2);
            }
            else if (ch == "/") {
                int E2 = st.top(); st.pop();
                int E1 = st.top(); st.pop();
                st.push(E1 / E2);
            }
        }

        return st.top();
    }
};