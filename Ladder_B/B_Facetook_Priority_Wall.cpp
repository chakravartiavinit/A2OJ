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
map<string, int> value;
int type(string a)
{
    int words = 1;
    for (int i = 0; i < a.length(); ++i)
    {
        if (a[i] == ' ')
        {
            words++;
        }
    }
    if (words == 4)
    {
        return 3;
    }
    string temp1 = "posted on";
    if (a.find(temp1) != string::npos)
    {
        return 1;
    }
    return 2;
}
pair<string, string> Names(string a)
{
    int query = type(a);
    string name1, name2;
    int index;
    for (int i = 0; i < a.length(); ++i)
    {
        if (a[i] == ' ')
        {
            index = i;
            break;
        }
        else
        {
            name1.push_back(a[i]);
        }
    }
    if (query == 1)
    {
        index += 11;
    }
    else if (query == 2)
    {
        index += 14;
    }
    else
    {
        index += 7;
    }
    for (int i = index; i < a.length(); ++i)
    {
        if (a[i] == 39)
        {
            break;
        }
        else
        {
            name2.push_back(a[i]);
        }
    }
    return {name1, name2};
}
void add_names_and_values(string a, string name)
{
    int query = type(a);
    pair<string, string> p1 = Names(a);
    string n1 = p1.first;
    string n2 = p1.second;
    if ((n1 == name) || (n2 == name))
    {
        if (query == 1)
        {
            value[n1] += 15;
            value[n2] += 15;
        }
        else if (query == 2)
        {
            value[n1] += 10;
            value[n2] += 10;
        }
        else if (query == 3)
        {
            value[n1] += 5;
            value[n2] += 5;
        }
    }
    else
    {
        value[n1] += 0;
        value[n2] += 0;
    }
}
bool compare(string a, string b)
{
    if (value[a] > value[b])
    {
        return true;
    }
    else if (value[a] == value[b])
    {
        if (a < b)
        {
            return true;
        }
        return false;
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
    string name;
    cin >> name;
    int n;
    cin >> n;
    set<string> all_names;
    for (int i = 0; i <= n; ++i)
    {
        string temp;
        getline(cin, temp);
        if (temp.size() != 0)
        {
            add_names_and_values(temp, name);
        }
    }
    vector<string> vt_names;
    for (auto x : value)
    {
        if (x.first != name)
        {
            vt_names.push_back(x.first);
        }
    }
    sort(vt_names.begin(), vt_names.end(), compare);
    for (auto x : vt_names)
    {
        cout << x << "\n";
    }
}