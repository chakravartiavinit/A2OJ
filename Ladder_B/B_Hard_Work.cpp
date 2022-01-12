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
bool check(char a)
{
    if (a == ';' || a == '_' || a == '-')
    {
        return false;
    }
    return true;
}
bool correct(string a, string b, string c, string d)
{
    string temp;
    for (int i = 0; i < a.length(); ++i)
    {
        if (check(a[i]) == true)
        {
            temp.push_back(a[i]);
        }
    }
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    vector<string> vt;
    vt.push_back(b);
    vt.push_back(c);
    vt.push_back(d);
    vector<int> vt1 = {0, 1, 2};
    do
    {
        string gamma;
        gamma += vt[vt1[0]] + vt[vt1[1]] + vt[vt1[2]];
        if (gamma == temp)
        {
            return true;
        }
    } while (next_permutation(vt1.begin(), vt1.end()));
    return false;
}
int main()
{
#ifndef ONLINE_JUDGE
    // freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string alpha, beta, gamma;
    cin >> alpha >> beta >> gamma;
    string temp1, temp2, temp3;
    for (int i = 0; i < alpha.length(); ++i)
    {
        if (check(alpha[i]) == true)
        {
            temp1.push_back(alpha[i]);
        }
    }
    for (int i = 0; i < beta.length(); ++i)
    {
        if (check(beta[i]) == true)
        {
            temp2.push_back(beta[i]);
        }
    }
    for (int i = 0; i < gamma.length(); ++i)
    {
        if (check(gamma[i]) == true)
        {
            temp3.push_back(gamma[i]);
        }
    }
    transform(temp1.begin(), temp1.end(), temp1.begin(), ::tolower);
    transform(temp2.begin(), temp2.end(), temp2.begin(), ::tolower);
    transform(temp3.begin(), temp3.end(), temp3.begin(), ::tolower);
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (correct(s, temp1, temp2, temp3) == true)
        {
            cout << "ACC\n";
        }
        else
        {
            cout << "WA\n";
        }
    }
}