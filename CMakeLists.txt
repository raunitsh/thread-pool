cmake_minimum_required(VERSION 3.30)
project(thread_pool)

set(CMAKE_CXX_STANDARD 20)

add_executable(thread_pool main.cpp
        types.h
        queue.hpp
        task_manager.cpp
        task_manager.h
        thread_pool.cpp
        thread_pool.h)
