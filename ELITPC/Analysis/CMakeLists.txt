set(MODULE_NAME "Analysis")
MESSAGE( STATUS "Adding CMake fragment for module:         " ${MODULE_NAME})
include_directories(${PROJECT_SOURCE_DIR}/${MODULE_NAME}/include )
include_directories(${CMAKE_SOURCE_DIR}/FrameworkCore/include)
include_directories(${PROJECT_SOURCE_DIR}/DataFormats/include)
include_directories(${ROOTINCDIR})
file(GLOB_RECURSE sources     ${PROJECT_SOURCE_DIR}/${MODULE_NAME}/src/*.cc)
add_library(${MODULE_NAME} SHARED ${sources})

# Define an executable
add_executable(httAnalysis bin/HTTAnalysis.cc)
target_link_libraries(${MODULE_NAME} FrameworkCore DataFormats )
target_link_libraries(httAnalysis ${MODULE_NAME} FrameworkCore DataFormats ${Boost_LIBRARIES} ${ROOT_LIBRARIES} Proof RooFitCore RooFit )

install(TARGETS ${MODULE_NAME} LIBRARY DESTINATION lib)
install(TARGETS httAnalysis RUNTIME DESTINATION bin)
install(FILES $<1:${PROJECT_SOURCE_DIR}/${MODULE_NAME}/config/> DESTINATION config)
install(FILES $<1:${PROJECT_SOURCE_DIR}/${MODULE_NAME}/python/> DESTINATION python)
install(DIRECTORY DESTINATION fig_png)
