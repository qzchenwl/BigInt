include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_library(BigInt BigInt.cpp)
add_executable(demo main.cpp)
# Key idea: SEPARATE OUT your main() function into its own file so it can be its
# own executable. Separating out main() means you can add this library to be
# used elsewhere.

target_link_libraries(demo BigInt)
