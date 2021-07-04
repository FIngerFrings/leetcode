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


//方法二：快速选择寻找中位数
//思路：其实和上面一样，不过使用的是快速选择找到中位数，关于快速选择可以看leetcode215的官方解答
class Solution {
public:
    int getk(vector<int>& nums, int k, int l, int r){
        int q = randomPartition(nums, l, r);
        if(q == k){
            return nums[q];
        }
        else{
            return q < k ? getk(nums, k, q + 1, r) : getk(nums, k, l, q - 1);
        }
    }

    int randomPartition(vector<int>& nums, int l, int r){
        int i = rand() % (r - l + 1) + l;
        swap(nums[i], nums[r]);
        return Partition(nums, l, r);
    }

    int Partition(vector<int>& nums, int l, int r){
        int x = nums[r], i = l - 1;
        for(int j = l; j < r; j++){
            if(nums[j] <= x){
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[i+1], nums[r]);
        return i + 1;
    }

    int minMoves2(vector<int>& nums) {
        srand(time(0));
        int n = nums.size();
        int k = (n + 1) / 2 - 1;
        int x = getk(nums, k, 0, n - 1);
        long num = 0;
        for(int i = 0; i < n; i++){
            num += abs(nums[i] - x);
        }
        return num;
    }
};
