
//
//  Created by Satya Prakash.
//  Copyright (c) 2015 Satya Prakash. All rights reserved.
//

/*
 *Given an array of integers, find two numbers such that they add up to a specific target number.
 *
 *The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
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

using std::vector;
using std::string;
using std::set;
using std::map;
using std::queue;
using std::stack;
using std::cin;
using std::cout;
using std::clog;
using std::cerr;
using std::ceil;
using std::min;
using std::max;
using std::abs;
using std::fabs;
using std::swap;
using std::array;
using std::pair;
using std::sort;
using std::ostream;
using std::make_pair;
using std::multiset;
using std::multimap;
using std::unordered_set;
using std::unordered_map;
using std::priority_queue;

typedef long long llong;
typedef unsigned int uint;
typedef long double ldouble;
typedef unsigned long ulong;
typedef unsigned long long ullong;

typedef const int cint;
typedef const long clong;
typedef const double cdouble;
typedef const long long cllong;
typedef const unsigned int cuint;
typedef const long double cldouble;
typedef const unsigned long culong;
typedef const unsigned long long cullong;

typedef pair<int, int> pii;

#define REP(i, n) for(size_t i = 0; i < (n); ++i)
#define PER(i, n) for(int i = (n); i >= 0; --i)

#define FOR(i, a, b) for(size_t i = (a); i < (b); ++i)
#define FORR(i, a, b) for(size_t i = (a); i >= (b); --i)

#define FORI(it, list) for(auto it = list.begin(); it != list.end(); ++it)
#define FORRI(it, list) for(auto it = list.rbegin(); it != list.rend(); ++it)

#define ALL(a) (a).begin(), (a).end()
#define ELIF else if
#define NL "\n"
#define FILL(a, b) memset(a, b, sizeof(a))
#define FILLI(c, v) std::fill(ALL(c), v)

#define PB push_back
#define MP make_pair
#define EB emplace_back

#define DBG(x) std::cerr<<"x = "<<x<<"\n";

const double PI = M_PI;
const double EPS = 1e-7;

const int MAX_INT = std::numeric_limits<int>::max();
const double MAX_DOUBLE = std::numeric_limits<double>::max();
const long long MAX_LLONG = std::numeric_limits<long long>::max();
const unsigned int MAX_UINT = std::numeric_limits<unsigned int>::max();
const unsigned long long MAX_ULLONG = std::numeric_limits<unsigned long long>::max();

const int MIN_INT = std::numeric_limits<int>::min();
const double MIN_DOUBLE = std::numeric_limits<double>::min();
const long long MIN_LLONG = std::numeric_limits<long long>::min();

const long long MOD = 1000000007LL;

#define gcd __gcd
#define bitcount __builtin_popcount

template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  return os<<"("<<p.first<<", "<<p.second<<")";
}

template<typename Iter>
ostream& _out(ostream &os, Iter b, Iter e ) {
    os<<"[";
    for (Iter it=b; it!=e; ++it) 
        os<<(it==b?"":" ")<<*it;
    os<<"]";
    return os;
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

inline void FAST_IO() {
    std::ios_base::sync_with_stdio(false);
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pii> orig(nums.size());
        int index = -1;
        std::transform(std::begin(nums), std::end(nums), std::begin(orig), [&index](int& num) { ++index; return MP(num, index);});
        sort(ALL(orig));
        cerr<<orig;
        for(const auto& p : orig) {
            pii temp {target - p.first, p.second};
            auto it = std::lower_bound(ALL(orig), temp, [](const pii& p, const pii& t) { return p.first < t.first; }); 
            if (it != orig.end() && it->second != temp.second) {
                cerr<<"NUM : "<<p.first<<", NUM2 : "<<it->first<<"\n";
                cerr<<"Index1 : "<<p.second<<", Index2 : "<<it->second<<"\n";
                return {int(p.second+1), int(it->second+1)};
            }
        }
        return {0};
    }
};

int main(int argc, char* argv[]) {
    FAST_IO();
    vector<int> v {3, 2, 4};
    Solution s;
    cout<<s.twoSum(v, 6);
}

// Mistake 3 : index should be in order.
