project (rustext)
set (PLUGIN_VERSION "1.0.0")

cmake_minimum_required (VERSION 2.8)
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

if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_C_COMPILER_ID STREQUAL "Clang")
	set (CMAKE_C_FLAGS "-m32")
endif ()
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	set (CMAKE_CXX_FLAGS "-m32 -std=c++11 -Wno-multichar")
endif ()

add_samp_plugin (${PROJECT_NAME}
	sdk/amxplugin.cpp
	sdk/amxplugin2.cpp
	src/main.cpp
	src/natives.cpp
	src/sampfunctions.cpp
	src/converter.cpp
	src/exports.def
)
