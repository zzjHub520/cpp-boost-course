# CMakeList.txt: CMakeProject1 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)
set(INC_DIR C:\\Users\\zzj\\Documents\\workspace\\cpp\\7z\\install_dir\\include\\boost-1_78)
include_directories(${INC_DIR})
set(LIB_DIR C:\\Users\\zzj\\Documents\\workspace\\cpp\\7z\\install_dir\\lib)
link_directories(${LIB_DIR})

# 将源代码添加到此项目的可执行文件。
add_executable (CMakeProject1 "CMakeProject1.cpp" "CMakeProject1.h")

# TODO: 如有需要，请添加测试并安装目标。
