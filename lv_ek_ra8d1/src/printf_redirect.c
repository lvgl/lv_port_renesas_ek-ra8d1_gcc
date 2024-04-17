#if 1
#include "hal_data.h"
#include "LVGL_thread.h"
#include "stdio.h"

void uart_callback(uart_callback_args_t *p_args)
{
    BaseType_t xHigherPriorityTaskWoken;
    BaseType_t xResult = pdFAIL;

    if (UART_EVENT_TX_COMPLETE == p_args->event)
    {
        xResult = xSemaphoreGiveFromISR( g_serial_binary_semaphore, &xHigherPriorityTaskWoken );
    }

    if( pdFAIL != xResult)
    {
        portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
    }
}

#if  defined(__GNUC__)
/* Nested in __GNUC__ because LLVM generates both __GNUC__ and __llvm__*/

 #if !defined(__llvm__)
#include <sys/stat.h>
#include <errno.h>
#undef errno
extern int errno;

int _write(int file, char *ptr, int len);
int _close(int file);
int _fstat(int file, struct stat *st);
int _isatty(int file);
int _read(int file, char *ptr, int len);
int _lseek(int file, int ptr, int dir);

#define DEBUG_SERIAL_TIMEOUT 2000/portTICK_PERIOD_MS



int _write(int file, char *ptr, int len)
{
    fsp_err_t err = FSP_SUCCESS;
    FSP_PARAMETER_NOT_USED(file);

    static bool uart_open = false;

    if (false == uart_open)
    {
        err = R_SCI_B_UART_Open(&g_uart0_ctrl, &g_uart0_cfg);
      if (FSP_SUCCESS == err)
      {
          uart_open = true;
          xSemaphoreGive( g_serial_binary_semaphore); //allow the first write to work.
      }

    }

    if (FSP_SUCCESS == err)
    {
#if defined(RENESAS_CORTEX_M85)
#if (BSP_CFG_DCACHE_ENABLED)
        SCB_CleanInvalidateDCache_by_Addr(ptr, len); //DTC is configured for UART TX
#endif
#endif

          err = R_SCI_B_UART_Write(&g_uart0_ctrl, (uint8_t *)ptr, (uint32_t)len);
          if (FSP_SUCCESS == err)
          {
              /* Wait for the previous USB Write to complete */
              if( xSemaphoreTake( g_serial_binary_semaphore, DEBUG_SERIAL_TIMEOUT ) != pdTRUE )
              {
                  __BKPT(0);
              }
          }
          else
          {
              __BKPT(0);
          }

    }

    if (FSP_SUCCESS != err)
    {
        len = -1;
    }

    return len;
}

int _close(int file)
{
  FSP_PARAMETER_NOT_USED(file);
  return -1;
}
int _fstat(int file, struct stat *st)
{
    FSP_PARAMETER_NOT_USED(file);
  st->st_mode = S_IFCHR;
  return 0;
}

int _isatty(int file)
{
    FSP_PARAMETER_NOT_USED(file);
  return 1;
}

int _lseek(int file, int ptr, int dir)
{
    FSP_PARAMETER_NOT_USED(file);
    FSP_PARAMETER_NOT_USED(ptr);
    FSP_PARAMETER_NOT_USED(dir);
  return 0;
}

int _read(int file, char *ptr, int len)
{
    FSP_PARAMETER_NOT_USED(file);
    FSP_PARAMETER_NOT_USED(ptr);
    FSP_PARAMETER_NOT_USED(len);
    return 0;
}
#elif !defined(__ARMCC_VERSION) && !defined(__CLANG_TIDY__)
int uart_putc(char c, FILE *file);

FILE __stdio = FDEV_SETUP_STREAM(uart_putc,
                    NULL,
                    NULL,
                    _FDEV_SETUP_WRITE);

FILE *const stdout = &__stdio;

#define DEBUG_SERIAL_TIMEOUT 2000/portTICK_PERIOD_MS

void uart_callback(uart_callback_args_t *p_args)
{
    BaseType_t xHigherPriorityTaskWoken;
    BaseType_t xResult = pdFAIL;

    if (UART_EVENT_TX_COMPLETE == p_args->event)
    {
        xResult = xSemaphoreGiveFromISR( g_serial_binary_semaphore, &xHigherPriorityTaskWoken );
    }

    if( pdFAIL != xResult)
    {
        portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
    }
}

int uart_putc(char c, FILE *file)
{
    fsp_err_t err = FSP_SUCCESS;
       FSP_PARAMETER_NOT_USED(file);

       static bool uart_open = false;

       if (false == uart_open)
       {
         err = R_SCI_B_UART_Open(&g_uart0_ctrl, &g_uart0_cfg);
         if (FSP_SUCCESS == err)
         {
             uart_open = true;
         }

       }

       if (FSP_SUCCESS == err)
       {
   #if defined(RENESAS_CORTEX_M85)
   #if (BSP_CFG_DCACHE_ENABLED)
           SCB_CleanInvalidateDCache_by_Addr(&c, 1); //DTC is configured for UART TX
   #endif
   #endif
             err = R_SCI_B_UART_Write(&g_uart0_ctrl, (uint8_t *)&c, (uint32_t)1);
             if (FSP_SUCCESS == err)
             {
                 /* Wait for the UART Write to complete */
                 if( xSemaphoreTake( g_serial_binary_semaphore, DEBUG_SERIAL_TIMEOUT ) != pdTRUE )
                 {
                    err = FSP_ERR_TIMEOUT;
                 }
             }
       }

       if (FSP_SUCCESS != err)
       {
           c = -1;
       }

       return c;
}
#endif
#endif
#endif
