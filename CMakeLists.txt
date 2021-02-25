project("shamirgui")
cmake_minimum_required(VERSION 3.7)

# include wxWidgets
find_package(wxWidgets COMPONENTS base core REQUIRED)
include(${wxWidgets_USE_FILE})

add_executable(${PROJECT_NAME} WIN32
	src/main.cpp
	src/window.cpp
	src/shamir.cpp
	src/pointlist.cpp
	src/point.cpp
)

# link wxWidgets
target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})

# gmp
find_library(GMP_LIBRARY gmp)
target_include_directories(${PROJECT_NAME} PRIVATE ${GMP_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE gmp)
