/* 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。*/
/*方法1：使用堆排序的方法，首先利用数组创建堆，然后依次弹出前面k-1个值，最后将最大值放到数组最后，然后取出*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(begin(nums), end(nums));
        for(int i = 0; i < k-1; i++){
            pop_heap(begin(nums), end(nums));
            nums.pop_back();
        }
        pop_heap(begin(nums), end(nums));
        return nums[nums.size()-1];
    }
};

/* 方法二，官方答案，实际上也是使用堆的方法，但是是通过自己实现堆的功能，而不是用库函数*/
class Solution {
public:
    void maxheapify(vector<int>& nums, int i, int heapsize){
        int l = 2 * i + 1, r = 2 * i + 2, largest = i;
        if(l < heapsize && nums[l] > nums[largest]){
            largest = l;
        }
        if(r < heapsize && nums[r] > nums[largest]){
            largest = r;
        }
        if(largest != i){
            swap(nums[i], nums[largest]);
            maxheapify(nums, largest, heapsize);
        }
    }

    void buildmaxheap(vector<int>& nums, int heapsize){
        //该函数初始化创建堆
        for(int i = heapsize/2; i >= 0; i--){
            maxheapify(nums, i, heapsize);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int heapsize = nums.size();
        buildmaxheap(nums, heapsize);
        for(int i = nums.size() - 1; i >= nums.size() - k + 1; i--){
            swap(nums[0], nums[i]);
            heapsize--;
            maxheapify(nums, 0, heapsize);
        }
        return nums[0];
    }
};

/* 方法三，基于快速排序的查找算法 */
/* 基本思路就是用快速排序找到第k个最大的值，但是并不需要像快速排序那么多运算*/
/* 因为我们只需要找到第k个最大的，而每次排序我们都可以找到一个知道正确位置的数，如果这个数正好是k则不用再排序了，如果不是k，我们也只需要做到一边排序即可*/
/*在分解的过程当中，我们会对子数组进行划分，如果划分得到的 qq 正好就是我们需要的下标，就直接返回 a[q]a[q]；否则，如果 qq 比目标下标小，就递归右子区间，否则递归左子区间。
 *这样就可以把原来递归两个区间变成只递归一个区间，提高了时间效率。这就是「快速选择」算法。我们知道快速排序的性能和「划分」出的子数组的长度密切相关。直观地理解如果每次规模
 *为 nn 的问题我们都划分成 11 和 n - 1n−1，每次递归的时候又向 n - 1n−1 的集合中递归，这种情况是最坏的，时间代价是 O(n ^ 2)O(n 2)。我们可以引入随机化来加速这个过程，它的时
 *间代价的期望是 O(n)O(n)
 */
class Solution {
public:
    int partition(vector<int>& nums, int l, int r){
        int i = l, j = r, x = nums[l];
        while(i < j){
            while(i < j && nums[j] >= x){
                j--;
            }
            if(i < j){
                nums[i++] = nums[j];
            }
            while(i < j && nums[i] <= x){
                i++;
            }
            if(i < j){
                nums[j--] = nums[i];
            }
        }
        nums[i] = x;
        return i;
    }

    int quicksort(vector<int>& nums, int l, int r, int index){
        int i  = partition(nums, l, r);
        if(i == index){
            return nums[i];
        }
        else{
            return (i < index) ? (quicksort(nums, i+1, r, index)) : (quicksort(nums, l, i-1, index)); 
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int numsize = nums.size();
        return quicksort(nums, 0, numsize-1, numsize-k);
    }
};

