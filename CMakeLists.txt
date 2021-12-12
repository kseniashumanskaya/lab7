cmake_minimum_required(VERSION 3.20)
project(lab7)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab7 student_tests.cpp main.cpp Student.cpp Student.h)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

target_link_libraries(lab7 gtest_main)