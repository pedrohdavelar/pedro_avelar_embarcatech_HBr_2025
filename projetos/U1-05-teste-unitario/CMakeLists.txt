# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 1.5.1)
set(toolchainVersion 13_2_Rel1)
set(picotoolVersion 2.0.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(U1-05-teste_un_temp C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Executável principal

add_executable(main_executable
        app/main.c
        drivers/led_embutido.c
        hal/hal_led.c
        drivers/rp2040_temp_sensor_driver.c
        hal/hal_rp2040_temp.c
        )

target_link_libraries(main_executable
        pico_stdlib              # for core functionality
        pico_cyw43_arch_none     # we need Wifi to access the GPIO, but we don't need anything else
        hardware_adc
        )

target_include_directories(main_executable PRIVATE include)

# Permitir a comunicação serial com o RP2040
pico_enable_stdio_uart(main_executable 0) # desabilita a comunicação via UART
pico_enable_stdio_usb(main_executable 1)  # habilita a comunicação via USB

# create map/bin/hex file etc.
pico_add_extra_outputs(main_executable)

# add url via pico_set_program_url



# Executável de teste unitário da medição de temperatura

add_executable(unit_test_executable
        test/test_rp2040_temp.c
        drivers/led_embutido.c
        hal/hal_led.c
        drivers/rp2040_temp_sensor_driver.c
        hal/hal_rp2040_temp.c
        include/Unity/unity.c
        )

target_link_libraries(unit_test_executable
        pico_stdlib              # for core functionality
        pico_cyw43_arch_none     # we need Wifi to access the GPIO, but we don't need anything else
        hardware_adc
        )

# adiciona o diretório de includes
target_include_directories(unit_test_executable PRIVATE include)

# Permitir a comunicação serial com o RP2040
pico_enable_stdio_uart(unit_test_executable 0) # desabilita a comunicação via UART
pico_enable_stdio_usb(unit_test_executable 1)  # habilita a comunicação via USB

# create map/bin/hex file etc.
pico_add_extra_outputs(unit_test_executable)

