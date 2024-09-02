一个轻量的 ，可以让c语言代码变得优雅的库
----
怎么使用呢？ 需要在CMakeLists.txt 引入:
```
include(ExternalProject)
ExternalProject_Add(
        easy_lib
        GIT_REPOSITORY https://github.com/putao0525/easy-lib.git
        GIT_TAG main  # 或者指定特定的分支、标签或提交哈希
        INSTALL_COMMAND ""  # 不使用 install 目标
)
ExternalProject_Get_Property(easy_lib source_dir binary_dir)
include_directories(${source_dir}/include)
add_executable(easy_lib_test main.c)
add_dependencies(easy_lib_test easy_lib)

```
讲解一个案例：
```
#include <stdio.h>
#include "easy_tools.h"

int main(void) {
    //时间库
    struct tm *curTime = easy_get_current_time();
    //日志库
    EASY_LOG_INFO("当前时间:%s", easy_format_time(curTime, NORM_DATETIME_PATTERN));
    //指针释放
    EASY_DELETE(curTime);
    return 0;
}

```