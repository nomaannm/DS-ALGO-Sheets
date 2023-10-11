/**
* PROBLEM NO : 268
*/
public class Solution {
    public int MissingNumber(int[] nums) {
        int sum = 0, n = nums.Length ;
        foreach(int i in nums)
        {
            sum += i ;
        }

        int ans = n*(n+1)/2;
        return ans - sum;
        
    }
}
