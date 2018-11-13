aux_source_directory(. SRCS)

install(FILES shape.h DESTINATION "${COMPILE_DIR}/include")
install(FILES square.h DESTINATION "${COMPILE_DIR}/include")
install(FILES triangle.h DESTINATION "${COMPILE_DIR}/include")
install(FILES circle.h DESTINATION "${COMPILE_DIR}/include")
