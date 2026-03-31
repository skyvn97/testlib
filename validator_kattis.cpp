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

const int MAX_N = (int)5e3;
const int MAX_C = (int)1e6;

struct Point {
    int x, y;

    Point(int _x = 0, int _y = 0) {
        x = _x; y = _y;
    }

    Point(InStream &stream, const string &name) {
        x = stream.readInt(0, MAX_C, name + ".x"); inf.readSpace();
        y = stream.readInt(0, MAX_C, name + ".y");
    }

    Point operator - (const Point &p) const {
        return Point(x - p.x, y - p.y);
    }

    long long operator % (const Point &p) const {
        return 1LL * x * p.y - 1LL * p.x * y;
    }
};

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	int numTest = inf.readInt(1, INT_MAX, "number of tests"); inf.readEoln();

	int sumN = 0;
	FOR(test, 1, numTest) {
		setTestCase(test);

		int numPoint = inf.readInt(1, MAX_N, "number of points"); inf.readEoln();

		sumN += numPoint; ensure(sumN <= MAX_N);

		vector<Point> points(numPoint);
		REP(i, numPoint) {
            points[i] = Point(inf, format("points[%d]", i + 1)); inf.readEoln();
		}
		REP(i, numPoint) {
            int j = (i + 1) % numPoint;
            int k = (i + 2) % numPoint;
            ensure((points[i] - points[j]) % (points[k] - points[j]) < 0);
            ensure((points[j] - points[i]) % (points[k] - points[i]) > 0);
		}
	}

	inf.readEof();
	return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/
