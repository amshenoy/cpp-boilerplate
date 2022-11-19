cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_TOOLCHAIN_FILE "C:/cppdev/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
set(VCPKG_HOST_TRIPLET "x64-windows" CACHE STRING "")

project(testproj VERSION 0.1.0)
add_executable(test_client) # <executable_name>

# include(CTest)
# enable_testing()

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)

find_package(ixwebsocket CONFIG REQUIRED)

target_link_libraries(test_client
    PRIVATE
        ixwebsocket::ixwebsocket
)

target_sources(test_client
    PRIVATE
        ix_client.cpp
)