
#include "F28x_Project.h"
#include "easy28x_bitfield_v12.2.h"

// Monitoring variable for easyDSP
volatile Uint32 bis_test_counter = 0;

/* W11-4 Power Sequence
 * State definitions only.
 * No GPIO control is performed at this stage.
 */
 
#define BIS_PS_IDLE             0U
#define BIS_PS_RAIL_ENABLE      1U
#define BIS_PS_RAIL_WAIT        2U
#define BIS_PS_IO_ENABLE        3U
#define BIS_PS_RESET_RELEASE    4U

#define BIS_PS_ACTIVE            5U
#define BIS_PS_OE_DISABLE        6U
#define BIS_PS_IO_POWER_DISABLE  7U
#define BIS_PS_RAIL_DISABLE      8U
#define BIS_PS_DONE              9U


/* State variable for easyDSP monitoring */
volatile Uint16 bis_powerseq_state = BIS_PS_IDLE;

/* W11-4 manual state transition request
 * 0 = No request
 * 1 = Advance one state
 * No GPIO control
 */
volatile Uint16 bis_powerseq_step_request = 0U;

/* W11-4 GPIO mapping
 * Based on BIS schematic handoff.
 * Pin assignments require final EDA verification.
 * Definitions only - no GPIO output control.
 */

#define BIS_GPIO_AFE_EN        25U
#define BIS_GPIO_AFE_IO_PWR    21U
#define BIS_GPIO_AFE_IO_EN     11U

#define BIS_GPIO_RF_EN         26U
#define BIS_GPIO_RF_IO_EN      33U

#define BIS_GPIO_DONE_OS       31U
#define BIS_GPIO_DONE_MAIN      8U

/* W11-4 planned output requests
 * Software-only flags for simulation.
 * These flags do NOT drive physical GPIO pins.
 */

#define BIS_REQ_AFE_RAIL     (1U << 0)
#define BIS_REQ_AFE_IO_PWR   (1U << 1)
#define BIS_REQ_RF_RAIL      (1U << 2)

#define BIS_REQ_AFE_IO_OE    (1U << 3)
#define BIS_REQ_RF_IO_OE     (1U << 4)

/* W11-4 compile-time mask checks
 * No physical GPIO control.
 */

#if ((BIS_REQ_AFE_RAIL | \
      BIS_REQ_AFE_IO_PWR | \
      BIS_REQ_RF_RAIL) != 0x0007U)
#error "W11-4 rail mask mismatch"
#endif

#if ((BIS_REQ_AFE_RAIL | \
      BIS_REQ_AFE_IO_PWR | \
      BIS_REQ_RF_RAIL | \
      BIS_REQ_AFE_IO_OE | \
      BIS_REQ_RF_IO_OE) != 0x001FU)
#error "W11-4 full mask mismatch"
#endif

/* Planned output request mask */
volatile Uint16 bis_powerseq_plan_mask = 0U;


int main(void)
{
    volatile Uint32 delay_count;

    // Initialize MCU system clock
    InitSysCtrl();

    // Initialize interrupt controller
    DINT;
    InitPieCtrl();

    IER = 0x0000;
    IFR = 0x0000;

    InitPieVectTable();

    // Initialize easyDSP SCI-A communication
    easyDSP_SCI_Init();

    // Main loop
    while(1)
    {
        bis_test_counter++;

        /* W11-4 state transition test only */
        if (bis_powerseq_step_request == 1U)
        {
            bis_powerseq_step_request = 0U;

            if (bis_powerseq_state < BIS_PS_DONE)
            {
                bis_powerseq_state++;
            }
            else
            {
                bis_powerseq_state = BIS_PS_IDLE;
            }
        }

/* W11-4 software-only output plan */

if (bis_powerseq_state == BIS_PS_IDLE)
{
    bis_powerseq_plan_mask = 0U;
}
else if (bis_powerseq_state <= BIS_PS_RAIL_WAIT)
{
    bis_powerseq_plan_mask =
        BIS_REQ_AFE_RAIL |
        BIS_REQ_AFE_IO_PWR |
        BIS_REQ_RF_RAIL;
}
else if (bis_powerseq_state <= BIS_PS_ACTIVE)
{
    bis_powerseq_plan_mask =
        BIS_REQ_AFE_RAIL |
        BIS_REQ_AFE_IO_PWR |
        BIS_REQ_RF_RAIL |
        BIS_REQ_AFE_IO_OE |
        BIS_REQ_RF_IO_OE;
}
else if (bis_powerseq_state == BIS_PS_OE_DISABLE)
{
    bis_powerseq_plan_mask =
        BIS_REQ_AFE_RAIL |
        BIS_REQ_AFE_IO_PWR |
        BIS_REQ_RF_RAIL;
}
else if (bis_powerseq_state == BIS_PS_IO_POWER_DISABLE)
{
    bis_powerseq_plan_mask =
        BIS_REQ_AFE_RAIL |
        BIS_REQ_RF_RAIL;
}
else
{
    bis_powerseq_plan_mask = 0U;
}



        // Simple software delay (not calibrated)
        for(delay_count = 0;
            delay_count < 1000000UL;
            delay_count++)
        {
        }
    }
}
