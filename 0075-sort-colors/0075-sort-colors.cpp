class Solution {
public:
    void sortColors(vector<int>& n) {
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;

        for(int i=0; i<n.size(); i++){
            if(n[i] == 0)cnt0++;
            else if(n[i] == 1)cnt1++;
            else cnt2++;
        }

        for(int i=0; i<n.size(); i++){
            if(i < cnt0)n[i]=0;
            else if(i>= cnt0 && i < cnt0+cnt1)n[i]=1;
            else n[i]=2;
        }
    }
};