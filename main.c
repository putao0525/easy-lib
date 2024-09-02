#include <stdio.h>
#include "easy_tools.h"


void testNumber() {
    int a = 5;
    int b = 3;
    int c = NUM_MIN(a, b);
//    EASY_LOG("最小值：%d", c);
}

void testLog() {
    EASY_LOG_INFO("This is a red log message with value: %d", 22);
}

int main(void) {
    testNumber();
    testLog();
    return 0;
}