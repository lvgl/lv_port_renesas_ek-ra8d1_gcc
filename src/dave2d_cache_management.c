#include "hal_data.h"
#include "r_drw_base.h"

#include "r_drw_cfg.h"

#if (BSP_CFG_RTOS == 2)                // FreeRTOS
 #include "FreeRTOS.h"
#endif

//Override the default weak functions in ra/fsp/src/r_drw/r_drw_memory.c

d1_int_t d1_cacheflush (d1_device * handle, d1_int_t memtype)
{

    FSP_PARAMETER_NOT_USED(handle);
    FSP_PARAMETER_NOT_USED(memtype);

#if defined(RENESAS_CORTEX_M85) && (BSP_CFG_DCACHE_ENABLED)
    SCB_CleanInvalidateDCache();
#endif

    return 1;
}

d1_int_t d1_cacheblockflush (d1_device * handle, d1_int_t memtype, const void * ptr, d1_uint_t size)
{
    FSP_PARAMETER_NOT_USED(handle);
    FSP_PARAMETER_NOT_USED(memtype);

#if defined(RENESAS_CORTEX_M85) && (BSP_CFG_DCACHE_ENABLED)
    SCB_CleanInvalidateDCache_by_Addr((void *)ptr, (int32_t)size);
#else
    FSP_PARAMETER_NOT_USED(ptr);
    FSP_PARAMETER_NOT_USED(size);
#endif

    return 1;
}
