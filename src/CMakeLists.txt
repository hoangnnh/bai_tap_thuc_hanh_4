add_subdirectory(phanso)

add_executable(app_phanso main.cpp)

target_link_libraries(app_phanso PUBLIC phanso)