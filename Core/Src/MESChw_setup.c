/*
 **
 ******************************************************************************
 * @file           : MESChw_setup.c
 * @brief          : Initialisation code for the PCB
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 David Molony.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************

 * MESChw_setup.c
 *
 *  Created on: 25 Jul 2020
 *      Author: David Molony
 */
/* Includes ------------------------------------------------------------------*/
#include "MESChw_setup.h"

void motor_init() {
    motor.Rphase = 0;  // We init at 0 to trigger the measurer to get the vals
    motor.Lphase = 0;  // We init at 0 to trigger the measurer to get the vals
    motor.uncertainty = 1;

}

void hw_init() {
    g_hw_setup.Vmax = 60.0;
    g_hw_setup.Rshunt = 0.0005;
    g_hw_setup.RIphPU = 4700;
    g_hw_setup.RIphSR = 150;
    g_hw_setup.RVBB = 1500;
    g_hw_setup.RVBT = 82000;
    g_hw_setup.OpGain = 16;  // Can this be inferred from the HAL declaration?
    g_hw_setup.VBGain = (3.3f/4096.0f)*(g_hw_setup.RVBB + g_hw_setup.RVBT)/g_hw_setup.RVBB;
    g_hw_setup.Igain =
        3.3 / (g_hw_setup.Rshunt * 4096 * g_hw_setup.OpGain *
               g_hw_setup.RIphPU / (g_hw_setup.RIphPU + g_hw_setup.RIphSR));
    g_hw_setup.RawCurrLim = 4000;
    g_hw_setup.RawVoltLim = (uint16_t)(4096.0f*(g_hw_setup.Vmax/3.3f)*g_hw_setup.RVBB/(g_hw_setup.RVBB+g_hw_setup.RVBT));
}
