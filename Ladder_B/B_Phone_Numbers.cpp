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
bool check_taxi(string &str)
{
    set<char> st;
    for (auto x : str)
    {
        if (x != '-')
        {
            st.insert(x);
        }
    }
    return (st.size() == 1);
}
bool check_pizza(string &str)
{
    vector<int> vt;
    for (auto x : str)
    {
        if (x != '-')
        {
            vt.push_back(x - '0');
        }
    }
    for (int i = 0; i + 1 < vt.size(); ++i)
    {
        if (vt[i] <= vt[i + 1])
        {
            return false;
        }
    }
    return true;
}
tuple<int, int, int> Calc(vector<string> &vt)
{
    tuple<int, int, int> tp;
    int count_taxi = 0, count_pizza = 0, count_girls = 0;
    for (int i = 0; i < vt.size(); ++i)
    {
        if (check_taxi(vt[i]) == true)
        {
            count_taxi++;
        }
        else if (check_pizza(vt[i]) == true)
        {
            count_pizza++;
        }
        else
        {
            count_girls++;
        }
    }
    tp = make_tuple(count_taxi, count_pizza, count_girls);
    return tp;
}
void Display_taxi(vector<string> &vt)
{
    cout << "If you want to call a taxi, you should call: ";
    for (int i = 0; i < vt.size(); ++i)
    {
        if (i == vt.size() - 1)
        {
            cout << vt[i];
        }
        else
        {
            cout << vt[i] << ", ";
        }
    }
    cout << ".\n";
}
void Display_pizza(vector<string> &vt)
{
    cout << "If you want to order a pizza, you should call: ";
    for (int i = 0; i < vt.size(); ++i)
    {
        if (i == vt.size() - 1)
        {
            cout << vt[i];
        }
        else
        {
            cout << vt[i] << ", ";
        }
    }
    cout << ".\n";
}
void Display_girls(vector<string> &vt)
{
    cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
    for (int i = 0; i < vt.size(); ++i)
    {
        if (i == vt.size() - 1)
        {
            cout << vt[i];
        }
        else
        {
            cout << vt[i] << ", ";
        }
    }
    cout << ".\n";
}
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
    map<string, vector<string>> phone_numbers;
    map<int, vector<string>, greater<int>> taxi, pizza, girls;
    for (int i = 0; i < n; ++i)
    {
        int size;
        cin >> size;
        string name;
        cin >> name;
        for (int j = 0; j < size; ++j)
        {
            string temp;
            cin >> temp;
            phone_numbers[name].push_back(temp);
        }
        tuple<int, int, int> counts = Calc(phone_numbers[name]);
        taxi[get<0>(counts)].push_back(name);
        pizza[get<1>(counts)].push_back(name);
        girls[get<2>(counts)].push_back(name);
    }
    Display_taxi(taxi.begin()->second);
    Display_pizza(pizza.begin()->second);
    Display_girls(girls.begin()->second);
}