class Solution {
public:
    int largestPerimeter(vector<int>& n) {
        sort(n.begin(), n.end(), greater<int>());
        bool h = false;
        int peri;
        for(int i=0; i<=n.size()-3 && h == false; i++){
            if(n[i]+n[i+2]>n[i+1])h =true;
            else h = false;

            if(n[i+1]+n[i+2] > n[i])h = true;
            else h = false;

            if(h == true)peri = n[i+1]+n[i+2]+n[i];
        }

        if(h==false )return 0;
        
        return peri;
    }
};