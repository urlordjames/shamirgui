project("shamirgui")
cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include wxWidgets
find_package(wxWidgets COMPONENTS base core REQUIRED)
include(${wxWidgets_USE_FILE})

add_executable(${PROJECT_NAME} WIN32
	src/main.cpp
	src/window.cpp
	src/pointlist.cpp
	src/point.cpp
)

# add shamirlib
add_library(shamirlib STATIC shamirlib/shamir.cpp)
set_target_properties(shamirlib PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/shamirlib)

if(BUILD_TESTING)
	find_package(GTest REQUIRED)
	add_subdirectory(tests)
endif(BUILD_TESTING)

# link wxWidgets
target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})

# gmp
find_library(GMP_LIBRARY gmp REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE gmp)

# link shamirlib
target_link_libraries(${PROJECT_NAME} PRIVATE shamirlib)

option(CMAKE_INSTALL_BINDIR "/bin")

# install
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
