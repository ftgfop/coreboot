/* SPDX-License-Identifier: GPL-2.0-or-later */

#ifndef ARMV7_H
#define ARMV7_H
#include <types.h>

/* Cortex-A9 revisions */
#define MIDR_CORTEX_A9_R0P1	0x410FC091
#define MIDR_CORTEX_A9_R1P2	0x411FC092
#define MIDR_CORTEX_A9_R1P3	0x411FC093
#define MIDR_CORTEX_A9_R2P10	0x412FC09A

/* Cortex-A15 revisions */
#define MIDR_CORTEX_A15_R0P0	0x410FC0F0

/* CCSIDR */
#define CCSIDR_LINE_SIZE_OFFSET		0
#define CCSIDR_LINE_SIZE_MASK		0x7
#define CCSIDR_ASSOCIATIVITY_OFFSET	3
#define CCSIDR_ASSOCIATIVITY_MASK	(0x3FF << 3)
#define CCSIDR_NUM_SETS_OFFSET		13
#define CCSIDR_NUM_SETS_MASK		(0x7FFF << 13)

/*
 * Values for InD field in CSSELR
 * Selects the type of cache
 */
#define ARMV7_CSSELR_IND_DATA_UNIFIED	0
#define ARMV7_CSSELR_IND_INSTRUCTION	1

/* Values for Ctype fields in CLIDR */
#define ARMV7_CLIDR_CTYPE_NO_CACHE		0
#define ARMV7_CLIDR_CTYPE_INSTRUCTION_ONLY	1
#define ARMV7_CLIDR_CTYPE_DATA_ONLY		2
#define ARMV7_CLIDR_CTYPE_INSTRUCTION_DATA	3
#define ARMV7_CLIDR_CTYPE_UNIFIED		4

/*
 * CP15 Barrier instructions
 * Please note that we have separate barrier instructions in ARMv7
 * However, we use the CP15 based instructions because we use
 * -march=armv5 in U-Boot
 */
#define CP15ISB	(asm volatile ("mcr     p15, 0, %0, c7, c5, 4" : : "r" (0)))
#define CP15DSB	(asm volatile ("mcr     p15, 0, %0, c7, c10, 4" : : "r" (0)))
#define CP15DMB	(asm volatile ("mcr     p15, 0, %0, c7, c10, 5" : : "r" (0)))

#endif /* ARMV7_H */
