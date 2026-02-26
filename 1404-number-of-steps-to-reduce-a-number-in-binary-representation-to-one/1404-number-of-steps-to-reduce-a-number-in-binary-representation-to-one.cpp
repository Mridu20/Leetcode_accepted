class Solution {
public:
    int numSteps(string s) {
        int cnt = 0;
        int carry = 0;

        for(int i = s.size() - 1; i > 0; i--) {

            if((s[i] - '0' + carry) % 2 == 0) {
                cnt += 1;
            }
            else {
                cnt += 2;
                carry = 1;
            }
        }

        return cnt + carry;
    }
};