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
void Transform_string(string &alpha)
{
    int n = alpha.length();
    bool flag = true;
    while (flag == true)
    {
        flag = false;
        int low = 0, high = n - 1;
        while (low < n)
        {
            if (alpha[high] == '9')
            {
                high--;
            }
            else if (alpha[low] == '0')
            {
                low++;
            }
            else
            {
                if ((low == 0 && alpha[low] > '1') || (alpha[low] > '0'))
                {
                    int can_added;
                    if (low == 0)
                    {
                        can_added = 8 - (alpha[high] - '0');
                    }
                    else
                    {
                        can_added = 9 - (alpha[high] - '0');
                    }
                    int more = alpha[low] - '0';
                    int val = min(can_added, more);
                    alpha[low] -= val;
                    alpha[high] += val;
                    flag = true;
                    if (alpha[high] == '9')
                    {
                        high--;
                    }
                    if (alpha[low] == '0')
                    {
                        low++;
                    }
                }
                else
                {
                    low++;
                }
            }
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    // freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int length, sum, temp;
    cin >> length >> sum;
    temp = sum;
    if (sum == 0)
    {
        if (length == 1)
        {
            cout << "0 0\n";
        }
        else
        {
            cout << "-1 -1\n";
        }
    }
    else if (length == 1)
    {
        if (sum <= 9)
        {
            cout << sum << " " << sum << "\n";
        }
        else
        {
            cout << "-1 -1\n";
        }
    }
    else
    {
        if (sum <= 9)
        {
            string large, small;
            small.push_back('1');
            for (int i = 1; i < length - 1; ++i)
            {
                small.push_back('0');
            }
            small.push_back((sum - 1) + '0');
            large.push_back(sum + '0');
            for (int i = 1; i < length; ++i)
            {
                large.push_back('0');
            }
            cout << small << " " << large << "\n";
        }
        else
        {
            string number;
            for (int i = 0; i < length; ++i)
            {
                if (sum > 9)
                {
                    number.push_back('9');
                    sum -= 9;
                }
                else
                {
                    break;
                }
            }
            if (number.length() != length)
            {
                int pos = length - number.length();
                for (int i = 0; i < pos - 1; ++i)
                {
                    number.push_back('0');
                }
                number.push_back(sum + '0');
            }
            int size = number.length();
            string small_number;
            small_number = number;
            sort(number.rbegin(), number.rend());
            sort(small_number.begin(), small_number.end());
            if (small_number[0] == '0')
            {
                for (int i = 0; i < length; ++i)
                {
                    if (small_number[i] > '0')
                    {
                        small_number[i]--;
                        small_number[0] = '1';
                        break;
                    }
                }
            }
            bool exist = true;
            int sum1 = 0;
            for (auto x : number)
            {
                sum1 += (x - '0');
                if (x < '0' || x > '9')
                {
                    exist = false;
                    break;
                }
            }
            if ((number.length() == length) && (sum1 == temp) && (exist == true))
            {
                cout << small_number << " " << number << "\n";
            }
            else
            {
                cout << "-1 -1\n";
            }
        }
    }
}