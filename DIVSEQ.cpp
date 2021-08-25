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
#define maxn 100005
#define MOD
#define all(x) x.begin(), x.end()
#define cosdo(x) cos((x)/180 * Pi)
#define sindo(x) sin((x)/180 * Pi)
#define tando(x) tan((x)/180 * Pi)
#define cotdo(x) 1/tando(x)
#define Task "DIVSEQ"
using namespace std;
const double Pi = acos(-1);
typedef long long ll;
typedef long double ld;
int a[maxn];
vi pos[maxn * 10];
int n, d;
int sf[maxn];
int add(int x, int y)
{
    x += y;
    if (x >= d) x -= d;
    return x;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    int t; cin >> t;
    while (t --) {
        reset(pos, 0);
        cin >> n >> d;
        for (int i = 1; i <= n; i ++) {
            cin >> a[i];
            a[i] %= d;
            sf[i] =add(sf[i - 1], a[i]);
        }
        for (int i = 0; i <= n; i ++)
            pos[sf[i]].PB(i);
        ll res = 0;
        int mx = 0;
        for (int i = 0; i <= d; i ++)
        {
            int x = sz(pos[i]);
            if (x == 0 || x == 1) continue;
            res += 1ll * x * (x - 1)/2;
            mx = max(mx, pos[i][x - 1] - pos[i][0]);
        }
        cout << res << " " << mx << "\n";
    }
}


