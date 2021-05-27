/* 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。你可以假设数组是非空的，并且给定的数组总是存在多数元素。*/
//方法一，使用哈希表，遍历数组中的元素，并使用哈希表计算每个元素出现的次数，当大于等于n/2 + 1时表示这个元素就是多数（因为每个数组中只有一个多数，所以个数大于一半的数肯定就是多数）
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> intmap;
        int i;
        for(i = 0; i < n; i++){
            intmap[nums[i]] += 1;
            if(intmap[nums[i]] >= (n/2) + 1){
                break;
            }
        }
        return nums[i];
    }
};

//方法二，排序
//如果将数组 nums 中的所有元素按照单调递增或单调递减的顺序排序，那么下标为[n/2]的元素（下标从 0 开始）一定是众数。
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n/2];
    }
};

//方法三，随机化
//因为超过 [n/2] 的数组下标被众数占据了，这样我们随机挑选一个下标对应的元素并验证，有很大的概率能找到众数。
//由于一个给定的下标对应的数字很有可能是众数，我们随机挑选一个下标，检查它是否是众数，如果是就返回，否则继续随机挑选。
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        while(true){
            int candidate = nums[rand() % nums.size()];
            int count = 0;
            for(int num : nums){
                if(num == candidate){
                    count++;
                }
            }
            if(count > nums.size() / 2){
                return candidate;
            }
        }
        return -1;
    }
};

//方法四，分治
/* 我们使用经典的分治算法递归求解，直到所有的子问题都是长度为 1 的数组。长度为 1 的子数组中唯一的数显然是众数，
 * 直接返回即可。如果回溯后某区间的长度大于 1，我们必须将左右子区间的值合并。如果它们的众数相同，那么显然这一段区间的众数是它们相同的值。
 * 否则，我们需要比较两个众数在整个区间内出现的次数来决定该区间的众数。
*/
class Solution {
    int count_element(vector<int>& nums, int target, int l, int r){
        int count = 0;
        for(int i = l; i <= r; i++){
            if(nums[i] == target){
                count++;
            }
        }
        return count;
    }

    int maxnumelement(vector<int>& nums, int l, int r){
        if(l == r){
            return nums[l];
        }
        int mid = (l + r) / 2;
        int leftmaxelement = maxnumelement(nums, l, mid);
        int rightmaxelement = maxnumelement(nums, mid + 1, r);
        if(count_element(nums, leftmaxelement, l, r) > (r - l + 1) / 2){
            return leftmaxelement;
        }
        if(count_element(nums, rightmaxelement, l, r) > (r - l + 1) / 2){
            return rightmaxelement;
        }
        return -1;
    }
public:
    int majorityElement(vector<int>& nums) {
        return maxnumelement(nums, 0, nums.size()-1);
    }
};
