#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL_
void debug_out() {
    cerr << "\033[0m" << endl;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << ' ' << H << ',';
    debug_out(T...);
}
#define debug(...) cerr << "\033[1;36m" << __func__ << ":L" << __LINE__ << " " << #__VA_ARGS__ << ":", debug_out(__VA_ARGS__)
#define dump(x) cerr << __func__ << ":L" << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define irep(i, n) for (int i = (int)(n)-1; i >= 0; --i)

using ll  = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

constexpr int INF        = 1000'000'000;
constexpr long long HINF = 4000'000'000000'000'000;
constexpr long long MOD  = 1000000007; // = 998244353;
constexpr double EPS     = 1e-4;
constexpr double PI      = 3.14159265358979;

#pragma region Macros
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << '[';
    for (auto &e : v) {
        os << e << ',';
    }
    os << ']';
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &st) {
    os << '{';
    for (auto itr = st.begin(); itr != st.end(); itr++) {
        os << *itr << ',';
    }
    os << '}';
    return os;
}
template <typename K, typename V>
ostream &operator<<(ostream &os, const map<K, V> &mp) {
    os << '{';
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        os << itr->first << ": " << itr->second << ',';
    }
    os << '}';
    return os;
}

void yn(bool cond, string Yes = "Yes", string No = "No") {
    cout << (cond ? Yes : No) << '\n';
}

template <typename T>
bool chmax(T &x, const T &y) {
    return (x < y) ? (x = y, true) : false;
}

template <typename T>
bool chmin(T &x, const T &y) {
    return (x > y) ? (x = y, true) : false;
}

#pragma endregion

// random seed
random_device seed_gen;
mt19937_64 rnd(seed_gen());
using GenInt  = uniform_int_distribution<int>;
using GenLong = uniform_int_distribution<long long>;

char lower() {
    static GenInt gen(0, 25);
    return 'a' + gen(rnd);
}

string lstring(int len) {
    string ret;
    ret.reserve(len);
    for (int i = 0; i < len; i++) {
        ret.push_back(lower());
    }
    return ret;
}

char upper() {
    static GenInt gen(0, 25);
    return 'A' + gen(rnd);
}

string ustring(int len) {
    string ret;
    ret.reserve(len);
    for (int i = 0; i < len; i++) {
        ret.push_back(upper());
    }
    return ret;
}

#pragma endregion

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    /*
        // make random int variable: 0 <= n <= 10
        GenInt gen(0, 10);
        int n = gen(rnd);
    */

    return 0;
}