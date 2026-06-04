class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int wave = 0;
        for(int i=num1; i<= num2; i++){
            int b = i;
            vector<int> a;
            while(b > 0){
                a.push_back(b%10);
                b/=10;
            }

            int m = a.size();
            for(int j=1; j<m-1; j++){
                if((a[j]>a[j-1] && a[j]>a[j+1])|| (a[j]<a[j-1] && a[j]<a[j+1])) wave++;
            }
        }

        return wave;
    }
};