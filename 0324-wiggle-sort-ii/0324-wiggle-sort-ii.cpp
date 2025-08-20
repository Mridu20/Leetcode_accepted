class Solution {
public:
    void wiggleSort(vector<int>& n) {
        vector<int> n1, n2;
        vector<int> ans;

        sort(n.begin(), n.end());
        int mid = (n.size() + 1) / 2;
        n1.assign(n.begin(), n.begin() + mid); 
        n2.assign(n.begin() + mid, n.end());   

        reverse(n1.begin(), n1.end()); 
        reverse(n2.begin(), n2.end());

        int i = 0, j = 0;
        for (int k = 0; k < n.size(); k++) {
            if (k % 2 == 0) {
                ans.push_back(n1[i++]);
            } else {
                ans.push_back(n2[j++]);
            }
        }

        n = ans;
    }
};