//All {
//macros {
#include <bits/stdc++.h>
using namespace std;
#define LL_MAX LLONG_MAX
#define ll long long
#define vi vector<int>
#define v vector<long long>
#define yes cout << "YES" << '\n'
#define no cout << "NO" << '\n'
#define alice cout << "Alice" << '\n'
#define ft first
#define sd second
#define mp make_pair
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define Sort(x) sort((x).begin(), (x).end())
#define Size(x) (int)(x).size()
#define All(x) (x).begin(), (x).end()
#define Rall(x) (x).rbegin(), (x).rend()
#define Max(x) *max_element(All(x))
#define Min(x) *min_element(All(x))
#define Sum(x) accumulate(All(x), 0ll)
#define Find(x, y) binary_search(All(x), y)
#define Loop(n) for(int i = 0; i < n; i++)
#define bob cout << "Bob" << '\n'
#define jai_hind ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
//}

//functions{
template <typename T>
void in(vector<T>& temp) {
    for(int i = 0; i < Size(temp); i++) cin >> temp[i];
}

template <typename T>
void out(const vector<T>& a) {
    for(const auto& val : a) cout << val << " ";
    cout << endl;
}

template <typename T>
T gcd(T a, T b) {
    while (b != 0) {
        T temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

template <typename T>
T lcm(T a, T b) {
    return (a / gcd(a, b)) * b;
}

template <typename T>
T power_mod(T base, T exponent, T mod) {
    T result = 1;
    base = base % mod;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        exponent = exponent >> 1; // equivalent to exponent / 2
        base = (base * base) % mod;
    }
    return result;
}

// Function to calculate factorial % mod
template <typename T>
T fact(T n, T mod) {
    T fac = 1;
    for (T i = 1; i <= n; i++) {
        fac = (fac * i) % mod;
    }
    return fac;
}

// Function to calculate nCr % mod
template <typename T>
T nCr(T N, T K, T mod) {
    if (K > N) return 0;
    T numerator = fact(N, mod);
    T denominator = (fact(K, mod) * fact(N - K, mod)) % mod;
    return (numerator * power_mod(denominator, mod - 2, mod)) % mod;
}

// Check if a number is prime
bool isPrime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

// Check if a number is a power of two
bool isPowerOfTwo(int n) {
    if (n == 0) return false;
    return (ceil(log2(n)) == floor(log2(n)));
}

// Check if a number is a perfect square
bool isPerfectSquare(ll x) {
    if (x >= 0) {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}

//}

//segment Tree{
    class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(const vector<int> &input_data) {
        n = input_data.size();
        tree.resize(2 * n);
        
        // Build the tree
        for (int i = 0; i < n; ++i) {
            tree[n + i] = input_data[i];
        }
        for (int i = n - 1; i > 0; --i) {
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }

    void update(int idx, int val) {
        idx += n;
        tree[idx] = val;
        while (idx > 1) {
            idx /= 2;
            tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
        }
    }

    int query(int L, int R) {
        L += n;
        R += n;
        int sum = 0;
        while (L <= R) {
            if (L % 2 == 1) {
                sum += tree[L];
                L++;
            }
            if (R % 2 == 0) {
                sum += tree[R];
                R--;
            }
            L /= 2;
            R /= 2;
        }
        return sum;
    }
};
//}

//DSU{
    class DSU {
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // Union by rank
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};
//}

void solve();

int32_t main() {
  jai_hind;
  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
  #endif
  int tt;
  cin>>tt;
  while(tt--)
  solve();
   
}

//}
void solve() {
    jai_hind;
}
    