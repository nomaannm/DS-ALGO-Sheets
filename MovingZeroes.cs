/**
* PROBLEM NO : 283
*/
public class Solution {
    public void MoveZeroes(int[] nums) {
        int tmp = 0 ;
        for(int i = 0 ; i < nums.Length - 1 ; i++)
        {
            if(nums[i] == 0)
            {
                tmp = nums[i];
                for(int j = i+1 ; j < nums.Length ; j++)
                {
                    if(nums[j] != 0)
                    {
                        nums[i] = nums[j];
                        nums[j] = tmp ;
                        break ;
                    
                    }
                }
                
            }
        }
    }
}
