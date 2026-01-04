class Solution {
public:
    int sumFourDivisors(vector<int>& a) {
        int ans=0;
        for(int i=0; i<a.size(); i++){
            int cnt=0;
            int sum = 0;
            for(int j=1; j*j <= a[i]; j++){
                if(a[i]%j ==0 && a[i]/j != j){
                    cnt+=2;
                    sum += j;
                    sum += a[i]/j;
                }
                else if(a[i]%j ==0 && a[i]/j == j){
                    cnt++;
                    sum += j;
                }
            }

            if(cnt == 4)ans += sum;
        }

        return ans;
    }
};