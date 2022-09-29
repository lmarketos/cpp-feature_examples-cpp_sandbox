add_subdirectory(tutorial)
add_subdirectory(tutorial_exercises)


enable_testing()
list(APPEND CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/GTest")
find_package(GTest REQUIRED)

