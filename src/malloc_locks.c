#include <LVGL_thread.h>
void __malloc_lock(struct _reent *r) ;
void __malloc_unlock(struct _reent *r) ;

void __malloc_lock(struct _reent *r)   {
    bool insideAnISR = xPortIsInsideInterrupt();
    configASSERT( !insideAnISR ); // Make damn sure no more mallocs inside ISRs!!
  vTaskSuspendAll();
};
void __malloc_unlock(struct _reent *r) {
  (void)xTaskResumeAll();
};
