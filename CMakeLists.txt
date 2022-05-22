cmake_minimum_required(VERSION 3.7)
project(ft_printf C)
set(CMAKE_CXX_STANDARD 99)

# Add c files of project root directory as source file
file(GLOB SOURCE_FILES "srcs/*.c")
file(GLOB HEADER_FILES "include/*.h")

include_directories(include libft/include include_internal)
add_library(ft_printf.a ${SOURCE_FILES} ${HEADER_FILES})
