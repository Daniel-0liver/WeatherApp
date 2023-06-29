cmake_minimum_required(VERSION 3.5)

project(WeatherApp LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets Network REQUIRED)

if(ANDROID)
  add_library(WeatherApp SHARED
    main.cpp
    weatherapp.cpp
    weatherapp.h
    weatherapp.ui
  )
else()
  add_executable(WeatherApp
    main.cpp
    weatherapp.cpp
    weatherapp.h
    weatherapp.ui
  )
endif()

target_link_libraries(WeatherApp PRIVATE Qt5::Widgets Qt5::Network)
