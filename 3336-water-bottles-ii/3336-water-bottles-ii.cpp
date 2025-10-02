class Solution {
public:
    int maxBottlesDrunk(int bttl, int ex) {
        int total = 0;
        total += bttl;
        int emp = bttl;
        bttl =0; 

        while(emp >= ex){
            emp -= ex;
            ex++;
            total++;
            emp++;
        }

        return total;
    }
};