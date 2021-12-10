/*
 * 在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
 * 你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
 * 如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。
 */
//方法一：暴力
//思路：尝试从所有点开始
//超时
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i = 0; i < n; i++){
            if(gas[i] >= cost[i]){
                int num = 0;
                for(int j = 0; j < n; j++){
                    num += gas[(i+j)%n];
                    num -= cost[(i+j)%n];
                    if(num < 0) break;
                    if(j == n - 1){
                        return i;
                    }
                }
            }
        }
        return -1;
    }
};

//代码随想录暴力
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i = 0; i < n; i++){
            int rest = gas[i] - cost[i];
            int index = (i + 1) % n;
            while(rest > 0 && index != i){    //不太认可这里为什么不能等于0
                rest += gas[index] - cost[index];
                index = (index + 1) % n;
            }
            if(rest >= 0 && index == i) return i;
        }
        return -1;
    }
};

//方法二：贪心？？？
//这个贪心不是特别好理解。。。
//实际上就是计算从0出发最缺油的一部分，然后从0的上一个加油站开始计算，也就是最后一个加油站，如果从这个加油站出发能填平这个最小值，则代表从这个加油站出发能走完一圈
//仔细想想还是能想通的
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int curSum = 0;
        int minSum = INT_MAX;
        for(int i = 0; i < n; i++){
            curSum += gas[i] - cost[i];
            if(curSum < minSum){
                minSum = curSum;
            }
        }

        if(curSum < 0)  return -1;
        if(minSum >= 0) return 0;

        for(int i = n - 1; i >= 0; i--){
            int rest = gas[i] - cost[i];
            minSum += rest;
            if(minSum >= 0){
                return i;
            }
        }
        return -1;
    }
};

//贪心
//思路：首先如果总油量减去总消耗大于等于零那么一定可以跑完一圈，说明各个站点的加油站 剩油量rest[i]相加一定是大于等于零的。
//i从0开始累加rest[i]，和记为curSum，一旦curSum小于零，说明[0, i]区间都不能作为起始位置，起始位置从i+1算起，再从0计算curSum。
//那么局部最优：当前累加rest[j]的和curSum一旦小于0，起始位置至少要是j+1，因为从j开始一定不行。全局最优：找到可以跑一圈的起始位置。
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int totalSum = 0;
        int starti = 0;
        for(int i = 0; i < gas.size(); i++){
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if(curSum < 0){
                starti = i + 1;
                curSum = 0;
            }
        }
        if(totalSum < 0)    return -1;
        return starti;
    }
};
