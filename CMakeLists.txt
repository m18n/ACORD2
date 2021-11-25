cmake_minimum_required(VERSION 3.5)
project(Acord)
find_package(OpenSSL REQUIRED)
file(GLOB CPPS "*.cpp")
add_subdirectory(curl)
add_executable(${PROJECT_NAME} ${CPPS} )
target_link_libraries(${PROJECT_NAME} PRIVATE OpenSSL::SSL CURL::libcurl)

