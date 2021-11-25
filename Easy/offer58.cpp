/* 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。 */
//方法一：模拟
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string temp = s.substr(0, n);
        int slow = 0;
        for(int i = n; i < s.size(); i++){
            s[slow++] = s[i];
        }
        for(int i = 0; i < temp.size(); i++){
            s[slow++] = temp[i];
        }
        return s;
    }
};

//方法二：局部反转 + 整体反转
//思路：先反转前n个字符，然后反转剩下的字符，然后整体反转
class Solution {
public:
    void MySwap(string &s, int l, int r){
        while(l < r){
            swap(s[l], s[r]);
            ++l;
            --r;
        }
    }

    string reverseLeftWords(string s, int n) {
        MySwap(s, 0, n - 1);
        MySwap(s, n, s.size() - 1);
        MySwap(s, 0, s.size() - 1);
        return s;
    }
};
