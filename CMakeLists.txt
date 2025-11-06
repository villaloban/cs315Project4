cmake_minimum_required(VERSION 3.28)
project(HuffmanDecoder)

set(CMAKE_CXX_STANDARD 17)

add_executable(HuffmanDecoder main.cpp
        HuffmanTree.cpp
        HuffmanTree.hpp
        TreeNode.hpp)
