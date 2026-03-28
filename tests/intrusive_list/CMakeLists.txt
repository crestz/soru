add_executable(soru_intrusive_list_tests IntrusiveListTests.cxx)
target_link_libraries(
  soru_intrusive_list_tests
  PRIVATE
    Soru::Soru
    GTest::gtest_main)

gtest_discover_tests(soru_intrusive_list_tests)
