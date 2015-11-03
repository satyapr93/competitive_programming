/*
 *You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 *Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 *Output: 7 -> 0 -> 8
 */

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
#define MK make_pair
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

template<typename Iter>
ostream& _out(ostream &os, Iter b, Iter e ) {
    os<<"[";
    for (Iter it=b; it!=e; ++it) 
        os<<(it==b?"":" ")<<*it;
    os<<"]";
    return os;
}

template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  return os<<"("<<p.first<<", "<<p.second<<")";
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

inline void FAST_IO() {
    std::ios_base::sync_with_stdio(false);
}


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       if(l1 == nullptr) {
           return l2;
       } else if (l2 == nullptr) {
           return l1;
       }
       ListNode* result = nullptr;
       ListNode* result_head = nullptr;
       int c = 0;
       while(l1 != nullptr || l2 != nullptr) {
           int d1 = 0;
           if(l1 != nullptr) {
               d1 = l1->val;
               l1 = l1->next;
           }
           int d2 = 0;
           if(l2 != nullptr) {
               d2 = l2->val;
               l2 = l2->next;
           }
           int res = d1 + d2 + c;
           ListNode* node = new ListNode(res % 10);
           if(result == nullptr) {
               result = node;
               result_head = result;
           } else {
               result -> next = node;
               result = result->next;
           }
           c = res / 10 ;
       }
       if(c != 0) {
           result -> next = new ListNode(c);
       }
       return result_head;
    }
};
int main(int argc, char* argv[]) {
    FAST_IO();
    Solution s;
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* res = s.addTwoNumbers(l1, l2);

    while(res != nullptr) {
        cout<<res->val<<" ";
        res = res->next;
    }
    cout<<"\n";
}


// Mistack 1 : forgot about last c.
// Mistake 2 : read the question wrong. both numbers are in reverse order.
