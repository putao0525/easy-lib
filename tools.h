//
// Created by putao on 2024/9/2.
//

#ifndef EASY_LIB_TOOLS_H
#define EASY_LIB_TOOLS_H
///数字类型
#ifndef NUM_MIN
#define NUM_MIN(a, b) ((a) < (b) ? (a) : (b))
#endif

#ifndef NUM_MAX
#define NUM_MAX(a, b) ((a) < (b) ? (a) : (b))
#endif

///数组相关
#ifndef ARRAY_SIZE
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#endif
///位操作
//todo
///未定义类别
//todo
#define SWAP(a, b) do { typeof(a) temp = (a); (a) = (b); (b) = temp; } while (0)
#define ALIGN(x, a) (((x) + ((a) - 1)) & ~((a) - 1))
///日志类型
#ifndef EASY_LOG
#define EASY_LOG(fmt, ...) printf("[%s:%d] " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif


#endif //EASY_LIB_TOOLS_H
