//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define Random(lf, rt) (lf + rand() % (rt - lf + 1))
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define mpa make_pair
#define oo 100000007
#define F first
#define S second
#define reset(x, i) memset(x,i,sizeof(x))
#define sz(x) int(x.size())
#define maxn 100005
#define MOD
#define all(x) x.begin(), x.end()
#define cosdo(x) cos((x)/180 * Pi)
#define sindo(x) sin((x)/180 * Pi)
#define tando(x) tan((x)/180 * Pi)
#define cotdo(x) 1/tando(x)
#define Task "FLOW"
using namespace std;
const double Pi = acos(-1);
typedef long long ll;
typedef long double ld;
int lg = 20;
struct data
{
    int u, v, w;
}canh[maxn];
bool cmp(data a, data b)
{
    return a.w > b.w;
}
int n, m, q;
int pr[maxn];
int SpT[20][maxn];
int minP[20][maxn];
vii ke[maxn];
int h[maxn];
ll res = 0;
int find_pr(int x)
{
    if (!pr[x]) return x;
    return (pr[x] = find_pr(pr[x]));
}
void noi(int u, int v, int w)
{
    int x = find_pr(u);
    int y = find_pr(v);
    if (x == y) return;
    pr[x] = y;
    ke[u].PB({v, w});
    ke[v].PB({u, w});
    //cout << u << " " << v << "\n";
}
void dfs(int u)
{
    int v, w;
    for (pii x : ke[u])
    {
        v = x.F;
        w = x.S;
        if (v == SpT[0][u]) continue;
        SpT[0][v] = u;
        minP[0][v] = w;
        h[v] = h[u] + 1;
        for (int i = 1; i < lg; i ++){
            SpT[i][v] = SpT[i - 1][SpT[i - 1][v]];
            minP[i][v] = min(minP[i - 1][v], minP[i - 1][SpT[i - 1][v]]);
        }
        dfs(v);
    }
}
int min_lca(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    int mn = oo;
    int k = h[u] - h[v];
    for (int i = lg - 1; i >= 0; i --)
        if (k & (1 << i))
        {
            mn = min(mn, minP[i][u]);
            u = SpT[i][u];
        }
    if (u == v) return mn;
    for (int i = lg - 1; i >= 0; i --)
        if (SpT[i][u] != SpT[i][v])
        {
            mn = min(min(mn, minP[i][u]), minP[i][v]);
            u = SpT[i][u];
            v = SpT[i][v];
        }
        mn = min(min(mn, minP[0][u]), minP[0][v]);
        return mn;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n >> m >> q;
    int u, v, w;
    for (int i = 1; i <= m; i ++)
    {
        cin >> u >> v >> w;
        canh[i] = {u, v, w};
    }
    sort(canh + 1, canh + m + 1, cmp);
    for (int i = 1; i <= m; i ++)
    {
        u = canh[i].u;
        v = canh[i].v;
        w = canh[i].w;
        noi(u, v, w);
    }
    dfs(1);
    while(q --)
    {
        cin >> u >> v;
        cout << min_lca(u, v) << "\n";
    }
}
