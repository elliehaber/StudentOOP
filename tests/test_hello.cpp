#include <cassert>
#include "../my_code/hello.h"
//comment
using namespace std;

int main() {
        int ret = sayHello();
    assert(ret == 0);
    return ret;
}
