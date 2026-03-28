find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

if(EXISTS "${CMAKE_CURRENT_LIST_DIR}/intrusive_list/CMakeLists.txt")
  add_subdirectory(intrusive_list)
endif()
