//
// Created by putao on 2024/9/2.
//
/// time类型
// 标准日期时间格式定义

#ifndef EASY_TIME_PATTERN
#define EASY_TIME_PATTERN
#define NORM_YEAR_PATTERN               "%Y"
#define NORM_MONTH_PATTERN              "%Y-%m"
#define SIMPLE_MONTH_PATTERN            "%Y%m"
#define NORM_DATE_PATTERN               "%Y-%m-%d"
#define NORM_TIME_PATTERN               "%H:%M:%S"
#define NORM_DATETIME_MINUTE_PATTERN    "%Y-%m-%d %H:%M"
#define NORM_DATETIME_PATTERN           "%Y-%m-%d %H:%M:%S"
#define NORM_DATETIME_MS_PATTERN        "%Y-%m-%d %H:%M:%S.%L"
#define ISO8601_PATTERN                 "%Y-%m-%d %H:%M:%S,%L"
#define CHINESE_DATE_PATTERN            "%Y年%m月%d日"
#define CHINESE_DATETIME_PATTERN        "%Y年%m月%d日 %H时%M分%S秒"
#define PURE_DATE_PATTERN               "%Y%m%d"
#define PURE_TIME_PATTERN               "%H%M%S"
#define PURE_DATETIME_PATTERN           "%Y%m%d%H%M%S"
#define PURE_DATETIME_MS_PATTERN        "%Y%m%d%H%M%S%L"
#define HTTP_DATETIME_PATTERN           "%a, %d %b %Y %H:%M:%S %Z"
#define UTC_SIMPLE_PATTERN              "%Y-%m-%dT%H:%M:%S"
#define UTC_SIMPLE_MS_PATTERN           "%Y-%m-%dT%H:%M:%S.%L"
#define UTC_PATTERN                     "%Y-%m-%dT%H:%M:%S%z"
#define UTC_MS_PATTERN                  "%Y-%m-%dT%H:%M:%S.%L%z"
#endif

#ifndef EASY_TIME_H
#define EASY_TIME_H

#include <stdlib.h>
#include <string.h>


static struct tm *easy_get_current_time() {
    time_t rawtime;
    struct tm *timeinfo;
    // 获取当前时间
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    // 返回 struct tm 结构
    return timeinfo;
}

char *easy_format_time(const struct tm *timeinfo, const char *format) {
    // 定义一个临时缓冲区来存储格式化结果
    char temp_buffer[128];
    strftime(temp_buffer, sizeof(temp_buffer), format, timeinfo);
    char *formatted_time = (char *) malloc(strlen(temp_buffer) + 1);
    if (formatted_time != NULL) {
        strcpy(formatted_time, temp_buffer);
    }
    return formatted_time;
}

#endif

