/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
//bool operator>(){
    
//}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.size()<2) return intervals;
        int suu;
        int kazu;
        int i=0;
        vector<Interval>arr;
        //���� ����
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b){
            return a.start < b.start;
        });
        for(int i=0;i<intervals.size();i++){
            cout<<intervals[i].start<<" ";
        }
        i=0;
        while(i+1<intervals.size()){
            suu=intervals[i].end;
            kazu=intervals[i+1].start;
            int k=i;
            while(suu>=kazu){
                k++;
                if(k+1>=intervals.size()){
                    intervals[i].end=max(intervals[i].end,intervals[k].end); 
                    arr.push_back(intervals[i]);
                    return arr;
                }
                intervals[i].end=max(intervals[i].end,intervals[k].end); 
                //intervals[i].end=intervals[k].end;
                suu=intervals[k].end;
                kazu=intervals[k+1].start;
              //  intervals[i].end=0;//����������;
            }
            
            arr.push_back(intervals[i]);
            i=k+1;
        }
        arr.push_back(intervals[i]);
        return arr;
    }
};
