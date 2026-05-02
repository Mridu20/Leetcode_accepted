class Solution {
public:
    int rotatedDigits(int n) {
        int cnt = 0;

        for (int i = 1; i <= n; i++) {
            int a = i;
            bool h = true;
            int c = 0;
            int pos = 1;
            while (a > 0 && h) {
                int b = a % 10;

                if ((b != 2 && b != 5) && (b != 6 && b != 9) &&
                    (b != 0 && b != 1 && b != 8)) {
                    h = false;
                } else {
                    int t;
                    if (b == 2)
                        t = 5;
                    else if (b == 5)
                        t = 2;
                    else if (b == 6)
                        t = 9;
                    else if (b == 9)
                        t = 6;
                    else
                        t = b;

                    c += t * pos;
                    pos *= 10;
                }

                a /= 10;
            }

            if (h && c != i)
                cnt++;
        }

        return cnt;
    }
};