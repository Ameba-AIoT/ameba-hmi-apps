/**
 * @file lv_demo_smarthub.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "smarthub_private.h"
#if LV_USE_DEMO_SMARTHUB

#if LV_FS_DEFAULT_DRIVER_LETTER == '\0'
    #error set a default drive letter (and enable an FS driver) for the smart hub demo
#endif

#if !LV_FONT_FMT_TXT_LARGE
    #error LV_FONT_FMT_TXT_LARGE needs to be enabled in lv_conf.h for the smart hub demo
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void smarthub_test(void)
{
    smarthub_api_example("A:assets", "A:assets/img_smarthub_lvgl_logo.png", "A:about_app_slides");
}

smarthub_api_t * lv_demo_smarthub(const char * assets_path,
                                          const char * logo_path,
                                          const char * slides_path,
                                          smarthub_exit_cb_t exit_cb)
{
    if(assets_path == NULL) assets_path = "lvgl/demos/smarthub/assets";
    if(logo_path == NULL) logo_path = "lvgl/demos/smarthub/assets/img_smarthub_lvgl_logo.png";
    if(slides_path == NULL) slides_path = "about_app_slides";
    lv_obj_t * base_obj = smarthub_base_obj_create(assets_path, logo_path, slides_path, exit_cb);
    smarthub_home(base_obj);

    smarthub_ctx_t * c = lv_obj_get_user_data(base_obj);
    return &c->api;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /*LV_USE_DEMO_SMARTHUB*/
