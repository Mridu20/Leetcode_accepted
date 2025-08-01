class Solution {
public:
    bitset<32> reverseBitset(const bitset<32>& b) {
        bitset<32> reversed;
        for (int i = 0; i < 32; ++i) {
            reversed[i] = b[31 - i];
        }
        return reversed;
    }
    int reverseBits(int n) {
        int m;
        bitset<32> a = bitset<32>(n);
        bitset<32> b = reverseBitset(a);

        m = b.to_ulong();

        return m;
    }
};