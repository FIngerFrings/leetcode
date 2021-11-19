/*
*给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
*不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
*元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
*/
//我的答案，方法同283，只是283中是将0移到后面，这里指定了val，所以只要加一个判断就行
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int left = 0, right = 0;
        int count = 0;
        while(right < n){
            if(nums[right] != val){
                swap(nums[left], nums[right]);
                left++;
            }
            else{
                count++;
            }
            right++;
        }
        return n - count;
    }
};
//我的方法可以改进，实际上新的数组长度就是left的值
//该方法空间复杂度很小，但是耗时较大（为啥较高我也不知道）
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int left = 0, right = 0;
        while(right < n){
            if(nums[right] != val){
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
        return left;
    }
};
//耗时较大估计是使用了swap，实际上这道题不需要使用swap，因为它并没有对数组中超过新长度的数做要求，所以可以直接将right的值赋给left，但这样不知道为什么所需空间变大了
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int left = 0, right = 0;
        while(right < n){
            if(nums[right] != val){
                nums[left] = nums[right];
                left++;
            }
            right++;
        }
        return left;
    }
};
//上面这样做耗时仍然比较高，实际上可以将while改成for，如下所示，这样就不需要提前定义一个right了
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int left = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != val){
                nums[left] = nums[i];
                left++;
            }
        }
        return left;
    }
};
//这实际上就是答案了，虽然耗时比较少但空间消耗变多了
//针对目标数值比较少的数组，实际上没有必要移动很多元素，所以下面的做法就将最后要删除的元素与最后一个元素交换，
//同时将n-1，这样就不会检查最后一个元素了，但有可能原本的最后一个元素也是要删除的，所以当交换过后就不会i进行+1操作，这也是选择while循环的原因
//这种方法在283题中我也曾想过，但不知道怎样重复检查一个选项，当时使用的是for循环，所以最后选择将i进行-1操作，所以实际上可以使用while循环来解决这个问题
//这样就不会每次循环都+1
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0;
        while(i < n){
            if(nums[i] == val){
                nums[i] = nums[n-1];
                n--;
            }
            else{
                i++;
            }
        }
        return n;
    }
};

//暴力解法
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == val){
                for(int j = i + 1; j < n; j++){
                    nums[j - 1] = nums[j];
                }
                --i;
                --n;
            }
        }
        return n;
    }
};
