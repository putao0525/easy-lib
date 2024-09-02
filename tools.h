//
// Created by putao on 2024/9/2.
//

#ifndef EASY_LIB_TOOLS_H
#define EASY_LIB_TOOLS_H
///数字类型
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
///数组相关
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
///未定义类别
#define SWAP(a, b) do { typeof(a) temp = (a); (a) = (b); (b) = temp; } while (0)
#define ALIGN(x, a) (((x) + ((a) - 1)) & ~((a) - 1))
///日志类型
#define EASY_LOG(fmt, ...) printf("[%s:%d] " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#endif //EASY_LIB_TOOLS_H
