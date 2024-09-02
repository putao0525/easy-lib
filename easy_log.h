//
// Created by putao on 2024/9/2.
//
///日志相关的工具类

#ifndef EASY_LIB_EASY_LOG_H
#define EASY_LIB_EASY_LOG_H
#include <time.h>

// 获取当前时间并格式化
#define CURRENT_TIME() ({ \
    time_t rawtime; \
    struct tm * timeinfo; \
    static char buffer[20]; \
    time(&rawtime); \
    timeinfo = localtime(&rawtime); \
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo); \
    buffer; \
})

// 定义颜色代码
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_RESET   "\033[0m"

// 定义日志级别
#define EASY_LOG_LEVEL_DEBUG 0
#define EASY_LOG_LEVEL_INFO  1
#define EASY_LOG_LEVEL_WARN  2
#define EASY_LOG_LEVEL_ERROR 3

// 定义日志宏
#define EASY_LOG_DEBUG(fmt, ...) PRIVATE_EASY_LOG(EASY_LOG_LEVEL_DEBUG, fmt, ##__VA_ARGS__)
#define EASY_LOG_INFO(fmt, ...)  PRIVATE_EASY_LOG(EASY_LOG_LEVEL_INFO, fmt, ##__VA_ARGS__)

#define EASY_LOG_WARN(fmt, ...)  PRIVATE_EASY_LOG(EASY_LOG_LEVEL_WARN, fmt, ##__VA_ARGS__)
#define EASY_LOG_ERROR(fmt, ...) PRIVATE_EASY_LOG(EASY_LOG_LEVEL_ERROR, fmt, ##__VA_ARGS__)

// 内部使用的日志宏
#define PRIVATE_EASY_LOG(level, fmt, ...) do { \
    const char* level_str; \
    const char* color; \
    switch (level) { \
        case EASY_LOG_LEVEL_DEBUG: level_str = "DEBUG"; color = COLOR_CYAN; break; \
        case EASY_LOG_LEVEL_INFO:  level_str = "INFO"; color = COLOR_GREEN; break; \
        case EASY_LOG_LEVEL_WARN:  level_str = "WARN"; color = COLOR_YELLOW; break; \
        case EASY_LOG_LEVEL_ERROR: level_str = "ERROR"; color = COLOR_RED; break; \
        default: level_str = "UNKNOWN"; color = COLOR_RESET; break; \
    } \
    printf("%s [%s:%d] %s[%s]%s " fmt "\n", CURRENT_TIME(), __FILE__, __LINE__, color, level_str, COLOR_RESET, ##__VA_ARGS__); \
} while (0)

#endif //EASY_LIB_EASY_LOG_H
