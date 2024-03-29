/* 
 * 老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
 * 你需要按照以下要求，帮助老师给这些孩子分发糖果：
 * 每个孩子至少分配到 1 个糖果。
 * 评分更高的孩子必须比他两侧的邻位孩子获得更多的糖果。
 * 那么这样下来，老师至少需要准备多少颗糖果呢？
 */
//方法一：两次遍历，贪心
//思路：第一次遍历保证了如果某个小孩评分比它左边小孩评分高，则他一定能得到比他左边小孩多的糖果
//如果只有一次遍历可能会出现左边孩子评分比右边孩子高，但是两个人拿一样多的糖果。这是因为如果左边这个孩子比他左边孩子评分低，那么左边这个孩子的糖果数是1
//而因为右边孩子比左边孩子评分低，所以他的糖果数也不会增加，仍为1。这样两个人的糖果数就会一样，因此需要再反方向遍历一次
//现在问题就是如果左边孩子评分比右边孩子高，可能会出现左边孩子的糖果比右边孩子少的情况吗
//会出现，因为在从右往左的过程中，右边孩子也会变的
//上面讲的情况没有考虑到从右往左遍历的过程中，右边孩子的糖果数可能会变得多于1个
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int num = n;
        vector<int> nums(n, 1);
        //第一次遍历保证了如果某个小孩评分比它左边小孩评分高，则他一定能得到比他左边小孩多的糖果
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]){
                num += nums[i-1] - nums[i] + 1;
                nums[i] = nums[i-1] + 1;
            }
        }
        //如果只有一次遍历可能会出现左边孩子评分比右边孩子高，但是两个人拿一样多的糖果
        //这是因为如果左边这个孩子比他左边孩子评分低，那么左边这个孩子的糖果数是1
        //而因为右边孩子比左边孩子评分低，所以他的糖果数也不会增加，仍为1
        //这样两个人的糖果数就会一样
        //因此需要再反方向遍历一次
        for(int i = n-2; i >= 0; i--){
            //问题就是如果左边孩子评分比右边孩子高，可能会出现左边孩子的糖果比右边孩子少的情况吗
            //会出现，因为在从右往左的过程中，右边孩子也会变的
            //上面讲的情况没有考虑到从右往左遍历的过程中，右边孩子的糖果数可能会变得多于1个
            //因此这里不能变成nums[i] == nums[i+1]
            if(ratings[i] > ratings[i+1] && nums[i] <= nums[i+1]){
                num += (nums[i+1] - nums[i] + 1);
                nums[i] = nums[i+1] + 1;
            }
        }
        return num;
    }
};
//上面的两次遍历可以满足条件
//这道题贪心之处在于，在遍历的过程中，如果我评分比你高，那么我就只比你多拿1块糖果（实际上可能并不是，也可能比你多拿好几块），
//第一次从左往右的遍历可以保证如果你比你左边的小孩评分高，你就可以比他拿的多。而第二次遍历可以保证如果你比你右边的小孩评分高，
//你可以拿的比他多，同时如果你比你左边小孩评分高，在第一次遍历的时候你就会拿的比他多，所以第二次遍历再多拿几个糖果也是比他多。
//如果你比你左边的小孩评分低，就算你这时候多拿了糖果，从而导致比他糖果多，等下轮到他的时候也会多给几个糖果给他。
//这道题贪心的点我觉得只是在遍历过程中如果旁边的人评分比你高，那么只会给你比他多1块糖果
//贪心
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> nums(n, 1);
        int ans = 0;
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1] && nums[i] <= nums[i-1]){
                nums[i] = nums[i-1] + 1;
            }
        }

        for(int i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i+1] && nums[i] <= nums[i+1]){
                nums[i] = nums[i+1] + 1;
            }
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};

//方法二：常数空间遍历
//思路：根据贪心的原则，糖果应该要少给，且从1开始累计，每次要么比相邻的同学多给一个，要么重新置为1
//对于一个递增子数组，给的糖果数应该也是递增的，而如果遇到一个小孩的评分等于左边小孩的情况，当前这个小孩给1个糖果
//在遍历过程中，如果当前小孩的评分小于左边的小孩，则先给他1个糖果，当后面的小孩评分更低时，则给后面的小孩1个糖果，前面递减子数组中的小孩都要多给1个糖果
//这里可能说的不是特别清楚，详情可以看官方解答
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ret = 1;
        int inc = 1, dec = 0, pre = 1;
        for(int i = 1; i < n; i++){
            if(ratings[i] >= ratings[i-1]){
                dec = 0;
                pre = (ratings[i] == ratings[i-1] ? 1 : pre + 1);
                inc = pre;
                ret += inc;
            }
            else{
                dec++;
                if(dec == inc){
                    dec++;
                }
                ret += dec;
                pre = 1;
            }
        }
        return ret;
    }
};
//总结：首先对于第一种方法，也就是两次遍历（贪心），需要掌握的是这种两次遍历的方法和这种贪心的思想，每次我都只分配刚好满足条件的糖果就可以让总的糖果数最少
//每次都给小孩分配能满足条件的最少的糖果，这就是贪心
