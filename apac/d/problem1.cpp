
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
#include <limits>
#include <numeric>
#include <climits>
#include <iterator>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

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

#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define per(i, n) for(int i = int(n); i >= 0; --i)

#define FOR(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forn(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forr(i, a, b) for(int i = int(a); i >= int(b); --i)

#define fori(it, list) for(auto it = list.begin(); it != list.end(); ++it)
#define forri(it, list) for(auto it = list.rbegin(); it != list.rend(); ++it)

#define all(a) (a).begin(), (a).end()
#define elif(x) else if(x)
#define init(a, b) memset(a, b, sizeof(a))

#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define eb(x) emplace_back(x)

#define dbg(x) std::cerr<<"x = "<<x<<"\n";

#define gcd(x, y) __gcd(x, y)
#define bitcount __builtin_popcount

#define cauto const auto&
#define NL "\n"
#define inRangeX(x) x>=0 && x<R
#define inRangeY(y) y>=0 && y<C

const double PI = M_PI;
const double EPS = 1e-7;

const double DOUBLE_MIN = std::numeric_limits<double>::min();
const double DOUBLE_MAX = std::numeric_limits<double>::max();

template<class ForwardIt, class T, class Compare>
ForwardIt binary_searchl(ForwardIt first, ForwardIt last, const T& value, Compare comp) {
    first = std::lower_bound(first, last, value, comp);
    
    if (!(first == last) && !(comp(value, *first))) {
        return first;
    } else return last;
}

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

const long long MOD = 1000000007LL;

array<array<bool, 105>, 105> mat;
//int ptree[105][105] = {-1};
//array<array<int, 105>, 105> visited;
int visited[105][105] = {0};
//vector<set<pii>> trees;

int R, C;

//void dfs(int x, int y, int px, int py) {
    //if (mat[x][y] == true) {
        //if(px == -1 && py == -1) {
            //trees.push_back({mp(x, y)});
        //}
        //int treeid = ptree[px][py];
        //if ()

    //}
//}

void bdfs(int x, int y) {
    cout<<x<<" "<<y<<"\n";
    visited[x][y] = 1;
    int nx = x;
    int ny = y+1;
    if(inRangeX(nx) && inRangeY(ny) && visited[nx][nx] == 0 && mat[nx][ny] == 1){
        bdfs(nx, ny);
    }
    nx = x +1;
    ny = y;
    if(inRangeX(nx) && inRangeY(ny) && visited[nx][nx] == 0 && mat[nx][ny] == 1){
        bdfs(nx, ny);
    }
    nx = x -1;
    ny = y;
    if(inRangeX(nx) && inRangeY(ny) && visited[nx][nx] == 0 && mat[nx][ny] == 1){
        bdfs(nx, ny);
    }
    nx = x;
    ny = y -1;
    if(inRangeX(nx) && inRangeY(ny) && visited[nx][nx] == 0 && mat[nx][ny] == 1){
        bdfs(nx, ny);
    }
}
int main() {
    fast_io();
    int tc = 0;
    cin>>tc;
    forn(t, 1, tc+1) {
        cout<<"Case #"<<t<<": ";
        cin>>R>>C;
        forn(i, 0, R)
            forn(j, 0, C) {
                char temp;
                cin>>temp;
                mat[i][j] = int(temp - '0');
                visited[i][j] = 0;
            }
        
        int N = 0;
        cin>>N;
        forn(k, 0, N) {
            char op;
            cin>>op;
            int count = 0;
            if(op == 'Q'){
                forn(i, 0, R)
                    forn(j, 0, C) {
                        if(visited[i][j] == 0 && mat[i][j] == 1) {
                            bdfs(i, j);
                            count++;
                        }
                    }
                cout<<count<<NL;
            } else {
                int x, y, z;
                cin>>x>>y>>z;
                mat[x][y] = z;
            }
        }
    }
}
