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
int main()
{
#ifndef ONLINE_JUDGE
    // freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    long long k;
    cin >> k;
    vector<long long> answer;
    long long start = 1;
    int length = n / 2;
    if (k < length)
    {
        cout << "-1\n";
    }
    else if (n == 1)
    {
        if (k == 0)
        {
            cout << "1\n";
        }
        else
        {
            cout << "-1\n";
        }
    }
    else
    {

        long long count = 0, start = 1;
        for (int i = 0; i < n - 2 - (n % 2); ++i)
        {
            answer.push_back(start);
            start++;
            if (i % 2 == 0)
            {
                count++;
            }
        }
        long long last_value = k - count;
        answer.push_back(last_value);
        answer.push_back(2 * last_value);
        long long Max = 0;
        for (auto x : answer)
        {
            Max = max(Max, x);
        }
        if (last_value < start)
        {
            for (int i = 0; i < n - 2; ++i)
            {
                if (answer[i] == last_value)
                {
                    if (i % 2 == 0)
                    {
                        answer[i] = Max + 1;
                        answer[i + 1] = Max + 2;
                    }
                    else
                    {
                        answer[i] = Max + 1;
                        answer[i - 1] = Max + 2;
                    }
                    break;
                }
            }
            Max = Max + 2;
            for (int i = 0; i < n - 2; ++i)
            {
                if (answer[i] == 2 * last_value)
                {
                    if (i % 2 == 0)
                    {
                        answer[i] = Max + 1;
                        answer[i + 1] = Max + 2;
                    }
                    else
                    {
                        answer[i] = Max + 1;
                        answer[i - 1] = Max + 2;
                    }
                    break;
                }
            }
        }
        if (n % 2 == 1)
        {
            answer.push_back(2 * (Max + 3));
        }
        for (auto x : answer)
        {
            cout << x << " ";
        }
    }
}