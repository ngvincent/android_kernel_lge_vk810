/*
 * Copyright (C) 2013 LG Electronics Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/kernel.h>

#include "slimport_register_set_test.h"
#include "slimport_tx_reg.h"

extern int sp_write_reg(uint8_t slave_addr, uint8_t offset, uint8_t value);

#if defined (CONFIG_MACH_APQ8064_ALTEV)

static void slimport_tx_link_phy_init_for_altev_vzw_us(void)
{
	pr_err("%s: slimport tx init [131127] \n", __func__);
    
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG0, 0x19);
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG1, 0x26);
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG2, 0x3F);
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG3, 0x3F);
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG4, 0x1b);
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG5, 0x28);
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG6, 0x3c);
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG7, 0x22);
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG8, 0x2F);
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG9, 0x23);
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG12, 0x0E);
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG14, 0x09);
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG15, 0x10);
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG16, 0x1F);
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG17, 0x16);
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG18, 0x1F);
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG19, 0x1F);

	sp_write_reg(TX_P2, 0xDC, 0x68);
}
#else

/* PHY parameter for CTS for APQ8064 base */
static void slimport_tx_link_phy_init_for_apq8064_base(void)
{
	pr_err("%s: slimport tx init \n", __func__);
    
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG4, 0x1b);
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG7, 0x22);
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG9, 0x23);
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG14, 0x09);
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG17, 0x16);
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG19, 0x1F);
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG1, 0x26);
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG5, 0x28);
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG8, 0x2F);
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG15, 0x10);
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG18, 0x1F);
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG2, 0x36);
	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG6, 0x3c);
		sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG0, 0x19);
		sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG16, 0x18);

	sp_write_reg(TX_P1, SP_TX_LT_CTRL_REG3, 0x3F);
}


#endif
void slimport_tx_link_phy_init(void)
{
#if defined(CONFIG_MACH_APQ8064_ALTEV)
	slimport_tx_link_phy_init_for_altev_vzw_us();
#else 
	slimport_tx_link_phy_init_for_apq8064_base();
#endif
}
