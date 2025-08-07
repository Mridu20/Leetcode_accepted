class Solution {
public:
    int trailingZeroes(int n) {
        int cnt2=0, cnt5=0, cnt=0;

        for(int i=1; i<n+1; i++){
            int j=i;
            while(j%2 == 0){
                cnt2++;
                j/=2;
            }

            while(j%5 == 0){
                cnt5++;
                j /= 5;
            }
        }

        cnt = min(cnt2, cnt5);
        return cnt;
    }
};