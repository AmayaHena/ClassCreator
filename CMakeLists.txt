cmake_minimum_required(VERSION 3.0)

project(classCreator)

set(SRCS
    src/main.cpp
    src/Core.cpp
    src/Dir.cpp
    src/File.cpp
    src/Parser.cpp
    src/Writer.cpp
    src/State.cpp
    )

set(HEADERS
    inc/Core.hpp
    inc/Dir.hpp
    inc/File.hpp
    inc/Parser.hpp
    inc/Writer.hpp
    inc/State.hpp
    )

add_executable(classCreator ${SRCS} ${HEADERS})
target_include_directories(classCreator PUBLIC inc)
