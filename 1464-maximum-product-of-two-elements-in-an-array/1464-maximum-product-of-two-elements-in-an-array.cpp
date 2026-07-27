class Solution {
public:
    int maxProduct(vector<int>& a) {
        sort(a.begin(), a.end());

        int p1 = (a[0]-1)*(a[1]-1);
        int p2 = (a[a.size()-1]-1)*(a[a.size()-2]-1);

        return max(p1, p2);
    }
};