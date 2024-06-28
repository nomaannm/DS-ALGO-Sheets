int canWePlace(vector<int>& stalls, int minDistance, int cows){
    int placedCows = 1, lastPlacedCowCoordinate = stalls[0];
    for(int i = 1; i < stalls.size() ; i++){
        if((stalls[i] - lastPlacedCowCoordinate) >= minDistance){
            placedCows++;
            lastPlacedCowCoordinate = stalls[i];
        }
    } 
    if(placedCows >= cows) return 1;
    return 0;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int maxPossible = 1;
    sort(begin(stalls),end(stalls));
    int lo = 1, hi = (stalls[stalls.size()-1] - stalls[0]);
    while(lo <= hi){
        int mid = (lo + hi)/2;
        {
            if(canWePlace(stalls,mid,k)) {
                maxPossible = max(maxPossible , mid);
                lo = mid + 1;
            }
            else{
                hi = mid-1;

            }
        }
    }
    return maxPossible;
}

