target_include_directories(
  Soru
  INTERFACE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include>)

target_sources(
  Soru
  INTERFACE
    FILE_SET soru_headers TYPE HEADERS
    BASE_DIRS
      ${PROJECT_SOURCE_DIR}/include
      ${PROJECT_SOURCE_DIR}/src
    FILES
      ${PROJECT_SOURCE_DIR}/include/soru/intrusive_list.hpp
      ${PROJECT_SOURCE_DIR}/src/IntrusiveList.cxx)
