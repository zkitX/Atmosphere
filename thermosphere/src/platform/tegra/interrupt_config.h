/*
 * Copyright (c) 2019 Atmosphère-NX
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "../../gicv2.h"

// For both guest and host
#define MAX_NUM_REGISTERED_INTERRUPTS 512

#define GIC_IRQID_MAINTENANCE       25
#define GIC_IRQID_HYP_TIMER         26
#define GIC_IRQID_VIRT_TIMER        27
#define GIC_IRQID_LEGACY_NFIQ       28
#define GIC_IRQID_SEC_PHYS_TIMER    29
#define GIC_IRQID_NS_PHYS_TIMER     30
#define GIC_IRQID_LEGACY_NIRQ       31


static inline void initGicV2Pointers(ArmGicV2 *gic)
{
    gic->gicd = (volatile ArmGicV2Distributor *)0x50041000ull;
    gic->gicc = (volatile ArmGicV2Controller *)0x50042000ull;
    gic->gich = (volatile ArmGicV2VirtualInterfaceController *)0x50044000ull;
    gic->gicv = (volatile ArmGicV2Controller *)0x50046000ull;
}