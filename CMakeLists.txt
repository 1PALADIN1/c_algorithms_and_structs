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
        Task9/stack.cpp Task9/stack.h
        Task10/task10.cpp Task10/task10.h
        Task10/stack_task10.cpp Task10/stack_task10.h
        Task10/linkedlist.cpp Task10/linkedlist.h
        Task12/task12.cpp Task12/task12.h
        Task12/binaryTree.cpp Task12/binaryTree.h
        Task13/task13.cpp Task13/task13.h
        Task15/task15.cpp Task15/task15.h
        Task16/task16.cpp Task16/task16.h)
