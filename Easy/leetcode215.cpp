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
