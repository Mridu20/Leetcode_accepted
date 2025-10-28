class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        sort(a.begin(), a.end());
        int cnt=1;
        int j=0;
        int n=a.size();

        for(int i=0; i<n; i++){
            while(i<n-1 && a[i]==a[i+1]){
                cnt++;
                i++;
            }
            // cout << cnt <<" ";
            if(cnt > n/3){
                a.emplace_back(a[i]);
                j++;
            }
            // cout<<j<<" ";
            cnt=1;
        }

            a.erase(a.begin(), a.begin()+n);

        return a;
    }
};