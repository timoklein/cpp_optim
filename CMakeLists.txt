cmake_minimum_required(VERSION 3.5)

project(cpp_optim LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)


# Source files
set( project_sources
   main.cpp
   src/functions.hpp
   src/functions.cpp
   src/returnvalue.hpp
   src/optimizer.hpp
   src/gradientdescent.hpp
   src/gaussnewton.hpp
   src/conjugategradient.hpp
)

# Create executable with all necessary source files
add_executable(${PROJECT_NAME}
  ${project_sources}
)
