cmake_minimum_required(VERSION 3.16)
project(GraphicsMathPractice CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(include)
file(GLOB QUESTION_FILES
    questions/Q*.cpp
    questions/coderpad_rendering/Q*.cpp
    questions/tesla/Q*.cpp
)
foreach(qfile ${QUESTION_FILES})
    get_filename_component(qname ${qfile} NAME_WE)
    add_executable(${qname} ${qfile})
    string(REGEX MATCH "^Q([0-9]+)" _ "${qname}")
    if(CMAKE_MATCH_1)
        get_filename_component(qdir ${qfile} DIRECTORY)
        string(FIND "${qdir}" "coderpad_rendering" is_coderpad)
        string(FIND "${qdir}" "tesla" is_tesla)
        if(is_coderpad GREATER -1)
            set(short_name "coderpad_q${CMAKE_MATCH_1}")
        elseif(is_tesla GREATER -1)
            set(short_name "tesla_q${CMAKE_MATCH_1}")
        else()
            set(short_name "q${CMAKE_MATCH_1}")
        endif()
        set_target_properties(${qname} PROPERTIES
            OUTPUT_NAME "${short_name}"
            RUNTIME_OUTPUT_DIRECTORY "${qdir}"
            RUNTIME_OUTPUT_DIRECTORY_DEBUG "${qdir}"
            RUNTIME_OUTPUT_DIRECTORY_RELEASE "${qdir}"
            RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${qdir}"
            RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${qdir}"
        )
    endif()
endforeach()
