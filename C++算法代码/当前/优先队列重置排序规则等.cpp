class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回最小的花费代价使得这n户人家连接起来
     * @param n int n户人家的村庄
     * @param m int m条路
     * @param cost intvector<vector<>> 一维3个参数，表示连接1个村庄到另外1个村庄的花费的代价
     * @return int
     */
    struct cpm{
        bool operator()(pair<int, int>T1,pair<int, int>T2){
            return T1.second>T2.second?1:0;
        }
    };
    int miniSpanningTree(int n, int m, vector<vector<int> >& cost) {
        // write code here
        vector<int>vec(n,false);
        vector<vector<int>>cos(n,vector<int>(n));
        for(const auto &i:cost){
            cos[i[0]-1][i[1]-1]=cos[i[1]-1][i[0]-1]=i[2];
        }
        priority_queue<int,vector<pair<int,int>>,cpm>que;
        int suu=0,ki=1,s=0;
        vec[suu]=true;
        while(true){
            for(int i=0;i<cos[suu].size();i++){
                if(vec[i]==false&&cos[suu][i]!=0){
                    que.push({i,cos[suu][i]});
                }
            }
            while(vec[que.top().first]){
                que.pop();
            }
            s+=que.top().second;
            cout<<suu<<"-"<<que.top().first<<"="<<s<<" | ";
            if(++ki==n)return s;
            suu=que.top().first;
            vec[suu]=true;
            que.pop();
        }
    }
};
