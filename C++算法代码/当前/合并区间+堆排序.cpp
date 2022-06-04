/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

void fun1(vector<Interval> &intervals,int Li,int len){
    
}
void fun(vector<Interval> &intervals){
    for(int i=0;i<intervals.size();i--){
        fun1(intervals,i,intervals.size());
    }
    for(int i=0;i<intervals.size();i++){
        fun1(intervals,0,intervals.size());
    }
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.size()<2) return intervals;
        int suu;
        int kazu;
        int i=0;
        vector<Interval>arr;
        //排序 排序
        fun(intervals);
        i=0;
        while(i+1<intervals.size()){
            suu=intervals[i].end;
            kazu=intervals[i+1].start;
            int k=i;
            while(suu>=kazu){
                k++;
                if(k+1>=intervals.size()){
                    intervals[i].end=intervals[k].end; 
                    arr.push_back(intervals[i]);
                    return arr;
                }
                intervals[i].end=intervals[k].end;
                suu=intervals[k].end;
                kazu=intervals[k+1].start;
              //  intervals[i].end=0;//不可能数字;
            }
            
            arr.push_back(intervals[i]);
            i=k+1;
        }
        arr.push_back(intervals[i]);
        return arr;
    }
};
