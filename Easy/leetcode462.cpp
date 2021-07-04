/* 
 * 给定一个非空整数数组，找到使所有数组元素相等所需的最小移动数，其中每次移动可将选定的一个元素加1或减1。 您可以假设数组的长度最多为10000。
 */
//方法一：暴力法
//思路：依次将数组中的每个数作为基准，让其他元素变成它，然后计算所需要的步骤，计算其中的最小值，但是超时了
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long minnum = INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            long num = 0;
            for(int j = 0; j < n; j++){
                if(i == j)  continue;
                num += abs(nums[i] - nums[j]);
            }
            minnum = min(minnum, num);
        }
        return minnum;
    }
};

//方法二：使用排序寻找中位数
//思路：直接使用性质：当所有的数都变成这个数组中的中位数时所需步骤最少
//这里使用排序得到中位数
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int x = nums[(n+1)/2 - 1];
        int num = 0;
        for(int i = 0; i < n; i++){
            num += abs(nums[i] - x);
        }
        return num;
    }
};
