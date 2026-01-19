class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        int n = a.size(); 

        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;

        for (int i = 0; i < n; i++) {
            
            if (cnt1 == 0 && el2 != a[i]) {
                cnt1 = 1;
                el1 = a[i]; 
            }
            else if (cnt2 == 0 && el1 != a[i]) {
                cnt2 = 1;
                el2 = a[i]; 
            } 
            else if (a[i] == el1) {
                cnt1++;
            } 
            else if (a[i] == el2) {
                cnt2++; 
            } 
            else {
                cnt1--; 
                cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0; 
        
        for (int i = 0; i < n; i++) {
            if (a[i] == el1) {
                cnt1++; 
            }
            if (a[i] == el2) {
                cnt2++;
            }
        }

        int mn = n / 3 + 1;
        
        vector<int> ans; 
        if (cnt1 >= mn) {
            ans.push_back(el1);
        }
        if (cnt2 >= mn && el1 != el2) {
            ans.push_back(el2); 
        }
        return ans;
    }
};