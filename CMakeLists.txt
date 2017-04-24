project (rustext)
set (PLUGIN_VERSION "2.0.3")

cmake_minimum_required (VERSION 2.8)
list (APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include (AMXConfig)
include (AddSAMPPlugin)

include_directories (
	${CMAKE_CURRENT_SOURCE_DIR}/
	${CMAKE_CURRENT_SOURCE_DIR}/src
	${CMAKE_CURRENT_SOURCE_DIR}/lib
	${CMAKE_CURRENT_SOURCE_DIR}/lib/sdk
	${CMAKE_CURRENT_SOURCE_DIR}/lib/sdk/amx
)

add_definitions (-DPLUGIN_NAME="${PROJECT_NAME}" -DPLUGIN_VERSION="${PLUGIN_VERSION}")

set (CMAKE_SHARED_LIBRARY_PREFIX "")

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	set (CMAKE_CXX_FLAGS "-std=c++11")
endif ()

add_samp_plugin (${PROJECT_NAME}
	lib/sdk/amxplugin.cpp
	lib/sdk/amxplugin2.cpp
	lib/RakNet/BitStream.cpp
	src/main.cpp
	src/main.hpp
	src/natives.cpp
	src/natives.hpp
	src/converter.cpp
	src/converter.hpp
	src/russifier.cpp
	src/russifier.hpp
	src/hooks.cpp
	src/hooks.hpp
	src/common.hpp
	src/exports.def
)
