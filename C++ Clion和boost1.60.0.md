[c++ - CLion和Boost 1.60.0](https://www.lmlphp.com/user/152245/article/item/3420305/)

扫码查看

在过去的几天里，我一直在努力使Boost库包含在我的项目中。我一直在阅读和使用有关Stack Overflow的众多海报的建议，由于某种原因，我不明白我仍然无法让CMake找到Boost，或者如果确实找到Boost，我将无法编译，因为它无法找到我显然需要链接的boost_system库，以消除未找到的系统config（）错误。

我目前正在Windows 10上使用GNU C ++编译器v4.9.3-1的MinGW实现

目前，Boost已提取到我的系统上：



```
C:\boost_1_60_0
```



这是我的CMake文件当前的样子：



```
cmake_minimum_required(VERSION 3.5)
project(Engine)

#SET(GCC_COVERAGE_LINK_FLAGS "-lboost_system")

message(STATUS "start running cmake...")

SET(BOOSTROOT "C:/boost_1_60_0/")
SET(BOOST_ROOT "C:/boost_1_60_0/")
SET(BOOST_LIBRARYDIR "C:/boost_1_60_0/libs/")

find_package(Boost 1.60.0 COMPONENTS system REQUIRED)

if(Boost_FOUND)

    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})
    add_definitions("-DHAS_BOOST")

endif()

add_executable(Engine main.cpp)

if(Boost_FOUND)

    target_link_libraries(Engine ${Boost_LIBRARIES})

endif()

set(SOURCE_FILES main.cpp)
```



我目前收到的错误是：



```
Error:Unable to find the requested Boost libraries.
Boost version: 1.60.0
Boost include path: C:/boost_1_60_0
Could not find the following Boost libraries:
        boost_system
No Boost libraries were found.  You may need to set BOOST_LIBRARYDIR to the directory containing Boost libraries or BOOST_ROOT to the location of Boost.
```



**更新**
这是使用-DBoost_Debug = ON运行cmake时的输出：



```
_boost_TEST_VERSIONS = 1.61.0;1.61;1.60.0;1.60
Boost_USE_MULTITHREADED = TRUE
Boost_USE_STATIC_LIBS =
Boost_USE_STATIC_RUNTIME =
Boost_ADDITIONAL_VERSIONS =
Boost_NO_SYSTEM_PATHS =
Declared as CMake or Environmental Variables:
 BOOST_ROOT = C:/boost_1_60_0/
 BOOST_INCLUDEDIR =
 BOOST_LIBRARYDIR = C:/boost_1_60_0/libs/
_boost_TEST_VERSIONS = 1.61.0;1.61;1.60.0;1.60
location of version.hpp: C:/boost_1_60_0/boost/version.hpp
version.hpp reveals boost 1.60.0
guessed _boost_COMPILER = -mgw49
_boost_MULTITHREADED = -mt
_boost_RELEASE_ABI_TAG = -
_boost_DEBUG_ABI_TAG = -d
_boost_LIBRARY_SEARCH_DIRS_RELEASE = C:/boost_1_60_0/libs/;C:/boost_1_60_0//lib;C:/boost_1_60_0//stage/lib;C:/boost_1_60_0/lib;C:/boost_1_60_0/../lib;C:/boost_1_60_0/stage/lib;PATHS;C:/boost/lib;C:/boost;/sw/local/lib_boost_LIBRARY_SEARCH_DIRS_DEBUG   = C:/boost_1_60_0/libs/;C:/boost_1_60_0//lib;C:/boost_1_60_0//stage/lib;C:/boost_1_60_0/lib;C:/boost_1_60_0/../lib;C:/boost_1_60_0/stage/lib;PATHS;C:/boost/lib;C:/boost;/sw/local/lib
Searching for SYSTEM_LIBRARY_RELEASE: boost_system-mgw49-mt-1_60;boost_system-mgw49-mt;boost_system-mt-1_60;boost_system-mt;boost_system
Searching for SYSTEM_LIBRARY_DEBUG: boost_system-mgw49-mt-d-1_60;boost_system-mgw49-mt-d;boost_system-mt-d-1_60;boost_system-mt-d;boost_system-mt;boost_system
```



提前致谢





**最佳答案**

有一些有用的标志可帮助FindBoost查找库。

在调用`find_package(Boost)`之前，尝试设置这些变量（打开或关闭-取决于您的Boost安装）。



```
set(Boost_LIB_PREFIX            "lib"       CACHE STRING "")
set(Boost_USE_MULTITHREADED     ON          CACHE BOOL "") # '-mt' flag
set(Boost_USE_STATIC_LIBS       ON          CACHE BOOL "")
set(Boost_USE_STATIC_RUNTIME    ON          CACHE BOOL "") # '-s' tag
set(Boost_USE_DEBUG_RUNTIME     ON          CACHE BOOL "") # '-g' tag
set(Boost_COMPILER              "-mgw49"    CACHE STRING "")
```



用`set(Boost_DETAILED_FAILURE_MSG TRUE)`设置标志将极大地帮助您进行诊断