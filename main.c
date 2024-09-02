#include <stdio.h>
#include "tools.h"


void testNumber() {
    int a = 5;
    int b = 3;
    int c = MIN(a, b);
    SELF_LOG("最小值：%d", c);
}

int main(void) {
    testNumber();
    return 0;
}