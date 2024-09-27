cmake_minimum_required(VERSION 3.10)
project(EVENTSYS)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(evsys
    src/main.cpp
    src/handlers.cpp
    src/emanager.cpp
)
