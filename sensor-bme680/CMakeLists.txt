cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
  hello_bme280
  VERSION 0.1
  DESCRIPTION "Hello world with the BME280 Sensor"
  LANGUAGES C CXX)

target_sources(app PRIVATE src/main.cpp)
