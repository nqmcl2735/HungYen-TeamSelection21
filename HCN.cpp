//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define Random(lf, rt) (lf + rand() % (rt - lf + 1))
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define mpa make_pair
#define oo INT_MAX
#define F first
#define S second
#define reset(x, i) memset(x,i,sizeof(x))
#define sz(x) int(x.size())
#define maxn 1000005
#define MOD
#define all(x) x.begin(), x.end()
#define cosdo(x) cos((x)/180 * Pi)
#define sindo(x) sin((x)/180 * Pi)
#define tando(x) tan((x)/180 * Pi)
#define cotdo(x) 1/tando(x)
#define Task "HCN"
using namespace std;
const double Pi = acos(-1);
typedef long long ll;
typedef long double ld;
int h[maxn];
int n, m;
stack <int> st;
ll res = 0;
pii res_bl[maxn];
void sol()
{
    while(!st.empty()) st.pop();
    for (int i = 1; i <= n; i ++)
    {
        while(!st.empty() && h[st.top()] >= h[i]) st.pop();
        res_bl[i].F = 0;
        if (!st.empty()) res_bl[i].F = st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for (int i = n; i >= 1; i --)
    {
        while(!st.empty() && h[st.top()] >= h[i]) st.pop();
        res_bl[i].S = n + 1;
        if (!st.empty()) res_bl[i].S = st.top();
        st.push(i);
    }
    for (int i = 1; i <= n; i ++)
        res = max(res, 1ll * (res_bl[i].S - res_bl[i].F - 1) * h[i]);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> m >> n;
    for (int i = 1; i <= n; i ++) cin >> h[i];
    sol();
    for (int i = 1; i <= n; i ++) h[i] = m - h[i];
    sol();
    cout << res;

}
