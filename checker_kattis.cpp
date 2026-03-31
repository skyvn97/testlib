/// Problem details: https://oj.vnoi.info/problem/icpc25_regional_h

#include "testlib_kattis.h"

#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE. **/

using ld = long double;
const ld EPS = 1e-6;

#define MAX   5050
int numPoint;
pair<ld, ld> points[MAX];

void init(void) {
    numPoint = inf.readInt();
    FOR(i, 1, numPoint) {
        points[i].fi = inf.readInt();
        points[i].se = inf.readInt();
    }
}

ld getDistance(int a, int b) { return hypot(points[a].fi - points[b].fi, points[a].se - points[b].se); }

/**
 * Things to check:
 * - No vertex is visited twice.
 * - The actual path length matches the printed one.
**/

int perm[MAX], id[MAX];

ld checkAnswer(InStream &stream) {
    memset(id, -1, sizeof id);
    FOR(i, 1, numPoint) {
        perm[i] = stream.readInt(1, numPoint, format("points[%d]", i));

        // No vertex is visited twice.
        if (id[perm[i]] > 0) {
            int j = id[perm[i]];
            stream.quitf(_wa, "perm[%d] = perm[%d] = %d", i, j, perm[i]);
        } else id[perm[i]] = i;
    }

    ld actual = 0;
    FOR(i, 1, numPoint - 1) actual += getDistance(perm[i], perm[i + 1]);

    return actual;
}

void process(void) {
    // doubleCompare still uses double instead of long double
    // tho at this point it only truncates precision
    double cont = checkAnswer(ouf);
    double jury = checkAnswer(ans);
    if (!doubleCompare(jury, cont, EPS)) {
        if (cont > jury) quitf(_wa, "Jury has better answer: jury = %.7lf, contestant = %.7lf, error = %.7lf",
                                    jury, cont, doubleDelta(jury, cont));
        if (cont < jury) quitf(_fail, "Jury has worse answer: jury = %.7lf, contestant = %.7lf, error = %.7lf",
                                    jury, cont, doubleDelta(jury, cont));
    }
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    int numTest = inf.readInt();
    FOR(test, 1, numTest) {
        setTestCase(test);
        init();
        process();
    }

    quitf(_ok, "T1win");
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/
