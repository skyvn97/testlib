/// Problem details: https://lqdoj.edu.vn/problem/cup2025r4p2

#include "testlib_themis_cms.h"

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

#define MAX   2207

int numValue, numDigit;
string input[MAX], output[MAX];
pattern valuePattern("[A-Z]{1}"); // some dummy things

int jury, cont;

void init(void) {
    numValue = inf.readInt();
    numDigit = inf.readInt();
    FOR(i, 1, numValue) input[i] = inf.readWord();
    valuePattern = pattern(testlib_format_("[0-9]{%d}", numDigit));
}

/**
 * Things to check:
 * - The values after changes form an increasing sequence.
 * - The number of changed digit matches the printed value.
**/

void checkAnswer(InStream &stream) {
    int &printed = stream.mode == _answer ? jury : cont;
    printed = stream.readInt(0, numValue * numDigit, "number of changes");
    if (stream.mode == _output) {
        if (jury == cont) {
            setMinimumPoint(0.36);
            setMessageNote(testlib_format_("number of changes matches: %d", jury));
        } else {
            setMessageNote(testlib_format_("number of changes mismatches: jury = %d, contestant = %d", jury, cont));
        }
    }

    FOR(i, 1, numValue) output[i] = stream.readWord(valuePattern, testlib_format_("values[%d]", i));

    // The values after changes form an increasing sequence.
    FOR(i, 2, numValue) if (output[i] <= output[i - 1])
        stream.quitf(_wa, "values[%d] is not less than value[%d]", i - 1, i);

    // The number of changed digit matches the printed value.
    int cnt = 0;
    FOR(i, 1, numValue) REP(j, numDigit) if (input[i][j] != output[i][j]) cnt++;
    if (cnt != printed) stream.quitf(_wa, "The printed number of changes is %d, but its actual value is %d", printed, cnt);
}

void process(void) {
    checkAnswer(ans);
    checkAnswer(ouf);

    quitif(jury == cont, _ok, "Correct solution");
    quitif(jury < cont, _wa, "Jury has better answer.");
    quitif(jury > cont, _fail, "Jury has worse answer.");
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    init();
    process();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/
