cmake_minimum_required(VERSION 3.2)

if ($ENV{TRAVIS_BUILD_NUMBER})
    set(PROJECT_VERSION "0.0.$ENV{TRAVIS_BUILD_NUMBER}")
else()
    set(PROJECT_VERSION "0.0.1")
endif()

project(allocator VERSION ${PROJECT_VERSION})

configure_file(version.h.in version.h)

find_package(GTest)

add_executable(allocator src/main.cpp)
target_include_directories(allocator PRIVATE "${CMAKE_BINARY_DIR}")

add_executable(app_test test/test_version.cpp)
target_include_directories(app_test PRIVATE 
    ${CMAKE_BINARY_DIR}
    ${GTEST_INCLUDE_DIRS}
)
target_link_libraries(app_test PRIVATE ${GTEST_BOTH_LIBRARIES} pthread)

set_target_properties(allocator app_test PROPERTIES 
    CXX_STANDARD 14 
    CXX_STANDARD_REQUIRED ON
)

install(TARGETS allocator RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

enable_testing()

add_test(app_test app_test)
