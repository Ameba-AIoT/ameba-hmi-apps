#include <stdio.h>
#include "ameba_soc.h"
#include "os_wrapper.h"

#include "lvgl.h"
#include "lv_ameba_hal.h"
#include "ui.h"

#define LOG_TAG "LV-Demos"

void caffee_machine(void *param) {
    UNUSED(param);

    lv_init();
    lv_ameba_hal_init();
    ui_init();

    /* To hide the memory and performance indicators in the corners
     * disable `LV_USE_MEM_MONITOR` and `LV_USE_PERF_MONITOR` in `lv_conf.h`*/

    while(1) {
        /* Periodically call the lv_task handler.
         * It could be done in a timer interrupt or an OS task too.*/
        uint32_t time_till_next = lv_task_handler();

        /* handle LV_NO_TIMER_READY. Another option is to `sleep` for longer */
        if(time_till_next == LV_NO_TIMER_READY)
            time_till_next = LV_DEF_REFR_PERIOD;

        /* delay to avoid unnecessary polling */
        rtos_time_delay_ms(time_till_next);
    }

    lv_deinit();

    rtos_task_delete(NULL);
}

void app_example(void) {
    rtos_task_create(NULL, "caffee_machine", caffee_machine, NULL, 1024 * 32, 1);
}
