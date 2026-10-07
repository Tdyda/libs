cmake_minimum_required(VERSION 4.3)
project(collections C)

set(CMAKE_C_STANDARD 11)

add_library(collections SHARED
        collection.h
        collection.c)
