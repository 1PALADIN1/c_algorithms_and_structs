cmake_minimum_required(VERSION 3.21)
project(Algorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(Algorithms
        main.cpp
        Task2/task2.cpp Task2/task2.h
        Task3/task3.cpp Task3/task3.h
        Task4/task4.cpp Task4/task4.h
        Task5/task5.cpp Task5/task5.h
        Task5/arrayUtils.cpp Task5/arrayUtils.h)
