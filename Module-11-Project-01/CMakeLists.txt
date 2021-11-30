cmake_minimum_required(VERSION 3.17)
project(Module-12-Bank-Solution)

set(CMAKE_CXX_STANDARD 14)

add_executable(Module12-Bank-Solution 
    main.cpp
    tellers.cpp
    accounts.cpp
    ui.cpp
)

add_custom_command(
    TARGET Module12-Bank-Solution POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Copying sample data ..."
    COMMAND ${CMAKE_COMMAND} -E copy_directory 
        ${CMAKE_CURRENT_SOURCE_DIR}/data
        $<TARGET_FILE_DIR:Module12-Bank-Solution>/data
)