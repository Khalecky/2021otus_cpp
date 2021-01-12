
cmake_minimum_required(VERSION 3.2)

if ($ENV{TRAVIS_BUILD_NUMBER})
    set(PROJECT_VERSION "0.0.$ENV{TRAVIS_BUILD_NUMBER}")
else()
    set(PROJECT_VERSION "0.0.1")
endif()

project(ip_filter VERSION ${PROJECT_VERSION})

configure_file(version.h.in version.h)

find_package(GTest)

set (SOURCES src/main.cpp src/ip_filter.cpp)

add_executable(ip_filter ${SOURCES})
target_include_directories(ip_filter PRIVATE "${CMAKE_BINARY_DIR}")

add_executable(app_test test/test_version.cpp)
target_include_directories(app_test PRIVATE 
    ${CMAKE_BINARY_DIR}
    ${GTEST_INCLUDE_DIRS}
)
target_link_libraries(app_test PRIVATE ${GTEST_BOTH_LIBRARIES} pthread)

set_target_properties(ip_filter app_test PROPERTIES 
    CXX_STANDARD 14 
    CXX_STANDARD_REQUIRED ON
)

install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

enable_testing()

add_test(app_test app_test)
