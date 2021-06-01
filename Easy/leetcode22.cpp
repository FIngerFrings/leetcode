/* 数字n代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且有效的括号组合。*/
//方法一：暴力法
//简述：将所有可能的组合都排列出来，然后判断是否符合条件
//问题的关键就在于怎么将所有组合都排列出来，其次如何判断一个组合是否符合条件
//首先是如何将所有组合都排列出来，首先需要明确的一点就是因为有n对括号，所以一个组合会有2n个字符，所有可能的组合为2^(2n)个，因为长度为n的序列就是在长度为n-1的序列前加一个'（'或'）'
//因此可以使用递归的方法，在这里每完成一种组合就判断它是否符合条件，如果符合就加入到数组中，不符合则直接跳过
//递归的方法具体看下面的代码注释
//其次就是如何判断一个字符串符合条件，因为符合条件的组合，其中的左括号和右括号个数一定相等，所以可以先初始化一个int类型的balance变量，检测到一个左括号就+1，检测到一个右括号就-1
//当在遍历字符串的过程中，如果balance小于0则一定不符合条件，因为符合条件的组合在遍历过程中左括号的个数一定大于等于右括号的个数，所以如果balance小于0肯定是不符合条件的
//说实话我想不出一种两对括号相交的情况，所以暂时认为只要最后balance=0且检测过程中balance不小于0就是满足条件的
class Solution {
public:
    bool valid(const string &current){      //在这里判断的时候最好加上const，以免修改current，而使用引用是为了提高效率
        int balance = 0;
        for(char str : current){
            if(str == '('){
                balance++;
            }
            else{
                balance--;
            }
            if(balance < 0){
                return false;
            }
        }
        return balance == 0;
    }

    void generate_all(string &current, int n, vector<string> &result){      //这里的current不用加const是因为要修改它
        if(n == current.size()){
            if(valid(current)){
                result.push_back(current);
            }
            return;
        }
      
        //以下就是递归的方法，实际上第一个字符串是全部都是左括号的情况，然后将最后一个字符弹出，再加一个右括号，之后再弹出
        //这时候最后一个位置没有字符，然后将倒数第二个字符换成右括号，之后再测试最后一个字符是左括号或右括号的情况
        //通过不断递归就可以得到全部的组合
        current += '(';
        generate_all(current, n, result);
        current.pop_back();
        current += ')';
        generate_all(current, n, result);
        current.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        generate_all(current, n*2, result);
        return result;
    }
};

//方法二：回溯法（虽然说是回溯法，但是我还是没有弄懂什么是回溯法。。。）
//思路：实际上是对方法一的改进，我们并不需要将所有组合都找出来，而是只要在序列保持有效时才添加左或右括号。我们可以通过跟踪到目前为止放置的左括号和右括号的数目来做到这一点
//如果左括号数量不大于n，我们添加一个左括号，如果右括号数量小于左括号，我们可以添加一个右括号
class Solution {
public:
    void backtacking(vector<string> &result, string &current, int left, int right, int n){
        if(current.size() == n*2){              //因为我们只有在序列有效时才添加括号，因此得到的所有组合都是有效的
            result.push_back(current);
            return;
        }
        
        //如果左括号数量小于n就添加左括号，直到左括号个数为n
        //之后再添加右括号，第一种情况就是前面n个全是左括号，后面n个全是右括号，然后递归就会将后面n个括号全部弹出
        //弹出后面n个右括号后，再将最后一个左括号弹出，同时添加一个右括号
        //之后因为左括号没到n个，因此还是会添加一个左括号，之后再全部添加左括号
        //之后不断递归，可以得到所有有效的序列
        if(left < n){                           
            current += '(';
            backtacking(result, current, left+1, right, n);
            current.pop_back();
        }

        if(right < left){
            current += ')';
            backtacking(result, current, left, right+1, n);
            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtacking(result, current, 0, 0, n);
        return result;
    }
};
//通过测试，方法二消耗的时间很少
