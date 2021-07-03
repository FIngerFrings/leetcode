/* 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。 */
//方法一：我也不知道应该叫什么方法
//思路：模拟平时计算两个数的步骤
class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size() - 1;
        int n = num2.size() - 1;
        int c = 0;
        string ans = "";
        while(m >= 0 || n >= 0 || c != 0){
            int i1 = (m >= 0) ? num1[m] - '0' : 0;
            int i2 = (n >= 0) ? num2[n] - '0' : 0;
            int result = i1 + i2 + c;
            ans += result % 10 + '0';
            //ans.push_back('0' + result % 10); //这句是正确的
            c = result / 10;
            --m;
            --n;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//同样是模拟计算，一开始的思路也确实是这个，但是之前没写出来.看pdf后写出来了
class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        if(m <= n){
            swap(m, n);
            swap(num1, num2);
        }
        int add = 0;
        string ans = "";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int i = 0; i < n; i++){
            int curr_sum = (num1[i] - '0') + (num2[i] - '0') + add;
            ans += (curr_sum % 10 + '0');
            add = curr_sum / 10;
        }
        for(int i = n; i < m; i++){
            int curr_sum = num1[i] - '0' + add;
            ans += (curr_sum % 10 + '0');
            add = curr_sum / 10;
        }
        if(add) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
