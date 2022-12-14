cmake_minimum_required(VERSION 3.21)
project(linkedhashset VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(interpreter_main
        Main.cpp
        Data.cpp
        Commands.cpp
        Parser.cpp 
)

add_executable(interpreter_test
        Data.cpp
        Commands.cpp
        Parser.cpp
        Tests.cpp
)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)



SET(WARN_FLAGS "-Wall -Wpedantic -Wextra")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WARN_FLAGS} ${ASAN_OPTIONS} -fsanitize=address")

enable_testing()

target_link_libraries(
  interpreter_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(interpreter_test)