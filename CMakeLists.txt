cmake_minimum_required(VERSION 3.14.4)
project(conflict-marker-check 
    VERSION 1.0.0
    DESCRIPTION "git conflict marker check command"
    LANGUAGES CXX)



set(SRC_DIR src)
set(C_DIR ${SRC_DIR}/classes)
set(H_DIR ${SRC_DIR}/classes)

file(GLOB MAIN_SOURCE ${SRC_DIR}/main.cpp)
file(GLOB LIB_SOURCE ${C_DIR}/*.cpp)

include_directories(${H_DIR})

# build
add_executable(conflict-marker-check  ${MAIN_SOURCE} ${LIB_SOURCE})

add_subdirectory(submodules/googletest)

set(TEST_DIR tests)


file(GLOB TEST_SOURCE ${TEST_DIR}/*.*)


# build for testing
add_executable(conflict-marker-check-test ${TEST_SOURCE} ${LIB_SOURCE})


target_include_directories(
	conflict-marker-check-test PUBLIC
	${PROJECT_SOURCE_DIR}/submodules/googletest/googletest/include
)

target_link_libraries(
	conflict-marker-check-test
	gtest
)

add_test(NAME conflict-marker-check-test COMMAND conflict-marker-check-test)
