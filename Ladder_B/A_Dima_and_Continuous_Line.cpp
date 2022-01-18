#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;

//LLLLLLLLLLL                               lllllll
//L:::::::::L                               l:::::l
//L:::::::::L                               l:::::l
//LL:::::::LL                               l:::::l
//  L:::::L               uuuuuu    uuuuuu   l::::l zzzzzzzzzzzzzzzzz    ssssssssss       eeeeeeeeeeee        cccccccccccccccc
//  L:::::L               u::::u    u::::u   l::::l z:::::::::::::::z  ss::::::::::s    ee::::::::::::ee    cc:::::::::::::::c
//  L:::::L               u::::u    u::::u   l::::l z::::::::::::::z ss:::::::::::::s  e::::::eeeee:::::ee c:::::::::::::::::c
//  L:::::L               u::::u    u::::u   l::::l zzzzzzzz::::::z  s::::::ssss:::::se::::::e     e:::::ec:::::::cccccc:::::c
//  L:::::L               u::::u    u::::u   l::::l       z::::::z    s:::::s  ssssss e:::::::eeeee::::::ec::::::c     ccccccc
//  L:::::L               u::::u    u::::u   l::::l      z::::::z       s::::::s      e:::::::::::::::::e c:::::c
//  L:::::L               u::::u    u::::u   l::::l     z::::::z           s::::::s   e::::::eeeeeeeeeee  c:::::c
//  L:::::L         LLLLLLu:::::uuuu:::::u   l::::l    z::::::z      ssssss   s:::::s e:::::::e           c::::::c     ccccccc
//LL:::::::LLLLLLLLL:::::Lu:::::::::::::::uul::::::l  z::::::zzzzzzzzs:::::ssss::::::se::::::::e          c:::::::cccccc:::::c
//L::::::::::::::::::::::L u:::::::::::::::ul::::::l z::::::::::::::zs::::::::::::::s  e::::::::eeeeeeee   c:::::::::::::::::c
//L::::::::::::::::::::::L  uu::::::::uu:::ul::::::lz:::::::::::::::z s:::::::::::ss    ee:::::::::::::e    cc:::::::::::::::c
//LLLLLLLLLLLLLLLLLLLLLLLL    uuuuuuuu  uuuullllllllzzzzzzzzzzzzzzzzz  sssssssssss        eeeeeeeeeeeeee      cccccccccccccccc
#define MOD 1000000007
#define PI 3.141592653589793238462
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*########################################### DEBUG ###############################################################################################*/
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(long long t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

/*###############################################################################################################################################*/
bool check_intersect(pair<long long, long long> &p1, pair<long long, long long> &p2)
{
    if(p1.first<p2.first&&p2.first<p1.second&&p1.second<p2.second)
    {
        return true;
    }
    else if(p2.first<p1.first&&p1.first<p2.second&&p2.second<p1.second)
    {
        return true;
    }
    return false;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<long long> vt(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> vt[i];
    }
    bool answer = false;
    if (n == 1)
    {
        cout << "no\n";
    }
    else
    {
        vector<pair<long long, long long>> vp;
        for (int i = 0; i + 1 < n; ++i)
        {
            long long Min = min(vt[i], vt[i + 1]);
            long long Max = max(vt[i], vt[i + 1]);
            vp.push_back({Min, Max});
        }
        for (int i = 0; i < vp.size(); ++i)
        {
            for (int j = i + 1; j < vp.size(); ++j)
            {
                if (check_intersect(vp[i], vp[j]) == true)
                {
                    answer = true;
                    break;
                }
            }
            if (answer == true)
            {
                break;
            }
        }
        if (answer == true)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
}