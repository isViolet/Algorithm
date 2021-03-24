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