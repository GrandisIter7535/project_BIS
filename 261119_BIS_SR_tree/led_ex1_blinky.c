
#include "driverlib.h"
#include "device.h"
#include "board.h"
#include "c2000ware_libraries.h"

#include "easy28x_driverlib_v12.2.h"

#define POWER_STAGE_DELAY_US       40000UL
#define LEVEL_SHIFTER_SETTLE_US     1000UL
#define RF_AFTER_RESET_DELAY_US    10000UL
#define RF_BUSY_POLL_DELAY_US       1000UL
#define RF_BUSY_MAX_POLLS            100U

// EasyDSP에서 확인할 변수
volatile uint16_t gLedState = 0U;
volatile uint16_t gRfReady = 0U;

static void powerOnAfe(void)
{
    GPIO_writePin(AFE_RESET_N, 0U);
    GPIO_writePin(AFE_IO_EN, 0U);

    GPIO_writePin(AFE_EN, 1U);
    GPIO_writePin(LED1_GPIO, 1U);
    gLedState = 1U;
    DEVICE_DELAY_US(POWER_STAGE_DELAY_US);

    GPIO_writePin(AFE_IO_PWR, 1U);
    DEVICE_DELAY_US(POWER_STAGE_DELAY_US);

    GPIO_writePin(AFE_IO_EN, 1U);
    DEVICE_DELAY_US(LEVEL_SHIFTER_SETTLE_US);
    GPIO_writePin(AFE_RESET_N, 1U);
}

static bool powerOnRf(void)
{
    uint16_t poll;

    GPIO_writePin(RF_RESET_N, 0U);
    GPIO_writePin(RF_IO_EN, 0U);

    GPIO_writePin(RF_EN, 1U);
    DEVICE_DELAY_US(POWER_STAGE_DELAY_US);

    GPIO_writePin(RF_IO_EN, 1U);
    DEVICE_DELAY_US(LEVEL_SHIFTER_SETTLE_US);
    GPIO_writePin(RF_RESET_N, 1U);
    DEVICE_DELAY_US(RF_AFTER_RESET_DELAY_US);

    for(poll = 0U; poll < RF_BUSY_MAX_POLLS; ++poll)
    {
        if(GPIO_readPin(RF_BUSY) == 0U)
        {
            return true;
        }
        DEVICE_DELAY_US(RF_BUSY_POLL_DELAY_US);
    }

    return GPIO_readPin(RF_BUSY) == 0U;
}

static void powerOff(void)
{
    gRfReady = 0U;
    GPIO_writePin(RF_RESET_N, 0U);
    GPIO_writePin(RF_IO_EN, 0U);
    GPIO_writePin(RF_EN, 0U);

    GPIO_writePin(AFE_RESET_N, 0U);
    GPIO_writePin(AFE_IO_EN, 0U);
    GPIO_writePin(AFE_IO_PWR, 0U);
    GPIO_writePin(AFE_EN, 0U);
    GPIO_writePin(LED1_GPIO, 0U);
    gLedState = 0U;
}

void main(void)
{
    Device_init();

    // GPIO18/X2를 LED 출력으로 사용합니다.
    SysCtl_turnOffOsc(SYSCTL_OSCSRC_XTAL);

    Device_initGPIO();
    Interrupt_initModule();
    Interrupt_initVectorTable();

    // RESET, 전원 제어, LED 및 DONE 출력을 LOW로 초기화합니다.
    Board_init();
    C2000Ware_libraries_init();

    easyDSP_SCI_Init();
    EINT;
    ERTM;

    powerOnAfe();
    if(powerOnRf())
    {
        gRfReady = 1U;
    }
    else
    {
        powerOff();
    }

    for(;;)
    {
        // easyDSP SCI 요청은 인터럽트에서 처리합니다.
    }
}
