struct data {
    int start;
    int end;
    int pos;
};

class Comparator{
  public:
    Comparator() = default;
    bool operator()(const data& theData1, const data& theData2){
        return theData1.end < theData2.end;
    }
};


class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<data> dataArr;
        for(int i=0; i < start.size(); i++){
            data temp = {start[i], end[i], i+1};
            dataArr.push_back(temp);
        }
        
        sort(dataArr.begin(), dataArr.end(), Comparator());
        
        int maxim = 1;
        int freeTime = dataArr[0].end;
        vector<int> positions;
        positions.push_back(dataArr[0].pos);
        
        for(int i=1; i < dataArr.size(); i++){
            if(dataArr[i].start > freeTime){
                maxim += 1;
                freeTime = dataArr[i].end;
                positions.push_back(dataArr[i].pos);
            }
        }
        
        return maxim;
        
    }
};
