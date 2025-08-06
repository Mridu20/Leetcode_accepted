class Solution {
public:
    bool canJump(vector<int>& n) {
        bool h = true;
        int k = n.size()-1;

        for(int i=n.size()-2; i>=0; i--){
            if(k - i <= n[i])k=i;
        }

        if(k==0)h=true;
        else h = false;

        return h;
    }
};