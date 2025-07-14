#ifndef USER_FREERTOSCONFIG_H_
#define USER_FREERTOSCONFIG_H_

#include  "src/lv_conf_internal.h"

#if LV_USE_OS == LV_OS_FREERTOS

#define configUSE_TRACE_FACILITY 1

void lv_freertos_task_switch_in(const char * name);
void lv_freertos_task_switch_out(void);

#define traceTASK_SWITCHED_IN()   lv_freertos_task_switch_in(pxCurrentTCB->pcTaskName);
#define traceTASK_SWITCHED_OUT()  lv_freertos_task_switch_out();

#endif

#endif /* USER_FREERTOSCONFIG_H_ */
