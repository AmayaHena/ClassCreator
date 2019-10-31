cmake_minimum_required(VERSION 3.0)

project(/*#!ProgramName*/)

set(SRCS
/*#!SrcCMake*/
    )

set(HEADERS
/*#!IncCMake*/
    )

add_executable(/*#!ProgramName*/ ${SRCS} ${HEADERS})
target_include_directories(/*#!ProgramName*/ PUBLIC inc)
