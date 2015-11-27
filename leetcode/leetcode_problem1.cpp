
//
//  Created by Satya Prakash.
//  Copyright (c) 2015 Satya Prakash. All rights reserved.
//

/*
 *Given an array of integers, find two numbers such that they add up to a
 *specific target number.
 *
 *The function twoSum should return indices of the two numbers such that they
 *add up to the target, where index1 must be less than index2. Please note
 *that your returned answers (both index1 and index2) are not zero-based.
 *
 *You may assume that each input would have exactly one solution.
 *
 *Input: numbers={2, 7, 11, 15}, target=9
 *Output: index1=1, index2=2
 */

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

#define NL "\n"

const double PI = M_PI;
const double EPS = 1e-7;

template<typename T>
constexpr T pi = T(M_PI);

template<typename T>
constexpr T MIN = std::numeric_limits<T>::min();

const double MIN_DOUBLE = std::numeric_limits<double>::min();
const double MAX_DOUBLE = std::numeric_limits<double>::max();

template<class Iter, class T, class Compare>
Iter binary_searchl(Iter first, Iter last, const T& value, Compare comp) {
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
    return _out(os, all(v));
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    return _out(os, all(v));
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

class Solution {
 public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pii> orig(nums.size());
        int index = -1;

        std::transform(all(nums), orig.begin(), [&index](int& num) {
                ++index; return mp(num, index);
                });

        sort(all(orig));
        cerr<< orig;
        for (const auto& p : orig) {
            pii temp {target - p.first, p.second};
            cerr<< " PAIR : " << p;

            auto it = binary_searchl(all(orig), temp, [](const pii& p, const pii& t) {
                        return p.first < t.first;
                        });

            if (it != orig.end() && it->second != temp.second) {
                cerr<< "num : " << p.first << ", num2 : " << it->first << "\n";
                cerr<< "index1 : " << p.second << ", index2 : " << it->second << "\n";
                if (p.second > it->second) {
                    return {it->second+1, p.second+1};
                }
                return {p.second+1, it->second+1};
            }
        }
        return {0};
    }
};

int main(int argc, char* argv[]) {
    fast_io();
    vector<int> v {150, 50, 23, 34, 350, 5};
    Solution s;
    cout<< s.twoSum(v, 200);
}
// Mistake 3 : wrong find function.
