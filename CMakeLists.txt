cmake_minimum_required(VERSION 3.14.4)
project(conflict-marker-check 
    VERSION 1.0.0
    DESCRIPTION "git conflict marker check command"
    LANGUAGES CXX)

set(SRC_DIR src)
set(TEST_DIR tests)
set(C_DIR ${SRC_DIR}/classes)
set(H_DIR ${SRC_DIR}/classes)

file(GLOB MAIN_SOURCE ${SRC_DIR}/main.cpp)
file(GLOB LIB_SOURCE ${C_DIR}/*.cpp)
file(GLOB TEST_SOURCE ${TEST_DIR}/*.*)

## build
set(BUILD_MAIN ${PROJECT_NAME})

add_executable(
	${BUILD_MAIN}
	${MAIN_SOURCE}
	${LIB_SOURCE}
)

target_include_directories(
	${BUILD_MAIN} 
	PUBLIC
	${H_DIR}
)

INSTALL(TARGETS ${BUILD_MAIN} RUNTIME DESTINATION bin)

## testing
#set(BUILD_TESTING ${PROJECT_NAME}-testing)
#
#add_executable(
#	${BUILD_TESTING}
#	${TEST_SOURCE}
#	${LIB_SOURCE}
#)
#
#target_include_directories(
#	${BUILD_TESTING}
#	PUBLIC
#	${H_DIR}
#	${PROJECT_SOURCE_DIR}/submodules/googletest/googletest/include
#)
#
#add_subdirectory(submodules/googletest)
#
#target_link_libraries(
#	${BUILD_TESTING}
#	gtest
#)
#
#add_test(NAME ${BUILD_TESTING} COMMAND ${BUILD_TESTING})

