cmake_minimum_required(VERSION 3.21)
cmake_policy(SET CMP0091 NEW)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
project(HUDColor LANGUAGES CXX)

if(NOT WIN32 OR NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
    message(FATAL_ERROR "HUDColor requires Windows MSVC x86. Configure with -A Win32.")
endif()
get_property(multi_config GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
if(multi_config)
    set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Supported configurations" FORCE)
elseif(NOT CMAKE_BUILD_TYPE MATCHES "^(Debug|Release)$")
    message(FATAL_ERROR "Select Debug or Release.")
endif()

include(cmake/Dependencies.cmake)
hudcolor_prepare_dependencies()

include("${VC_LTL_Root}/VC-LTL helper for cmake.cmake")

# Include directories follow HUDColor.vcxproj; only the SDK headers are needed,
# and the plugin links no third-party library.
add_library(hudcolor_settings INTERFACE)
target_include_directories(hudcolor_settings INTERFACE
    src
    "${METAHOOK_SOURCE_PATH}/include"
    "${METAHOOK_SOURCE_PATH}/include/Interface"
    "${METAHOOK_SOURCE_PATH}/include/Interface/VGUI"
    "${METAHOOK_SOURCE_PATH}/include/HLSDK/cl_dll"
    "${METAHOOK_SOURCE_PATH}/include/HLSDK/common"
    "${METAHOOK_SOURCE_PATH}/include/HLSDK/engine"
    "${METAHOOK_SOURCE_PATH}/include/HLSDK/pm_shared"
    "${METAHOOK_SOURCE_PATH}/include/HLSDK/public"
    "${METAHOOK_SOURCE_PATH}/include/VGUI"
    "${METAHOOK_SOURCE_PATH}/include/vgui_controls"
    "${METAHOOK_SOURCE_PATH}/include/SteamSDK"
    "${METAHOOK_SOURCE_PATH}/include/SourceSDK"
    "${METAHOOK_SOURCE_PATH}/include/SourceSDK/tier0"
    "${METAHOOK_SOURCE_PATH}/include/SourceSDK/tier1"
)
# _MBCS mirrors the original MultiByte character set.
target_compile_definitions(hudcolor_settings INTERFACE WIN32 _WINDOWS _USRDLL _MBCS
    $<$<CONFIG:Debug>:_DEBUG>
    $<$<CONFIG:Release>:NDEBUG>)
# Debug used to turn every warning off, Release stayed at Level3 with the SDK's
# known warnings suppressed. /O1 keeps the original MinSpace release optimization.
target_compile_options(hudcolor_settings INTERFACE /permissive
    $<$<CONFIG:Debug>:/W0>
    $<$<CONFIG:Release>:/W3>
    $<$<CONFIG:Release>:/wd4311>
    $<$<CONFIG:Release>:/wd4312>
    $<$<CONFIG:Release>:/wd4819>
    $<$<CONFIG:Release>:/wd4996>
    $<$<CONFIG:Release>:/O1>)

include(cmake/Sources.cmake)
add_library(HUDColor SHARED ${HUDCOLOR_SOURCES})
target_link_libraries(HUDColor PRIVATE hudcolor_settings)
target_compile_options(HUDColor PRIVATE /MP /Zi)
target_link_options(HUDColor PRIVATE /DEBUG
    $<$<CONFIG:Debug>:/INCREMENTAL>
    $<$<CONFIG:Release>:/INCREMENTAL:NO>
    $<$<CONFIG:Release>:/OPT:REF>
    $<$<CONFIG:Release>:/OPT:ICF>)
set_target_properties(HUDColor PROPERTIES INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)

install(TARGETS HUDColor RUNTIME DESTINATION svencoop/metahook/plugins)
install(FILES "$<TARGET_PDB_FILE:HUDColor>" DESTINATION svencoop/metahook/plugins)
