#include <iostream>
#include <fstream>

#include <algorithm>
#include <cassert>
#include <sstream>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <list>
#include <string>


using namespace std;
using ull = unsigned long long;
using vecd = std::vector<double>;
using veci = std::vector<int>;
using seti = std::unordered_set<int>;


struct InputData {
    size_t n;
    vector<int> v;
    InputData(istream & ids) {
        ids >> n;
        v.resize(n);
        for (size_t i = 0; i < n; ++i) {
            ids >> v[i];
        }
        assert(n > 0);
    }
};

#if INPUT_SOURCE == GENERATE_RANDOM_INPUT
InputData GenerateRandomInput() {
    static_assert(false, "TODO");
}
#endif

struct OutputData {
    string s;

    void Print(ostream & o) const {
        o << s;
        o << endl;
    }

#if TEST_TYPE == DO_TEST_BY_ASSERT
    bool Validate() const {
        static_assert(false, "TODO");
    }
#endif
};

OutputData Execute(const InputData & data) {
    OutputData ret;

    ull counter = 0;
    for (int e : data.v) {
        if (e == 0)
            ++counter;
    }
    counter = 1;

    if (counter % 2 == 1 && data.v.back() == 0) {
        stringstream ss;
        ss << "YES" << endl;
        for (size_t i = 0; i < data.n - 1; ++i)
            ss << "(";
        ss << data.v.front();
        for (size_t i = 1; i < data.n; ++i)
            ss << "->" << data.v[i] << ")";
        ret.s = ss.str();

    }
    else
        ret.s = "NO";

    return ret;
}




int main()
{
#ifdef OUTPUT_TO_FILE
    std::ofstream ofs(OUTPUT_TO_FILE);
#define ods ofs
#else
#define ods std::cout
#endif

    try {

#ifdef DO_TESTS
        int testSize = -1;
#if INPUT_SOURCE == LOAD_INPUT_FROM_FILE
        std::ifstream ifs(INPUT_FILE);
        cout << "LOCAL INPUT" << "  " << INPUT_FILE << endl;
        ifs >> testSize;
#elif INPUT_SOURCE == GENERATE_RANDOM_INPUT
        testSize = ITERATIONS
#endif
        assert(testSize >= 0);
        for (size_t i = 0; i < static_cast<size_t>(testSize); ++i) {

            cout << "Test № " << i + 1 << std::endl;
#if INPUT_SOURCE == LOAD_INPUT_FROM_FILE
            InputData src(ifs);
#elif INPUT_SOURCE == GENERATE_RANDOM_INPUT
            InputData src = GenerateRandomInput();
#endif
            OutputData dst = Execute(src);
#if TEST_TYPE == DO_TEST_BY_COMPARISON

#elif TEST_TYPE == DO_TEST_BY_ASSERT
            assert(dst.Validate());
#endif
            dst.Print(ods);
            cout << std::endl;
        }
        cout << "All tests completed!" << endl << endl;

#else
        InputData src(std::cin);
        OutputData dst = Execute(src);
        dst.Print(ods);
#endif
    }
    catch(const std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
