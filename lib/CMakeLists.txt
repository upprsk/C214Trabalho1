set(HEADER_LIST include/lib.hpp include/common.hpp)

# Make an automatic library - will be static or dynamic based on user setting
add_library(lib lib.cpp ${HEADER_LIST})

target_include_directories(lib PUBLIC include)
target_link_libraries(lib PRIVATE fmt)
target_link_libraries(lib PUBLIC nlohmann_json::nlohmann_json)

# All users of this library will need at least C++20
target_compile_features(lib PUBLIC cxx_std_20)
