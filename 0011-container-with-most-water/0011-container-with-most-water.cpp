class Solution {
public:
    int maxArea(vector<int>& h) {
        int ar=0;

        int i=0;
        int j = h.size()-1;

        while(i < j){
            int l = min(h[i], h[j]);
            ar = max(ar, l*(j-i));
            if(h[i] < h[j]){
                i++;
            }
            else if(h[i] > h[j]){
                j--;
            }
            else j--;
        }

        return ar;
    }
};