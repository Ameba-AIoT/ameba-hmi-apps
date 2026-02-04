##########################################################################################
## * This part defines public part of the component
## * Public part will be used as global build configures for all component

set(public_includes)                # public include directories, NOTE: relative path is OK
set(public_definitions)             # public definitions
set(public_libraries)               # public libraries(files), NOTE: linked with whole-archive options

#----------------------------------------#
# Component public part, user config begin

# You may use if-else condition to set or update predefined variable above

# Component public part, user config end
#----------------------------------------#

# WARNING: Fixed section, DO NOT change!
ameba_global_include(${public_includes})
ameba_global_define(${public_definitions})
ameba_global_library(${public_libraries}) #default: whole-archived

##########################################################################################
## * This part defines private part of the component
## * Private part is used to build target of current component
## * NOTE: The build API guarantees the global build configures(mentioned above)
## *       applied to the target automatically. So if any configure was already added
## *       to public above, it's unnecessary to add again below.

# NOTE: User defined section, add your private build configures here
# You may use if-else condition to set these predefined variable
# They are only for ameba_add_internal_library/ameba_add_external_app_library/ameba_add_external_soc_library

set(private_sources)                 # private source files, NOTE: relative path is OK
set(private_includes)                # private include directories, NOTE: relative path is OK
set(private_definitions)             # private definitions
set(private_compile_options)         # private compile_options

ameba_list_append(private_sources
    app_main.c
    ui.c
    ui_helpers.c
    components/ui_comp_dropdown.c
    components/ui_comp_roller.c
    components/ui_comp.c
    components/ui_comp_hook.c
    screens/ui_Home.c
    screens/ui_Settings.c
    images/ui_img_ebike_bg_png.c
    images/ui_img_slider_battery_png.c
    images/ui_img_speed_slider_png.c
    images/ui_img_icn_flash_png.c
    images/ui_img_menu_on_png.c
    images/ui_img_icn_bike_png.c
    images/ui_img_icn_battery_png.c
    images/ui_img_icn_map_png.c
    images/ui_img_menu_line_png.c
    images/ui_img_particle_1_png.c
    images/ui_img_water_2_png.c
    images/ui_img_particle_3_png.c
    images/ui_img_water_1_png.c
    images/ui_img_particle_2_png.c
    images/ui_img_battery_bg_png.c
    images/ui_img_icn_charge_png.c
    images/ui_img_pin_line_png.c
    images/ui_img_pin_on_png.c
    images/ui_img_icn_x_png.c
    images/ui_img_icn_ok_png.c
    images/ui_img_map_png.c
    images/ui_img_gps_knob_png.c
    images/ui_img_gps_bg_png.c
    images/ui_img_right_png.c
    images/ui_img_settings_corner_png.c
    images/ui_img_icn_settings_png.c
    images/ui_img_settings_bg_png.c
    images/ui_img_volume_on_png.c
    images/ui_img_volume_off_png.c
    images/ui_img_icn_x2_png.c
    fonts/ui_font_Big.c
    fonts/ui_font_Medium.c
    fonts/ui_font_Number.c
    fonts/ui_font_Small.c
)

ameba_list_append(private_compile_options
    -Wno-unused-parameter
)

ameba_add_internal_library(ebike
    p_SOURCES
        ${private_sources}
    p_INCLUDES
        ${private_includes}
    p_DEFINITIONS
        ${private_definitions}
    p_COMPILE_OPTIONS
        ${private_compile_options}
)
