class Solution {
public:
    string winningPlayer(int x, int y) {
        int a = y/4;
        int ans = min(a, x);

        if(ans%2 == 1)return "Alice";
        else return "Bob";
    }
};