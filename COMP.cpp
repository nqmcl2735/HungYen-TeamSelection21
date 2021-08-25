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
#define maxn 5005
#define MOD 1000000007
#define all(x) x.begin(), x.end()
#define cosdo(x) cos((x)/180 * Pi)
#define sindo(x) sin((x)/180 * Pi)
#define tando(x) tan((x)/180 * Pi)
#define cotdo(x) 1/tando(x)
#define Task "COMP"
using namespace std;
const double Pi = acos(-1);
typedef long long ll;
typedef long double ld;
int dp[maxn];
ll sum[maxn];
ll mu[maxn];
ll M2 = 1ll * MOD * MOD;
ll coso = 311;
string s;
int n;
ll get_hash(int l, int r)
{
    return (sum[r] - sum[l - 1] * mu[r - l + 1] + M2)%MOD;
}
int sol(int l, int r)
{
    int x = r - l + 1;
    for (int i = 1; i <= x; i ++)
    if (x % i == 0)
    {
        bool flag = 1;
        int tinh = get_hash(l, l + i - 1);
        for (int j = l; j <= r - i + 1; j += i) if (get_hash(j, j + i - 1) != tinh)
        {
            flag = 0;
            break;
        }
        if (flag) return i;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> s;
    n = sz(s);
    s = " " + s;

    mu[0] = 1;
    for (int i = 1; i <= n; i ++)
        mu[i] = (mu[i - 1] * coso) % MOD;

    sum[0] = 0;
    for (int i = 1; i <= n; i ++)
        sum[i] = (sum[i - 1] * coso + s[i]) %MOD;

    for (int i = 1; i <= n; i ++)
        dp[i] = oo;
    for (int r = 1; r <= n; r ++)
        for (int l = 1; l <= r; l ++)
        dp[r] = min(dp[r], dp[l - 1] + sol(l, r));
    cout << dp[n];
}

