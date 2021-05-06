/* 第 i 个人的体重为 people[i]，每艘船可以承载的最大重量为 limit。
 * 每艘船最多可同时载两人，但条件是这些人的重量之和最多为 limit。
 * 返回载到每一个人所需的最小船数。(保证每个人都能被船载)。
*/
//官方给出的答案是贪心算法，也是双指针算法
//思路：如果最重的人可以与最轻的人共用一艘船，那么就这样安排。否则，最重的人无法与任何人配对，那么他们将自己独自乘一艘船。这么做的原因是，如果最轻的人可以与任何人配对，那么他们也可以与最重的人配对。
//算法：令 people[i] 指向当前最轻的人，而 people[j] 指向最重的那位。然后，如上所述，如果最重的人可以与最轻的人共用一条船（即 people[j] + people[i] <= limit），那么就这样做；否则，最重的人自己独自坐在船上。
//需要注意的是每艘船只能载2个人，核心就是最优的组合就是当前最重和当前最轻的人一艘船，如果当前最重的人和当前最轻的人不能坐在一艘船上，则这个最重的人要一个人一艘船
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        int ans = 0;

        while (i <= j) {
            ans++;        //就是因为如果当前最重的人和最轻的人不能在一起，则最重的人需要一个人一艘，所以就要将结果加一，所以每次j必定都会减一
            if (people[i] + people[j] <= limit)
                i++;
            j--; 
        }

        return ans;
    }
};