class Solution {
public:
    int bestClosingTime(string a) {
        vector<int> y, n;
        int cntn=0, cnty=0;

        for(int i=0; i<a.size(); i++){
            if(a[i]=='N')cntn++;
            if(a[i]=='Y')cnty++;

            n.push_back(cntn);
            y.push_back(cnty);
        }

        int ans=cnty;
        int indx = 0;
        for(int i=0; i<a.size(); i++){
            int pen = n[i] + cnty-y[i];
            if(pen < ans){
                ans = pen;
                indx = i+1;
            }
        }

        int pen = cntn;
        if(pen < ans){
                indx = a.size();
            }

        return indx;
    }
};