include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(phanso_tests phanso_tests.cpp)

target_link_libraries(
        phanso_tests
        GTest::gtest_main
        phanso
)

include(GoogleTest)
gtest_discover_tests(phanso_tests)