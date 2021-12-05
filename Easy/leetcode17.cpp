/*
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 */
//方法一：回溯
//思路：略
class Solution {
public:
    vector<string> ans;
    string path;

    void backtracking(string digits, int cur){
        if(path.size() == digits.size()){
            ans.push_back(path);
            return;
        }

        int num  = digits[cur] - '2';
        char start;
        if(num <= 5){
            start = 'a' + num * 3;
        }
        else{
            start = 'a' + num * 3 + 1;
        }

        int end;
        if(num == 5 || num == 7){
            end = 4;
        }
        else{
            end = 3;
        }

        for(int i = 0; i < end; i++){
            path += start + i;
            backtracking(digits, cur + 1);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)  return {};
        backtracking(digits, 0);
        return ans;
    }
};

//代码随想录更好的回溯
class Solution {
public:
    vector<string> ans;
    string path;
    vector<string> map{
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    void backtracking(string digits, int cur){
        if(path.size() == digits.size()){
            ans.push_back(path);
            return;
        }

        int index = digits[cur] - '0';
        string letter = map[index];

        for(int i = 0; i < letter.size(); i++){
            path += letter[i];
            backtracking(digits, cur + 1);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)  return {};
        backtracking(digits, 0);
        return ans;
    }
};
