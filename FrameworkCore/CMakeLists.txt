set(MODULE_NAME "FrameworkCore")
MESSAGE( STATUS "Adding CMake fragment for module:         " ${MODULE_NAME})
include_directories(${PROJECT_SOURCE_DIR}/${MODULE_NAME}/include)
include_directories(${ROOTINCDIR})
file(GLOB_RECURSE sources ${PROJECT_SOURCE_DIR}/${MODULE_NAME}/src/*.cc)

add_library(${MODULE_NAME} SHARED ${sources})

target_link_libraries(${MODULE_NAME} ${Boost_LIBRARIES})

install(TARGETS ${MODULE_NAME} LIBRARY DESTINATION lib)
