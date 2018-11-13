#设定cmake版本
cmake_minimum_required(VERSION 3.0)
#项目名称
project(FunctionPointor)

#自定义编译选项
set(CMAKE_INCLUDE_CURRENT_DIR on)
#设置目录相关变量
#PROJECT_SOURCE_DIR 顶级目录
# 源代码目录
set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
# build目录，cmake生成文件夹目录
set(CMAKE_BUILD "${PROJECT_SOURCE_DIR}/build")
# cpack打包目录
set(CPACK_DIR "${PROJECT_SOURCE_DIR}/cpack")
# bin可执行文件目录
set(PROJECT_BINARY_DIR "${PROJECT_SOURCE_DIR}/bin")
# compile 编译文件目录
set(COMPILE_DIR "${PROJECT_SOURCE_DIR}/compile")

#设置cmake相关配置变量
set(CMAKE_INCLUDE_CURRENT_DIR on)
#设置支持gdb
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
#设置项目版本
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 01)
set(PROJECT_VERSION_PATCH 01)

include_directories(${SOURCE_DIR})
#设置依赖库
aux_source_directory(${SOURCE_DIR} DIR_SRCS)
add_subdirectory(${SOURCE_DIR})
add_executable(main ${DIR_SRCS})
#设置安装路径
install(TARGETS main DESTINATION ${COMPILE_DIR}/bin)

#添加测试
enable_testing()
add_test(test_run main)
#测试帮助信息是否可以正常提示
# add_test(test_usage main)
# set_tests_properties(test_usage
#   PROPERTIES PASS_REGULAR_EXPRESSION "main")
# 测试宏
macro(do_test arg1 arg2 result)
    add_test(test_${arg1}_${arg2} main ${arg1} ${arg2})
    set_tests_properties(test_${arg1}_${arg2}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endmacro(do_test)

#打包发布
# cpack打包
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE
    "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_DIRECTORY "${PROJECT_SOURCE_DIR}/pack")
set(CPACK_SOURCE_GENERATOR "TGZ")
set(PROJECT_VERSION_FULL "${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "project-${PROJECT_VERSION_FULL}")
include(CPack)


