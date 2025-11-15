cmake_minimum_required(VERSION 3.24)
option(CMAKE_EXPORT_COMPILE_COMMANDS "Create compile_commands.json" ON)
project(MyApp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE NOVA_FILES
        CONFIGURE_DEPENDS
        Nova/src/*.h
        Nova/src/*.cpp
)
file(GLOB GLAD_FILES Nova/vendor/GLAD/src/glad.cpp Nova/vendor/GLAD/include/glad/glad.h Nova/vendor/GLAD/include/KHR/khrplatform.h)
file(GLOB APP_FILES src/*.cpp src/*.h)

add_executable(${PROJECT_NAME}
        ${NOVA_FILES}
        ${GLAD_FILES}
        ${APP_FILES}
)

target_include_directories(${PROJECT_NAME} PRIVATE Nova)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)# -Wpedantic)






include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(Nova/src)
include_directories(Nova/vendor/GLAD/include)

target_precompile_headers(${PROJECT_NAME} PRIVATE Nova/src/nvpch.h)

add_subdirectory(Nova/vendor/GLFW)

find_package(OpenGL REQUIRED)
target_link_libraries(MyApp
        PUBLIC
        glfw
        OpenGL::GL
)
