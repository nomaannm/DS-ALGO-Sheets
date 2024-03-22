// REVERSE ARRAY
// CODING NINJAS
// TWO POINTERS RECURSION 
void twoPtrRecursion(vector<int>::iterator ptr1 , vector<int>::iterator ptr2, vector<int>& nums){;
    if(ptr1 >= ptr2) return;
    swap(*ptr1 , *ptr2);
    return twoPtrRecursion(++ptr1,--ptr2,nums);
    
}
vector<int> reverseArray(int n, vector<int> &nums)
{
    auto l = nums.begin();
    auto r = nums.end() - 1;
    twoPtrRecursion(l,r,nums);
    return nums;

}
