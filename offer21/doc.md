# 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面

> https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/

输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。

**示例**：

> 输入：nums = [1,2,3,4]
> 输出：[1,3,2,4] 
> 注：[3,1,2,4] 也是正确的答案之一。

**提示**：

> 0 <= nums.length <= 50000
> 1 <= nums[i] <= 10000

**代码**

```java
class Solution {
    public int[] exchange(int[] nums) {
        int length = nums.length;
        int i = 0;
        int j = length - 1;
        while(i < j){
            if(nums[i] % 2 != 1 && nums[j] % 2 != 0){
                int e = nums[i];
                nums[i] = nums[j];
                nums[j] = e;
            }else if(nums[i] % 2 != 1){
                j--;
            }else if(nums[j] % 2 != 0){
                i++;
            }else{
                j--;
                i++;
            }
        }
        return nums;
    }
}
```

**解题思路**

​		本题目的是将一个整数数组中的奇数放在左边，相反偶数在右边。可以在数组首尾设置指针i，j。如果i指向的数不是奇数，则该数需要交换到右边，同时j指向的数不是偶数，则需要交换到左侧。

**核心代码**

```java
if(nums[i] % 2 != 1 && nums[j] % 2 != 0){
	int e = nums[i];
    nums[i] = nums[j];
    nums[j] = e;
}else if(nums[i] % 2 != 1){
    j--;
}else if(nums[j] % 2 != 0){
    i++;
}else{
    j--;
    i++;
}
```

- 首尾同时不满足，则同时交换。
- 若左侧不满足，i值不变，j左移继续判断直到找到右侧不满足的数或i，j重叠结束。
- 若右侧不满足同理左侧。
- 若都满足则同时移动一位。

**快慢双指针**

​		这次用的是首尾双指针，还有一种方法是快慢双指针。

```c++
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if ((nums[left] & 1) != 0) {
                left ++;
                continue;
            }
            if ((nums[right] & 1) != 1) {
                right --;
                continue;
            }
            swap(nums[left++], nums[right--]);
        }
        return nums;
    }
};
```

> 作者：https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/solution/ti-jie-shou-wei-shuang-zhi-zhen-kuai-man-shuang-zh/