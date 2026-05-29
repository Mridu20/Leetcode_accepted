class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a1, vector<int>& a2) {
        
        unordered_map<int, int> mp;
        stack<int> st;

        for(int i = a2.size() - 1; i >= 0; i--) {

            while(!st.empty() && st.top() <= a2[i]) {
                st.pop();
            }

            if(st.empty()) {
                mp[a2[i]] = -1;
            }
            else {
                mp[a2[i]] = st.top();
            }

            st.push(a2[i]);
        }

        vector<int> ans;

        for(int x : a1) {
            ans.push_back(mp[x]);
        }

        return ans;
    }
};