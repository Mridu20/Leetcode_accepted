class Solution {
public:
    int numWaterBottles(int bttl, int ex) {
        int total = 0;
        total += bttl;

        while(bttl >= ex){
            total += bttl/ex;
            bttl = bttl/ex + bttl%ex;
        }

        return total;
    }
};