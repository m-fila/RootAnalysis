set(MODULE_NAME "DataFormats")
MESSAGE( STATUS "Adding CMake fragment for module:         " ${MODULE_NAME})
file(GLOB_RECURSE sources       ${PROJECT_SOURCE_DIR}/${MODULE_NAME}/src/*.cc)

include_directories(${PROJECT_SOURCE_DIR}/${MODULE_NAME}/include )
include_directories(${CMAKE_SOURCE_DIR}/FrameworkCore/include )
include_directories(${ROOTINCDIR})

ROOT_GENERATE_DICTIONARY(G__${MODULE_NAME} ${PROJECT_SOURCE_DIR}/${MODULE_NAME}/include/HTTEvent.h
 LINKDEF ${PROJECT_SOURCE_DIR}/${MODULE_NAME}/include/LinkDef.h)

add_library(${MODULE_NAME} SHARED ${sources} G__${MODULE_NAME}.cxx)

# Define headers for this library. PUBLIC headers are used for
# compiling the library, and will be added to consumers' build
# paths.
  
# Depend on a library that we defined in the top-level file
target_link_libraries(${MODULE_NAME} ${Boost_LIBRARIES})

install(TARGETS ${MODULE_NAME} LIBRARY DESTINATION lib)

if(EXISTS lib${MODULE_NAME}_rdict.pcm)
  install(FILES lib${MODULE_NAME}_rdict.pcm lib${MODULE_NAME}.rootmap DESTINATION lib)
endif()

