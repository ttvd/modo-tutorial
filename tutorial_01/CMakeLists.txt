CMAKE_MINIMUM_REQUIRED(VERSION 2.4.3)
SET(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS true)
CMAKE_POLICY(SET CMP0003 NEW)

PROJECT(modotutorial01)

# Check debug / release type.
IF(CMAKE_BUILD_TYPE STREQUAL "Debug")

    IF(WIN32)

        SET(DEF_CMAKE_DEBUG TRUE)

        # Prefix all debug binaries with _d.
        #SET(CMAKE_DEBUG_POSTFIX "_d")
    
    ENDIF()

ENDIF()

INCLUDE(CheckTypeSize)
CHECK_TYPE_SIZE("void*" DEF_POINTER_SIZE BUILTIN_TYPES_ONLY)

# Find out how many bits we have.
IF(DEF_POINTER_SIZE EQUAL 8)

    SET(DEF_CMAKE_BITS_X64 TRUE)
    SET(DEF_CMAKE_BITS_X86 FALSE)

ELSE()

    SET(DEF_CMAKE_BITS_X64 FALSE)
    SET(DEF_CMAKE_BITS_X86 TRUE)

ENDIF()

# Output paths.
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "_bin_rel")
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "_lib_rel")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "_bin_deb")
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "_lib_deb")

# Gather sources.
FILE(GLOB DEF_MODOPHYSIQUE_INCLUDE_H "_include/*.h")
FILE(GLOB DEF_MODOPHYSIQUE_INCLUDE_CPP "_source/*.cpp")

# Find out how many bits we have.
IF(DEF_CMAKE_BITS_X64)

    INCLUDE_DIRECTORIES("_include" "c:\\SDK_64\\_include" "_include" "c:\\SDK_64\\_include\\lx")

    IF(DEF_CMAKE_DEBUG)
        
        LINK_DIRECTORIES("C:\\SDK_64\\_lib_deb")

    ELSE()

        LINK_DIRECTORIES("C:\\SDK_64\\_lib_rel")

    ENDIF()

    ADD_LIBRARY(modotutorial64_01 SHARED ${DEF_MODOPHYSIQUE_INCLUDE_H} ${DEF_MODOPHYSIQUE_INCLUDE_CPP})
    TARGET_LINK_LIBRARIES(modotutorial64_01 lx_sdk64)   

ELSE()

    INCLUDE_DIRECTORIES("_include" "c:\\SDK\\_include" "_include" "c:\\SDK\\_include\\lx")
    
    IF(DEF_CMAKE_DEBUG)
        
        LINK_DIRECTORIES("C:\\SDK\\_lib_deb")

    ELSE()

        LINK_DIRECTORIES("C:\\SDK\\_lib_rel")

    ENDIF()

    ADD_LIBRARY(modotutorial_01 SHARED ${DEF_MODOPHYSIQUE_INCLUDE_H} ${DEF_MODOPHYSIQUE_INCLUDE_CPP})
    TARGET_LINK_LIBRARIES(modotutorial_01 lx_sdk)   

ENDIF()
