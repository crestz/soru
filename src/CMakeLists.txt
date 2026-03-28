target_include_directories(
  Soru
  INTERFACE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include>)

if(EXISTS "${CMAKE_CURRENT_LIST_DIR}/intrusive_list/CMakeLists.txt")
  add_subdirectory(intrusive_list)
endif()

if(EXISTS "${CMAKE_CURRENT_LIST_DIR}/smr/CMakeLists.txt")
  add_subdirectory(smr)
endif()
