#将当前目录下的所有源文件保存在DIR_LIB_SRCS变量中
aux_source_directory(. DIR_SOURCE)
#生成链接库
add_library(main ${DIR_SOURCE})

#制定lib库的安装路径
install(TARGETS main DESTINATION ${COMPILE_DIR}/bin)
install(FILES config.h DESTINATION ${COMPILE_DIR}/include)