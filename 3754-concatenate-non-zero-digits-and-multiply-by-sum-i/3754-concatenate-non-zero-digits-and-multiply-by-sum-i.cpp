class Solution {
public:
    long long sumAndMultiply(int n) {
        int b = n;
        long long x = 0;
        long long sum = 0;

        while(b != 0){
            x*=10;
            x+= (b%10);
            sum += (b%10);

            b/=10;
        }

        long long m = 0;
        while(x != 0){
            while(x%10 == 0)x/=10;
            m*=10;
            m+=(x%10);

            x/=10;
        }

        return m*sum;

    }
};