class Solution {
public:
    bool checkValidString(string s) {
        int mn = 0, mx = 0;

        for (char c : s) {
            if (c == '(') {
                mn++;
                mx++;
            } 
            else if (c == ')') {
                mn = max(0, mn - 1); 
                mx--;
                if (mx < 0) return false; 
            } 
            else {
                mn = max(0, mn - 1);
                mx++;                
            }
        }

        return mn == 0; 
    }
};