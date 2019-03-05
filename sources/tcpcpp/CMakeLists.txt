cmake_minimum_required(VERSION 3.0)

set(NAME tcpcpp)

add_library(${NAME} STATIC SHARED tcp_server.cpp)

target_include_directories(${NAME}
        PUBLIC "${PROJECT_SOURCE_DIR}/include/${NAME}"
        PRIVATE "${PROJECT_SOURCE_DIR}/src/${NAME}")

install(TARGETS ${NAME} DESTINATION "${CMAKE_INSTALL_LIBDIR}")
install(DIRECTORY "${PROJECT_SOURCE_DIR}/include/${NAME}" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")