//
// Created by putao on 2024/9/2.
//
///日志相关的工具类

#ifndef EASY_LIB_EASY_LOG_H
#define EASY_LIB_EASY_LOG_H
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
    const char* color; \
    switch (level) { \
        case EASY_LOG_LEVEL_DEBUG: color = COLOR_CYAN; break; \
        case EASY_LOG_LEVEL_INFO:  color = COLOR_GREEN; break; \
        case EASY_LOG_LEVEL_WARN:  color = COLOR_YELLOW; break; \
        case EASY_LOG_LEVEL_ERROR: color = COLOR_RED; break; \
        default: color = COLOR_RESET; break; \
    } \
    printf("%s[%s:%d] " fmt "%s\n", color, __FILE__, __LINE__, ##__VA_ARGS__, COLOR_RESET); \
} while (0)

#endif //EASY_LIB_EASY_LOG_H
