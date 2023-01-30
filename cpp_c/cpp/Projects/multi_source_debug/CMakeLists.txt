include(CMakeToolsHelpers OPTIONAL)
 
# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)
 
# 项目名称
project(multi_source_debug)
 
# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_ROOT_SRCS变量
aux_source_directory(. DIR_ROOT_SRCS)
 
# 添加 Lib子目录
add_subdirectory(Lib)
 
# 指定生成目标
add_executable(n_gram main.cpp ${DIR_ROOT_SRCS})
 
# 添加链接库
# target_link_libraries(OpencvTest OpencvLib)
————————————————
