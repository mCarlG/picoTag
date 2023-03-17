cmake_minimum_required(VERSION 3.25)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)
set(PICO_BOARD pico_w)

include_directories(src)
include(src/pico_sdk_import.cmake)

project(picoTag VERSION 0.1)

pico_sdk_init()

add_executable(pico_tag src/main.c)
target_link_libraries(
	pico_tag
	pico_stdlib
	pico_btstack_ble
	pico_btstack_cyw43
	pico_cyw43_arch_none
	)

pico_add_extra_outputs(pico_tag)
