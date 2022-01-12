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
void dfs(int start, map<int, vector<int>> &graph, vector<bool> &visited, int &counter)
{
    visited[start] = true;
    counter++;
    for (auto x : graph[start])
    {
        if (visited[x] == false)
        {
            dfs(x, graph, visited, counter);
        }
    }
}
bool cycle(int start, int parent, map<int, vector<int>> &graph, vector<bool> &visited1)
{
    visited1[start] = true;
    for (auto x : graph[start])
    {
        if (visited1[x] == false)
        {
            return cycle(x, start, graph, visited1);
        }
        else
        {
            if (x != parent)
            {
                return true;
            }
        }
    }
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
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> graph;
    int left, right;
    for (int i = 0; i < m; ++i)
    {
        cin >> left >> right;
        graph[left].push_back(right);
        graph[right].push_back(left);
    }
    vector<bool> visited(n + 1, false);
    int answer = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (visited[i] == false)
        {
            vector<bool> visited1(n + 1, false);
            if (cycle(i, i, graph, visited1) == true)
            {
                int counter = 0;
                dfs(i, graph, visited, counter);
                if (counter > 1 && counter % 2 == 1)
                {
                    answer++;
                }
            }
        }
    }
    if (n % 2 == 1)
    {
        if (answer % 2 == 0)
        {
            answer++;
        }
    }
    else
    {
        if (answer % 2 == 1)
        {
            answer++;
        }
    }
    cout << answer << "\n";
}