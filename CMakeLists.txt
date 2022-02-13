cmake_minimum_required(VERSION 3.21)
project(Algorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(Algorithms
        main.cpp
        Task2/task2.cpp Task2/task2.h
        Task3/task3.cpp Task3/task3.h
        Task4/task4.cpp Task4/task4.h
        Task6/task6.cpp Task6/task6.h
        Utils/arrayUtils.cpp Utils/arrayUtils.h
        Task7/task7.cpp Task7/task7.h
        Task9/task9.cpp Task9/task9.h
        Task9/queue.cpp Task9/queue.h
        Task9/stack.cpp Task9/stack.h)
