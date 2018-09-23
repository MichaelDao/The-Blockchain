cmake_minimum_required(VERSION 3.8)
project(blockchain)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Block.cpp Block.h Blockchain.cpp Blockchain.h sha256.cpp sha256.h)
add_executable(blockchain ${SOURCE_FILES})