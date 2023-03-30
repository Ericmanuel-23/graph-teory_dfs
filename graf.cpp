#include <bits/stdc++.h>
#define ll long long
#define S second
#define F first
#define PB push_back
using namespace std;

const int Size = 1e5 + 4;

vector<pair<int,int> >cont;
bool visited [Size];
vector<int> adj[Size];

void dfs(int x){
    visited[x] = 1;

    for(int y : adj[x])
        if (!visited[y])
            dfs(y);
    }
int main()
{
    int N,M;
    cin>>N>>M;

    for(int i = 0; i< M;i++){
            int A,B;
            cin>>A>>B;

            adj[A].push_back(B);
            adj[B].push_back(A);
    }
    int res = - 1;
    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            dfs(i);
            if (res != - 1) {
                cont.emplace_back(i, res);
            }
            res = i;
        }

    }

    cout << cont.size() << "\n";
    for (auto &x : cont) {
        cout << x.F << " " << x.S << "\n";
    }
    return 0;
}
