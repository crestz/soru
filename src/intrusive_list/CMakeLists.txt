target_sources(
  Soru
  INTERFACE
    FILE_SET soru_headers TYPE HEADERS
    BASE_DIRS
      ${PROJECT_SOURCE_DIR}/include
      ${PROJECT_SOURCE_DIR}/src
    FILES
      ${PROJECT_SOURCE_DIR}/include/soru/intrusive_list.hpp
      ${CMAKE_CURRENT_LIST_DIR}/IntrusiveList.cxx)
