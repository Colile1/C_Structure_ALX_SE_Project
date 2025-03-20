add_library(tests
  test_main.cpp  # Create this later
)
target_link_libraries(tests PRIVATE
  C_Structures
  GTest::GTest
  GTest::GTest
)
add_test(NAME tests COMMAND tests)
