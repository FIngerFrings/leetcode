/* 给你一个整数 columnNumber ，返回它在 Excel 表中相对应的列名称。 */
//方法一：不知道什么方法的方法
//思路：略
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while(columnNumber){
            char a = (columnNumber - 1) % 26 + 'A';
            ans.push_back(a);
            columnNumber = (columnNumber - 1) / 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
