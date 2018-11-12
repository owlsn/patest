#将当前目录下的所有源文件保存在DIR_LIB_SRCS变量中
aux_source_directory(. DIR_LIB_SRCS)
#生成链接库
add_library(lib ${DIR_LIB_SRCS})

#制定lib库的安装路径
install(TARGETS lib DESTINATION ${COMPILE_DIR}/bin)
install(FILES check.h DESTINATION ${COMPILE_DIR}/include)
install(FILES path.h DESTINATION ${COMPILE_DIR}/include)
install(FILES stack.h DESTINATION ${COMPILE_DIR}/include)