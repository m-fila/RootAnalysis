project(ELITPC LANGUAGES CXX)

# Adding external project
MESSAGE( STATUS "Adding external project:           TPCReco")
include(ExternalProject)
ExternalProject_Add(TPC_Reco SOURCE_DIR ${PROJECT_SOURCE_DIR}/deps/TPCReco CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_BINARY_DIR})
include_directories(${PROJECT_BINARY_DIR}/include)
link_directories(${PROJECT_BINARY_DIR}/lib)
# remember to add_dependencies(TARGET TPC_Reco)
# and target_link_libraries(TARGET PUBLIC TPCReco)


add_subdirectory(DataFormats)
add_subdirectory(Analysis)