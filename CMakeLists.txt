cmake_minimum_required(VERSION 3.27)
project(SmartPointersv2)

set(CMAKE_CXX_STANDARD 17)

add_executable(SmartPointersv2 main.cpp
        CSmartPointer.h
        CRefCounter.h
        MathTree.cpp
        MathTree.h
        CError.cpp
        CError.h
        CResult.tpp
        CResult.h
        Node.h
        Node.cpp
        Operations.h)
