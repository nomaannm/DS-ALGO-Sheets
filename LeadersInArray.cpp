vector<int> superiorElements(vector<int>&a) {
    int maxi = INT_MIN;
    vector<int> leaders;

    for(int i = a.size() - 1 ; i >= 0 ; i--){
        if(a[i] > maxi) leaders.push_back(a[i]);
        maxi = max(maxi,a[i]);
    }


    return leaders;
}
