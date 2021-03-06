/* 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
 * 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
 * 你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。
*/
//方法一，该方法算是双指针？？？总之就是定义两个指针分别指向数组的开头和结尾，然后交换两个元素，再分别++和--，直到l=r或l>r
//经过测试，该方法时间和内存消耗比较大
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1;
        while(l < r){
            swap(s[l], s[r]);
            ++l;
            --r;
        }
    }
};
//官方答案也是这种解法。。。
class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int l = 0, r = s.size()-1; l<=r; l++, r--){
            swap(s[l], s[r]);
        }
    }
};
