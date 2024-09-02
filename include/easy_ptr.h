//
// Created by putao on 2024/9/2.
//
///数组相关的操作
#ifndef EASY_PTR_H
#define EASY_PTR_H

#include <stdlib.h>

void *private_new(size_t size) {
    void *ptr = malloc(size);
    return ptr;
}

#define EASY_NEW(type) (type*)private_new(sizeof(type))

#define EASY_INIT(type, ...) ({ \
    type* ptr = EASY_NEW(type); \
    if (ptr != NULL) { \
        *ptr = (type)__VA_ARGS__; \
    } \
    ptr; \
})

#define EASY_DELETE(ptr) do { \
    if (ptr) { \
        free(ptr); \
        ptr = NULL; \
    } \
} while (0)

#endif