#ifndef _UI_COMP_ROLLER_H
#define _UI_COMP_ROLLER_H

#include "../ui.h"

#ifdef __cplusplus
extern "C" {
#endif

// COMPONENT Roller
#define UI_COMP_ROLLER_ROLLER 0
#define UI_COMP_ROLLER_LABEL_ROLLER 1
#define UI_COMP_ROLLER_ROLLER2 2
#define _UI_COMP_ROLLER_NUM 3
lv_obj_t * ui_Roller_create(lv_obj_t * comp_parent);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
