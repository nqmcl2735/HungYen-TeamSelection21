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
#define Task "LONGRUN"
using namespace std;
const double Pi = acos(-1);
typedef long long ll;
typedef long double ld;
int v[maxn];
int c, l, n;
int res = 0;
double tmax;
int calc(int x, int y)
{
    double mu = (v[x] - v[y]) * 1.00;
    int f = tmax * (mu / c);
    return f;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n >> l >> c;
    for (int i = 1; i <= n; i ++)
        cin >> v[i];
    sort(v + 1, v + n + 1);
    tmax = (1.00 * l * c)/ (1.00 * v[n]);
    for (int i = 2; i <= n; i ++)
        for (int j = 1; j < i; j ++)
            res += calc(i, j);
    cout << res;
}
