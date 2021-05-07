/* leetcode162 寻找峰值*/
/* 峰值元素是指其值大于左右相邻值的元素。给你一个输入数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。
 * 你可以假设 nums[-1] = nums[n] = -∞ 。
 */
//该方法实际上就是遍历数组中所有元素，然后进行比较，需要注意的地方是有个条件是相邻两个元素不相等，这是我在做第一遍的时候没注意到的
//为什么会只需要比较当前元素和下一个元素的值呢？核心就是相邻元素不相等
//如果对于降序排列的数组，首元素就符合条件，且首元素大于下一个元素，可以直接返回
//如果是升序排列的，那就是会循环到最后一个元素，直接返回n-1
//如果峰值在中间，则峰值的它肯定大于前面一个元素，因为如果小于前面一个元素，那么它必定不会到这里
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            if(nums[i] > nums[i+1]){
                return i;
            }
        }
        return n-1;
    }
};

/* 
 * 我们可以将 numsnums 数组中的任何给定序列视为交替的升序和降序序列。通过利用这一点，以及“可以返回任何一个峰作为结果”的要求，我们可以利用二分查找来找到所需的峰值元素。
 * 在简单的二分查找中，我们处理的是一个有序数列，并通过在每一步减少搜索空间来找到所需要的数字。在本例中，我们对二分查找进行一点修改。首先从数组 numsnums 中找到中间的元素 midmid。
 * 若该元素恰好位于降序序列或者一个局部下降坡度中（通过将 nums[i]nums[i] 与右侧比较判断)，则说明峰值会在本元素的左边。于是，我们将搜索空间缩小为 midmid 的左边(包括其本身)，
 * 并在左侧子数组上重复上述过程。若该元素恰好位于升序序列或者一个局部上升坡度中（通过将 nums[i]nums[i] 与右侧比较判断)，则说明峰值会在本元素的右边。
 * 于是，我们将搜索空间缩小为 midmid 的右边，并在右侧子数组上重复上述过程。就这样，我们不断地缩小搜索空间，直到搜索空间中只有一个元素，该元素即为峰值元素。
 * 为了理解本方法的原理，让我们再次讨论前文提到的全部三种情况。
 */
//能这么做的核心是因为可以返回任何一个峰值
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid;
        while(l < r){       //这里换成l!=r也是一样的
            mid = (l + r) / 2;
            if(nums[mid] > nums[mid+1]){
                r = mid;
            }
            else{
                l = mid + 1;    //如果nums[mid]<nums[mid+1]，那么mid肯定不是峰值
            }
        }
        return l;
    }
};

//上面使用的是迭代的方法，还可以用递归的方法实现，原理相同
class Solution {
public:
    int bisearch(vector<int>& nums, int l, int r){
        int mid = (l + r) / 2;
        if(l == r){
            return l;
        }
        if(nums[mid] > nums[mid+1]){
            return bisearch(nums, l, mid);
        }
        else{
            return bisearch(nums, mid+1, r);
        }
    }

    int findPeakElement(vector<int>& nums) {
        return bisearch(nums, 0, nums.size()-1);
    }
};
