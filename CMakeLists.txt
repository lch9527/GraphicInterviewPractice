cmake_minimum_required(VERSION 3.16)
project(GraphicsMathPractice CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(include)
file(GLOB QUESTION_FILES
    "questions/3D math/Q*.cpp"
    questions/coderpad_rendering/Q*.cpp
    questions/data_structure_builder/Q*.cpp
    questions/tesla/Q*.cpp
    questions/leetcode/Answer_Q*.cpp
)
foreach(qfile ${QUESTION_FILES})
    get_filename_component(qname ${qfile} NAME_WE)
    add_executable(${qname} ${qfile})
    string(REGEX MATCH "^(Answer_)?Q([0-9]+)" _ "${qname}")
    if(CMAKE_MATCH_2)
        set(qnumber "${CMAKE_MATCH_2}")
        get_filename_component(qdir ${qfile} DIRECTORY)
        string(FIND "${qdir}" "3D math" is_3d_math)
        string(FIND "${qdir}" "coderpad_rendering" is_coderpad)
        string(FIND "${qdir}" "data_structure_builder" is_data_structure_builder)
        string(FIND "${qdir}" "tesla" is_tesla)
        string(FIND "${qdir}" "leetcode" is_leetcode)
        if(is_3d_math GREATER -1)
            set(short_name "3d_math_q${qnumber}")
            set(output_dir "${CMAKE_SOURCE_DIR}/questions_artifacts/3D math")
        elseif(is_coderpad GREATER -1)
            set(short_name "coderpad_q${qnumber}")
            set(output_dir "${CMAKE_SOURCE_DIR}/questions_artifacts/coderpad_rendering")
        elseif(is_data_structure_builder GREATER -1)
            set(short_name "data_structure_builder_q${qnumber}")
            set(output_dir "${CMAKE_SOURCE_DIR}/questions_artifacts/data_structure_builder")
        elseif(is_leetcode GREATER -1)
            set(short_name "leetcode_q${qnumber}")
            set(output_dir "${CMAKE_SOURCE_DIR}/questions_artifacts/leetcode")
        elseif(is_tesla GREATER -1)
            set(short_name "tesla_q${qnumber}")
            set(output_dir "${CMAKE_SOURCE_DIR}/questions_artifacts/tesla")
        else()
            set(short_name "q${qnumber}")
            set(output_dir "${CMAKE_SOURCE_DIR}/questions_artifacts")
        endif()
        set_target_properties(${qname} PROPERTIES
            OUTPUT_NAME "${short_name}"
            RUNTIME_OUTPUT_DIRECTORY "${output_dir}"
            RUNTIME_OUTPUT_DIRECTORY_DEBUG "${output_dir}"
            RUNTIME_OUTPUT_DIRECTORY_RELEASE "${output_dir}"
            RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${output_dir}"
            RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${output_dir}"
        )
    endif()
endforeach()
