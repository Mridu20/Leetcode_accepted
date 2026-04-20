class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt = 0;
        int n = g.size();
        int m = s.size();

        int i=0, j=0;
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());

        while(i<n && j<m){
            if(g[i]<= s[j]){
                cnt++;
                i++;
                j++;
            }
            else i++;
        }

        return cnt;
    }
};