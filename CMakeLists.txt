cmake_minimum_required(VERSION 3.23)
project(Weightlifting-App)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED)
set(OpenCV_DIR "C:/Users/nicho/opencv/build/x64/vc16/lib")

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include OpenCV directories
include_directories(${OpenCV_INCULDE_DIRS})

# Create the executable target
add_executable(Weightlifting-App main.cpp)

# Link OpenCV libraries to the target
target_link_libraries(Weightlifting-App ${OpenCV_LIBS})
