cmake_minimum_required(VERSION 3.10)
project(WebServer )
# set C++ standard 
set(CMAKE_CXX_STANDARD 20)
include(FetchContent)

FetchContent_Declare(json
  URL https://github.com/nlohmann/json/releases/download/v3.10.5/json.tar.xz
)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
  FetchContent_Populate(json)
  add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
find_package(Poco REQUIRED COMPONENTS Foundation Net Zip )
file(GLOB FILE_MANAGERS_SOURCES "src/http_server/manager/managers/*.cpp")
file(GLOB FILE_MANAGER_SOURCES "src/http_server/manager/*.cpp")
file(GLOB HTTP_SERVER_SOURCES "src/http_server/*.cpp")
add_library(file_managers ${FILE_MANAGERS_SOURCES} )
add_library(file_manager ${FILE_MANAGER_SOURCES} )
add_library(http_server ${HTTP_SERVER_SOURCES})
add_executable(WebServer src/main.cpp)


target_link_libraries(http_server PUBLIC Poco::Foundation Poco::Zip Poco::Net)
target_link_libraries(http_server ${POCO_LIBRARIES})
target_link_libraries(http_server PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(file_manager PUBLIC file_managers)
target_link_libraries(http_server PRIVATE  file_manager)
target_link_libraries(WebServer http_server)

#copy files from dist folder to build folder
file(COPY "dist/" DESTINATION ".")

