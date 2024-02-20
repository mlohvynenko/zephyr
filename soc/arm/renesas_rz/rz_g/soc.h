/*
 * Copyright (c) 2024 EPAM Systems
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 */

#ifndef _SOC__H_
#define _SOC__H_

#ifndef _ASMLANGUAGE

/* __CM33_REV                0x0004U   Core revision r0p4
 * M33 core0 - no FPU, M33 core1 - with FPU
 */
#define __SAUREGION_PRESENT CONFIG_CPU_HAS_ARM_SAU
#define __VTOR_PRESENT      CONFIG_CPU_CORTEX_M_HAS_VTOR
#define __MPU_PRESENT       CONFIG_CPU_HAS_ARM_MPU
#define __FPU_PRESENT       CONFIG_CPU_HAS_FPU /* FPU present */
#define __DSP_PRESENT       CONFIG_ARMV8_M_DSP /* DSP ext present - no */
#define __DCACHE_PRESENT    CONFIG_CPU_HAS_DCACHE /* DCACHE present - no */
#define __ICACHE_PRESENT    CONFIG_CPU_HAS_ICACHE /* ICACHE present - no */

/*
 * Macro to convert across CM33/CM33_FPU and A55 address spaces
 * This macro are designed to convert CM33 addresses to A55 addresses
 * in secure and non-secure space. According to Table 5.2 of HW Manual.
 */
#define CM33_ADDRESS_OFFSET_SECURE    (0x30000000)
#define CM33_ADDRESS_OFFSET_NONSECURE (0x20000000)
#define CM33_TO_A55_ADDR_S(x)         ((x)-CM33_ADDRESS_OFFSET_SECURE)
#define CM33_TO_A55_ADDR_NS(x)        ((x)-CM33_ADDRESS_OFFSET_NONSECURE)

#endif /* !_ASMLANGUAGE */

#endif /* _SOC__H_ */