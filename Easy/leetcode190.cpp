/* 颠倒给定的 32 位无符号整数的二进制位。*/
//方法一：逐位颠倒
//思路：就是遍历32位二进制的每一位，然后添加到ans中
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = n & 1;
        n >>= 1;
        int count = 0;
        while(++count < 32){
            ans <<= 1;
            ans += (n & 1);
            n >>= 1;
        }
        return ans;
    }
};

//同样是逐位颠倒，但是代码比较简洁
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i = 0; i < 32 && n > 0; i++){
            ans |= ((n & 1) << (31 - i));
            n >>= 1;
        }
        return ans;
    }
};
//其实这样好像会更好
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i = 0; i < 32; i++){
            ans <<= 1;
            ans += (n & 1);
            n >>= 1;
        }
        return ans;
    }
};

//方法二：分治
//思路：具体思路看官方解答
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        const uint32_t M1 = 0x55555555;
        const uint32_t M2 = 0x33333333;
        const uint32_t M3 = 0x0f0f0f0f;
        const uint32_t M4 = 0x00ff00ff;
        n = (n >> 1) & M1 | (M1 & n) << 1;
        n = (n >> 2) & M2 | (M2 & n) << 2;
        n = (n >> 4) & M3 | (M3 & n) << 4;
        n = (n >> 8) & M4 | (M4 & n) << 8;
        return n >> 16 | n << 16;
    }
};
