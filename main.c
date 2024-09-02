#include <stdio.h>
#include "easy_tools.h"


void testNumber() {
    int a = 5;
    int b = 3;
    int c = EASY_NUM_MAX(a, b);
    EASY_LOG_INFO("最小值：%d", c);
    EASY_LOG_ERROR("最小值不符合预期：%d", c);
    EASY_LOG_WARN("最小值不符合预期：%d", c);
    EASY_LOG_DEBUG("最小值不符合预期：%d", c);

}

void testLog() {
    EASY_LOG_INFO("This is a red log message with value: %d", 22);
}

void testArray() {
    int arr[5] = {1, 2, 3, 4, 5};
    int size = EASY_ARRAY_SIZE_EASY(arr);
    EASY_LOG_INFO("数组的大小:%d", size);

}

void testTime() {
    struct tm *currentTime = easy_get_current_time();
    char *xx = easy_format_time(currentTime, NORM_DATETIME_PATTERN);
    EASY_LOG_INFO("当前时间:%s", xx);
    EASY_DELETE(xx);//使用之后，进行释放
}

typedef struct {
    char name[50];
} Teacher;
typedef struct {
    char name[50];
    int age;
    Teacher teacher;
} Person;


void test_ptr() {
    Person *p2 = EASY_INIT(Person, { .name = "John", .age = 23, .teacher = {.name = "baba"}});
    if (p2 == NULL) {
        EASY_LOG_INFO("p2 is NULL");
    }
    EASY_LOG_INFO("name:%s, aga:%d, teacherName:%s", p2->name, p2->age, p2->teacher.name);
    EASY_DELETE(p2);

    Person *p3 = EASY_NEW(Person);
    if (p3 != NULL) {
        strcpy(p3->name, "John");
    }
    EASY_LOG_INFO("p32--> name:%s", p3->name);
    EASY_DELETE(p3);

}

int main(void) {
    testNumber();
    testLog();
    testArray();
    testTime();
    test_ptr();
    return 0;
}