cmake_minimum_required(VERSION 3.16)
project(GraphicsMathPractice CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(include)
file(GLOB QUESTION_FILES questions/Q*.cpp)
foreach(qfile ${QUESTION_FILES})
    get_filename_component(qname ${qfile} NAME_WE)
    add_executable(${qname} ${qfile})
    string(REGEX MATCH "^Q([0-9]+)" _ "${qname}")
    if(CMAKE_MATCH_1)
        set(short_name "q${CMAKE_MATCH_1}")
        set_target_properties(${qname} PROPERTIES
            OUTPUT_NAME "${short_name}"
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/questions"
            RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/questions"
            RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/questions"
            RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_SOURCE_DIR}/questions"
            RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_SOURCE_DIR}/questions"
        )
    endif()
endforeach()
