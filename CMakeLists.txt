set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

project(cmmcompiler CXX)

cmake_minimum_required(VERSION 3.1)
add_definitions("-g")
find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

BISON_TARGET(parser
             parser.yy
             ${CMAKE_CURRENT_BINARY_DIR}/parser.cc)
FLEX_TARGET(scanner
            scanner.ll
            ${CMAKE_CURRENT_BINARY_DIR}/scanner.cc)
ADD_FLEX_BISON_DEPENDENCY(scanner parser)

add_executable(compiler
    main.cc
    driver.cc
    ast.cc
    node.cc
    symbol.cc
    semantic.cc
    my_hash_table.cc
    ${FLEX_scanner_OUTPUTS}
    ${BISON_parser_OUTPUTS}
)
target_include_directories(compiler
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${FLEX_INCLUDE_DIRS}
        ${CMAKE_CURRENT_BINARY_DIR})
set_property(TARGET compiler
             PROPERTY CXX_STANDARD 17)
# enable_testing()
# add_test(NAME basic
#          COMMAND ${CMAKE_SOURCE_DIR}/test/test0.pl
#          WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
