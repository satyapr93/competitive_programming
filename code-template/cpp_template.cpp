//
//  Created by Satya Prakash.
//  Copyright (c) 2015 Satya Prakash. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <array>
#include <tuple>
#include <cmath>
#include <ctime>
#include <numeric>
#include <limits>
#include <iterator>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <utility>

using namespace std;

typedef int64_t llong;
typedef unsigned int uint;
typedef long double ldouble;

typedef const int cint;
typedef const int64_t cllong;
typedef const double cdouble;
typedef const unsigned int cuint;
typedef const long double cldouble;
typedef const uint64_t cullong;

typedef pair<int, int> pii;
typedef vector<int> veci;
typedef vector<vector<int>> vec2i;
typedef vector<vector<llong>> vec2l;
typedef vector<vector<double>> vec2d;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define per(i, n) for (int i = (n); i >= 0; --i)

#define forn(i, a, b) for (int i = (a); i < (b); ++i)
#define forr(i, a, b) for (int i = (a); i >= (b); --i)

#define fori(it, list) for (auto it = list.begin(); it != list.end(); ++it)
#define forri(it, list) for (auto it = list.rbegin(); it != list.rend(); ++it)

#define all(a) (a).begin(), (a).end()
#define elif(x) else if (x)
#define fill(c, v) std::fill(ALL(c), v)
#define filla(a, b) memset(a, b, sizeof(a))

#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define eb(x) emplace_back(x)

#define dbg(x) std::cerr << "x = " << x << "\n";

#define gcd(x, y) __gcd(x, y)
#define bitcount __builtin_popcount

#define nl "\n"

const double PI = M_PI;
const double EPS = 1e-7;

template<typename T>
constexpr T pi = T(M_PI);

template<typename T>
constexpr T MIN = std::numeric_limits<T>::min();

const double MIN_DOUBLE = std::numeric_limits<double>::min();
const double MAX_DOUBLE = std::numeric_limits<double>::max();

template<class ForwardIt, class T, class Compare>
ForwardIt binary_searchl(ForwardIt first, ForwardIt last, const T& value, Compare comp) {
    first = std::lower_bound(first, last, value, comp);
    if (!(first == last) && !(comp(value, *first))) {
        return first;
    } else {
      return last;
    }
}

template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}

template<typename Iter>
ostream& _out(ostream& os, const Iter& b, const Iter& e ) {
    os << "[";
    for (Iter it=b; it != e; ++it)
        os<< (it == b?"":" ") << *it;
    os << "]";
    return os;
}

template <typename T, size_t N>
ostream& operator<<(ostream& os, const array<T, N>& v) {
  return _out(os, ALL(v));
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  return _out(os, ALL(v));
}

template <typename T1, typename T2>
ostream& operator<<(ostream& os, const map<T1, T2>& m) {
  return _out(os, all(m));
}

template <typename T>
ostream& operator<<(ostream& os, const set<T>& s) {
  return _out(os, all(s));
}

struct pairhash {
 public:
    template <typename T1, typename T2>
        size_t operator()(const pair<T1, T2> &p) const {
            return std::hash<T1>()(p.first) ^ std::hash<T2>()(p.second);
        }
};

/*
 *namespace std {
 *    template<>
 *    bool operator==(const pii& p1, const pii& p2) {
 *        return p1.first == p2.first;
 *    }
 *}
 */

inline void fast_io() {
    std::ios_base::sync_with_stdio(false);
}

const int64_t MOD = 1000000007LL;

int main(int argc, char* argv[]) {
    fast_io();
    forn (i, 0, 10) {
        cout<< i << nl;
    }
    cout<< MIN<double> << nl;
}
