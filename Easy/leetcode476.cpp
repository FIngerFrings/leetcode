//方法一：用数组存放二进制数
//思路：就是用数组存放二进制数，离谱
class Solution {
public:
    int findComplement(int num) {
        vector<int> ans(31);
        int k = 0;
        int p = 1;
        int ret = 0;
        while(num){
            ans[k++] = num % 2;
            num /= 2;
        }

        for(int i = 0; i < k; i++){
            if(ans[i] == 0){
                ans[i] = 1;
            }
            else{
                ans[i] = 0;
            }
            ret += p * ans[i];
            p <<= 1;
        }

        return ret;

    }
};
