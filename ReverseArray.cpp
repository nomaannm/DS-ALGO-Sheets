//CODING NINJAS

vector<int> reverseArray(int n, vector<int> &nums)
{
    for(auto fit = begin(nums) , eit = end(nums)-1 ; fit < eit ; fit++ , eit--){
        swap(*fit,*eit);
    }
    return nums;

}
