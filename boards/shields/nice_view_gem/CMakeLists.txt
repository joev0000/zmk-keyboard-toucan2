if(CONFIG_ZMK_DISPLAY AND CONFIG_NICE_VIEW_WIDGET_STATUS)
  zephyr_library_include_directories(${CMAKE_SOURCE_DIR}/include)
  zephyr_library_sources(custom_status_screen.c)
  zephyr_library_sources(assets/images.c)
  if(CONFIG_TOUCAN_STATUS_SCREEN EQUAL 2)
    zephyr_library_sources(widgets/battery_arc.c)
    zephyr_library_sources(widgets/battery_arc_peripheral.c)
    zephyr_library_sources(widgets/output_arc.c)
    zephyr_library_sources(widgets/chart.c)
  else()
    zephyr_library_sources(widgets/battery.c)
    zephyr_library_sources(widgets/battery_peripheral.c)
    zephyr_library_sources(widgets/output.c)
  endif()
  zephyr_library_sources(widgets/util.c)
  
  if(NOT CONFIG_ZMK_SPLIT OR CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
    if(CONFIG_TOUCAN_STATUS_SCREEN EQUAL 1)
      zephyr_library_sources(widgets/profile.c)
      zephyr_library_sources(widgets/layer_logo.c)
      zephyr_library_sources(widgets/output.c)
    elseif (CONFIG_TOUCAN_STATUS_SCREEN EQUAL 2)
      zephyr_library_sources(widgets/profile_arc.c)
      zephyr_library_sources(widgets/layer_arc.c)
      zephyr_library_sources(widgets/output_arc.c)
    else()
      zephyr_library_sources(widgets/profile.c)
      zephyr_library_sources(widgets/layer.c)
      zephyr_library_sources(widgets/output.c)
    endif()
    zephyr_library_sources(widgets/screen.c)
    zephyr_library_sources(widgets/sleep.c)
    zephyr_library_sources(widgets/version.c)

    # Abbreviated hash of the commit this firmware was built from, shown on the display.
    # GitHub Actions provides GITHUB_SHA; local builds fall back to git.
    if(DEFINED ENV{GITHUB_SHA})
      string(SUBSTRING "$ENV{GITHUB_SHA}" 0 7 TOUCAN_FIRMWARE_COMMIT)
    else()
      execute_process(
        COMMAND git rev-parse --short=7 HEAD
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        OUTPUT_VARIABLE TOUCAN_FIRMWARE_COMMIT
        OUTPUT_STRIP_TRAILING_WHITESPACE
        ERROR_QUIET
      )
    endif()
    if(TOUCAN_FIRMWARE_COMMIT)
      zephyr_library_compile_definitions(TOUCAN_FIRMWARE_COMMIT="${TOUCAN_FIRMWARE_COMMIT}")
    endif()
  endif()
endif()