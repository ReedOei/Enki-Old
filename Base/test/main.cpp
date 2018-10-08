//
// Created by roei on 10/8/18.
//

#include <iostream>
#include <rapidcheck.h>

void test_func(const std::vector<int> &vec) {
    auto t = vec;
    std::reverse(t.begin(), t.end());
    std::reverse(t.begin(), t.end());
    RC_ASSERT(t == vec);
}

int main() {
    rc::check("simple test", test_func);

    return 0;
}
