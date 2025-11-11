cmake_minimum_required(VERSION 3.16)
project(talos_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Protobuf REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GRPC REQUIRED IMPORTED_TARGET grpc++)
find_program(GRPC_CPP_PLUGIN_EXECUTABLE grpc_cpp_plugin)
if(NOT GRPC_CPP_PLUGIN_EXECUTABLE)
	message(FATAL_ERROR "grpc_cpp_plugin not found. Ensure gRPC tools are installed.")
endif()

set(PROTO_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../proto)
set(PROTO_FILES ${PROTO_DIR}/icd.proto)

set(GENERATED_SRC_DIR ${CMAKE_CURRENT_BINARY_DIR}/generated)
set(PROTO_SRCS ${GENERATED_SRC_DIR}/icd.pb.cc)
set(PROTO_HDRS ${GENERATED_SRC_DIR}/icd.pb.h)
set(GRPC_SRCS ${GENERATED_SRC_DIR}/icd.grpc.pb.cc)
set(GRPC_HDRS ${GENERATED_SRC_DIR}/icd.grpc.pb.h)

add_custom_command(
	OUTPUT ${PROTO_SRCS} ${PROTO_HDRS} ${GRPC_SRCS} ${GRPC_HDRS}
	COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_SRC_DIR}
		COMMAND ${Protobuf_PROTOC_EXECUTABLE}
	ARGS --grpc_out ${GENERATED_SRC_DIR}
			 --cpp_out ${GENERATED_SRC_DIR}
		  --plugin=protoc-gen-grpc=${GRPC_CPP_PLUGIN_EXECUTABLE}
			 -I ${PROTO_DIR}
			 ${PROTO_FILES}
	DEPENDS ${PROTO_FILES}
	COMMENT "Generating gRPC sources from ${PROTO_FILES}"
	VERBATIM
)

add_library(talos_icd_proto STATIC
	${PROTO_SRCS}
	${GRPC_SRCS}
)

target_include_directories(talos_icd_proto
	PUBLIC
		${GENERATED_SRC_DIR}
		${Protobuf_INCLUDE_DIRS}
		${GRPC_INCLUDE_DIRS}
)

target_link_libraries(talos_icd_proto
	PUBLIC
		${Protobuf_LIBRARIES}
		PkgConfig::GRPC
)

add_executable(talos
	src/main.cpp
	src/talos_service.cpp
)

target_link_libraries(talos
	PRIVATE
		talos_icd_proto
		PkgConfig::GRPC
)

target_include_directories(talos
	PRIVATE
		${GENERATED_SRC_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}/src
)
