class Solution {
public:
    bool lemonadeChange(vector<int>& a) {
        int cnt5 = 0, cnt10=0;

        for(int i=0; i<a.size(); i++){
            if(a[i]==10){
                cout << 0 <<" ";
                if(cnt5 == 0)return false;
                else cnt5--;
                cnt10++;
            }
            else if(a[i]==20){
                cout << 1 <<" ";
                if(cnt5 >= 1 && cnt10 >= 1){
                    cnt5--;
                    cnt10--;
                }
                else if(cnt5 >= 3) cnt5 -=3;
                else return false;
            }
            else cnt5++;

            // if(a[i]==5)cnt5++;
            // else if(a[i]==10)cnt10++;
            // else cnt20++;
        }
        return true;
    }
};