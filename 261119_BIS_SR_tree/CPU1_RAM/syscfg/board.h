/*
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef BOARD_H
#define BOARD_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//
// Included Files
//

#include "driverlib.h"
#include "device.h"

//*****************************************************************************
//
// PinMux Configurations
//
//*****************************************************************************
//
// GPIO18 - GPIO Settings
//
#define LED1_GPIO_GPIO_PIN_CONFIG GPIO_18_GPIO18
//
// GPIO25 - GPIO Settings
//
#define AFE_EN_GPIO_PIN_CONFIG GPIO_25_GPIO25
//
// GPIO26 - GPIO Settings
//
#define RF_EN_GPIO_PIN_CONFIG GPIO_26_GPIO26
//
// GPIO21 - GPIO Settings
//
#define AFE_IO_PWR_GPIO_PIN_CONFIG GPIO_21_GPIO21
//
// GPIO41 - GPIO Settings
//
#define USB_PG_N_GPIO_PIN_CONFIG GPIO_41_GPIO41
//
// GPIO0 - GPIO Settings
//
#define myGPIO0_GPIO_PIN_CONFIG GPIO_0_GPIO0
//
// GPIO33 - GPIO Settings
//
#define RF_IO_EN_GPIO_PIN_CONFIG GPIO_33_GPIO33
//
// GPIO11 - GPIO Settings
//
#define AFE_IO_EN_GPIO_PIN_CONFIG GPIO_11_GPIO11
//
// GPIO42 - GPIO Settings
//
#define AFE_RESET_N_GPIO_PIN_CONFIG GPIO_42_GPIO42
//
// GPIO45 - GPIO Settings
//
#define RF_RESET_N_GPIO_PIN_CONFIG GPIO_45_GPIO45
//
// GPIO40 - GPIO Settings
//
#define RF_BUSY_GPIO_PIN_CONFIG GPIO_40_GPIO40
//
// GPIO31 - GPIO Settings
//
#define DONE_OS_FW_GPIO_PIN_CONFIG GPIO_31_GPIO31
//
// GPIO8 - GPIO Settings
//
#define DONE_MAIN_FW_GPIO_PIN_CONFIG GPIO_8_GPIO8

//
// SCIA -> EASY_SCIA Pinmux
//
//
// SCIA_RX - GPIO Settings
//
#define GPIO_PIN_SCIA_RX 28
#define EASY_SCIA_SCIRX_GPIO 28
#define EASY_SCIA_SCIRX_PIN_CONFIG GPIO_28_SCIA_RX
//
// SCIA_TX - GPIO Settings
//
#define GPIO_PIN_SCIA_TX 29
#define EASY_SCIA_SCITX_GPIO 29
#define EASY_SCIA_SCITX_PIN_CONFIG GPIO_29_SCIA_TX

//
// SPIA -> RF_SPIB Pinmux
//
//
// SPIA_PICO - GPIO Settings
//
#define GPIO_PIN_SPIA_PICO 224
#define RF_SPIB_SPIPICO_GPIO 224
#define RF_SPIB_SPIPICO_PIN_CONFIG GPIO_224_SPIA_PICO
//
// SPIA_POCI - GPIO Settings
//
#define GPIO_PIN_SPIA_POCI 13
#define RF_SPIB_SPIPOCI_GPIO 13
#define RF_SPIB_SPIPOCI_PIN_CONFIG GPIO_13_SPIA_POCI
//
// SPIA_CLK - GPIO Settings
//
#define GPIO_PIN_SPIA_CLK 12
#define RF_SPIB_SPICLK_GPIO 12
#define RF_SPIB_SPICLK_PIN_CONFIG GPIO_12_SPIA_CLK
//
// SPIA_PTE - GPIO Settings
//
#define GPIO_PIN_SPIA_PTE 242
#define RF_SPIB_SPIPTE_GPIO 242
#define RF_SPIB_SPIPTE_PIN_CONFIG GPIO_242_SPIA_PTE

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
#define LED1_GPIO 18
void LED1_GPIO_init();
#define AFE_EN 25
void AFE_EN_init();
#define RF_EN 26
void RF_EN_init();
#define AFE_IO_PWR 21
void AFE_IO_PWR_init();
#define USB_PG_N 41
void USB_PG_N_init();
#define myGPIO0 0
void myGPIO0_init();
#define RF_IO_EN 33
void RF_IO_EN_init();
#define AFE_IO_EN 11
void AFE_IO_EN_init();
#define AFE_RESET_N 42
void AFE_RESET_N_init();
#define RF_RESET_N 45
void RF_RESET_N_init();
#define RF_BUSY 40
void RF_BUSY_init();
#define DONE_OS_FW 31
void DONE_OS_FW_init();
#define DONE_MAIN_FW 8
void DONE_MAIN_FW_init();

//*****************************************************************************
//
// SCI Configurations
//
//*****************************************************************************
#define EASY_SCIA_BASE SCIA_BASE
#define EASY_SCIA_BAUDRATE 115200
#define EASY_SCIA_CONFIG_WLEN SCI_CONFIG_WLEN_8
#define EASY_SCIA_CONFIG_STOP SCI_CONFIG_STOP_ONE
#define EASY_SCIA_CONFIG_PAR SCI_CONFIG_PAR_NONE
#define EASY_SCIA_FIFO_TX_LVL SCI_FIFO_TX0
#define EASY_SCIA_FIFO_RX_LVL SCI_FIFO_RX0
void EASY_SCIA_init();

//*****************************************************************************
//
// SPI Configurations
//
//*****************************************************************************
#define RF_SPIB_BASE SPIA_BASE
#define RF_SPIB_BITRATE 1000000
#define RF_SPIB_DATAWIDTH 16
void RF_SPIB_init();

//*****************************************************************************
//
// SYSCTL Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void	Board_init();
void	GPIO_init();
void	SCI_init();
void	SPI_init();
void	SYSCTL_init();
void	PinMux_init();

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif  // end of BOARD_H definition
