/*
 * 在柠檬水摊上，每一杯柠檬水的售价为 5 美元。顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。
 * 每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。
 * 注意，一开始你手头没有任何零钱。
 * 给你一个整数数组 bills ，其中 bills[i] 是第 i 位顾客付的账。如果你能给每位顾客正确找零，返回 true ，否则返回 false 。
 */
//方法一：贪心
//思路：5美元则直接收，10美元则找零5美元，20美元则优先找零10+5美元，否则找零5+5+5美元
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> hash;
        for(int bill : bills){
            if(bill == 5) hash[5]++;
            else if(bill == 10){
                if(hash[5] > 0){
                    hash[5]--;
                    hash[10]++;
                }
                else return false;
            }
            else{
                if(hash[10] > 0 && hash[5] > 0){
                    hash[10]--;
                    hash[5]--;
                    hash[20]++;
                }
                else if(hash[5] >= 3){
                    hash[5] -= 3;
                    hash[20]++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
//其实可以不用哈希表，只用两个变量five和ten记录就行
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(int bill : bills){
            if(bill == 5) five++;
            else if(bill == 10){
                if(five > 0){
                    five--;
                    ten++;
                }
                else return false;
            }
            else{
                if(ten > 0 && five > 0){
                    ten--;
                    five--;
                }
                else if(five >= 3){
                    five -= 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
