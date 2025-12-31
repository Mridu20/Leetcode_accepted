class Solution {
public:
    string smallestNumber(string p) {
    string result;
    stack<int> st;
    int n = p.size();

    for (int i = 0; i <= n; i++) {
        st.push(i + 1);

        if (i == n || p[i] == 'I') {
            while (!st.empty()) {
                result += char('0' + st.top());
                st.pop();
            }
        }
    }
    return result;
}

};