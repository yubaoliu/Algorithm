//https://ain-crad.github.io/2018/11/18/Uva1599-Ideal-Path/
// https://github.com/Ain-Crad/Algorithm-and-DataStructure-Practice/blob/master/Uva/Uva1599.cpp
/*
 *
 * Author : Aincrad
 *
 * Date : Sat 17 Nov 23:09:12 CST 2018
 *
 */
#include <bits/stdc++.h>

using namespace std;
#define ONLINE_JUDGE
const int maxn = 1e5 + 7;
const int inf = 1e9 + 7;
struct Edge{
    int to;
    int color;
};
vector<Edge> G[maxn];
int n, m;
int d[maxn];
bool vis[maxn];

void back_bfs(){
    d[n - 1] = 0;
    vis[n - 1] = true;
    queue<int> que;
    que.push(n - 1);
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(size_t i = 0; i < G[v].size(); i++){
            Edge e = G[v][i];
            int u = e.to;
            if(!vis[u]){
                d[u] = d[v] + 1;
                que.push(u);
                vis[u] = true;
            }
        }

    }
}

vector<int> ans;

void bfs(){
    memset(vis, 0, sizeof(vis));
    vis[0] = true;

    vector<int> next;
    next.push_back(0);
    for(int i = 0; i < d[0]; i++){
        int minColor = inf;
        for(size_t j = 0; j < next.size(); j++){
            int v = next[j];
            for(size_t k = 0; k < G[v].size(); k++){
                Edge e = G[v][k];
                int u = e.to;
                if(d[u] == d[v] - 1){
                    minColor = min(minColor, e.color);
                }
            }
        }
        ans.push_back(minColor);

        vector<int> next2;
        for(size_t j = 0; j < next.size(); j++){
            int v = next[j];
            for(size_t k = 0; k < G[v].size(); k++){
                Edge e = G[v][k];
                if(e.color == minColor && !vis[e.to] && d[e.to] == d[v] - 1){
                    next2.push_back(e.to);
                    vis[e.to] = true;
                }
            }
        }
        next = next2;
    }

    int res = ans.size();
    cout << res << endl;
    for(int i = 0; i < res; i++){
        if(i == 0) cout << ans[i];
        else cout << " " << ans[i];
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif

    while(cin >> n >> m){
        memset(d, 0, sizeof(d));
        memset(vis, 0, sizeof(vis));
        ans.clear();
        for(int i = 0; i < n; i++){
            G[i].clear();
        }

        int a, b, c;
        Edge e;
        for(int i = 0; i < m; i++){
            cin >> a >> b >> c;
            e.to = b - 1;
            e.color = c;
            G[a - 1].push_back(e);
            e.to = a - 1;
            G[b - 1].push_back(e);
        }

        back_bfs();
        bfs();
    }
    return 0;
}