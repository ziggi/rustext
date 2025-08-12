cmake_minimum_required (VERSION 2.8...9.9)

project (rustext)
set (PLUGIN_VERSION "2.0.11")

list (APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include (AMXConfig)
include (AddSAMPPlugin)

include_directories (
	${CMAKE_CURRENT_SOURCE_DIR}/
	${CMAKE_CURRENT_SOURCE_DIR}/src
	${CMAKE_CURRENT_SOURCE_DIR}/sdk
	${CMAKE_CURRENT_SOURCE_DIR}/sdk/amx
)

add_definitions (-DPLUGIN_NAME="${PROJECT_NAME}" -DPLUGIN_VERSION="${PLUGIN_VERSION}")

set (CMAKE_SHARED_LIBRARY_PREFIX "")

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	set (CMAKE_CXX_FLAGS "-std=c++11")
endif ()

add_samp_plugin (${PROJECT_NAME}
	sdk/amxplugin.cpp
	sdk/amxplugin2.cpp
	src/main.cpp
	src/main.hpp
	src/natives.cpp
	src/natives.hpp
	src/sampfunctions.cpp
	src/sampfunctions.hpp
	src/converter.cpp
	src/converter.hpp
	src/russifier.cpp
	src/russifier.hpp
	src/common.hpp
	src/format.cpp
	src/format.h
	src/exports.def
)
