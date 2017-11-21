cmake_minimum_required(VERSION 3.4)
project(light-scheduler VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

include_directories(src)

add_executable(light-scheduler
    src/light_scheduler.cpp
)

# src/light_scheduler.tests.cpp
