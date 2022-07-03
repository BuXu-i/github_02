class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * ������С�Ļ��Ѵ���ʹ����n���˼���������
     * @param n int n���˼ҵĴ�ׯ
     * @param m int m��·
     * @param cost intvector<vector<>> һά3����������ʾ����1����ׯ������1����ׯ�Ļ��ѵĴ���
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
