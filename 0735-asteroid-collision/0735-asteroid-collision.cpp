class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;

        for (int x : a) {

            bool h = false;

            while (!st.empty() && st.top() > 0 && x < 0) {

                if (st.top() < -x) {
                    st.pop();
                }
                else if (st.top() == -x) {
                    st.pop();
                    h = true;
                    break;
                }
                else {
                    h = true;
                    break;
                }
            }

            if (!h)
                st.push(x);
        }

        vector<int> ans(st.size());

        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};