#将当前目录下的所有源文件保存在DIR_LIB_SRCS变量中
aux_source_directory(. DIR_EXTRA_SRCS)
#生成链接库
add_library(extra ${DIR_EXTRA_SRCS})

#制定extra库的安装路径
install(TARGETS extra DESTINATION ${COMPILE_DIR}/bin)
install(FILES math.h DESTINATION ${COMPILE_DIR}/include)