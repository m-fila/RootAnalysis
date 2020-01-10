project(HTauTau_DataFormats LANGUAGES CXX)

include_directories(${PROJECT_SOURCE_DIR}/../include )

ROOT_GENERATE_DICTIONARY(G__HTTEvent ${PROJECT_SOURCE_DIR}/../include/HTTEvent.h LINKDEF ${PROJECT_SOURCE_DIR}/../include/LinkDef.h)

add_library(DataFormats SHARED HTTEvent.cc EventProxyHTT.cc PropertyEnum.cc G__HTTEvent.cxx)

# Define headers for this library. PUBLIC headers are used for
# compiling the library, and will be added to consumers' build
# paths.
target_include_directories(DataFormats PUBLIC ${ROOTINCDIR} ${PROJECT_SOURCE_DIR}/../include  ${CMAKE_SOURCE_DIR}/Core/include)
  
# Depend on a library that we defined in the top-level file
target_link_libraries(DataFormats ${Boost_LIBRARIES})

install(TARGETS DataFormats LIBRARY DESTINATION lib)

if(EXISTS libHTTEvent_rdict.pcm)
  install(FILES libHTTEvent_rdict.pcm libHTTEvent.rootmap DESTINATION lib)
endif()

