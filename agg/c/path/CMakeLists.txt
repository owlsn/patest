#cmake版本号
cmake_minimum_required(VERSION 3.0)
# 项目名称
project(path)

#自定义编译选项
set(CMAKE_INCLUDE_CURRENT_DIR on)

#设置支持gdb
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
set(COMPILE_DIR "${PROJECT_SOURCE_DIR}/compile")
set(CMAKE_INCLUDE_CURRENT_DIR on)
set(PATH_VERSION_MAJOR 1)
set(PATH_VERSION_MINOR 01)

# 判断系统是否包含某个函数
include("${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake")
check_function_exists (pow HAVE_POW)

#加入配置头文件，用于处理cmake对源码的设置
configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_SOURCE_DIR}/config.h"
)

option(
    USE_LIB "Use provided lib" on
)
if(USE_LIB)
    include_directories("${PROJECT_SOURCE_DIR}/extra")
    add_subdirectory(extra)
    set (EXTRA_LIBS ${EXTRA_LIBS} extra)
endif(USE_LIB)

#将.目录下的所有文件，并保存在DIR_SRCS变量
aux_source_directory(. DIR_SRCS)
#添加子目录lib
add_subdirectory(lib)
#生成指定文件

#制定安装路径
add_executable(main ${DIR_SRCS})
target_link_libraries(main lib)
target_link_libraries(main extra)

install(TARGETS main DESTINATION ${COMPILE_DIR}/bin)
install(FILES "${PROJECT_BINARY_DIR}/config.h" DESTINATION ${COMPILE_DIR}/include)

#启用测试
enable_testing()
#测试程序是否成功运行
add_test(test_run main)

#测试帮助信息是否可以正常提示
add_test(test_usage main)
set_tests_properties(test_usage
  PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .* base exponent")

# 测试宏
macro(do_test arg1 arg2 result)
    add_test(test_${arg1}_${arg2} main ${arg1} ${arg2})
    set_tests_properties(test_${arg1}_${arg2}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endmacro(do_test)

#测试5的平方
# add_test(test_5_2 main 5 2)
# set_tests_properties(test_5_2
#  PROPERTIES PASS_REGULAR_EXPRESSION "is 25")
do_test(5 2 "is 25")

#测试10的5次方
# add_test(test_10_5 main 10 5)
# set_tests_properties(test_10_5
#  PROPERTIES PASS_REGULAR_EXPRESSION "is 100000")
do_test(10 5 "is 100000")
#测试2的10次方
# add_test(test_2_10 main 2 10)
# set_tests_properties(test_2_10
#  PROPERTIES PASS_REGULAR_EXPRESSION "is 1024")
do_test(2 10 "is 1024")


# cpack打包
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE
    "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${PATH_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PATH_VERSION_MINOR}")
set(CPACK_PACKAGE_DIRECTORY "${PROJECT_SOURCE_DIR}/pack")
set(CPACK_SOURCE_GENERATOR "TGZ")
set(PROJECT_VERSION_FULL "${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "path-${PROJECT_VERSION_FULL}")
include(CPack)
