cmake_minimum_required(VERSION 3.12)
project(C_Structures LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

# Include Eigen and GLM (header-only)
find_package(Eigen3 REQUIRED)
find_package(glm REQUIRED)

# SDL2 and OpenGL
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

# GLEW (for OpenGL extensions)
find_package(GLEW REQUIRED)

# Google Test
find_package(GTest REQUIRED)

# Add shared library
add_library(C_Structures SHARED
  src/main.cpp
  src/model/Node.cpp
  src/model/Beam.cpp
  src/data/CSVHandler.cpp
)

# Include directories
target_include_directories(C_Structures PRIVATE
  ${SDL2_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIR}/Eigen  # Ensure Eigen include path is correct
  ${GLEW_INCLUDE_DIRS}
  include/
)


# Link libraries
target_link_libraries(C_Structures PRIVATE
  ${SDL2_LIBRARIES}
  OpenGL::GL
  GLEW::GLEW
)

# Testing (future use)
enable_testing()
add_subdirectory(tests)
