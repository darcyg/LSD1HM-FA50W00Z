/*
 * (C) Copyright 2007-2011
 * Allwinner Technology Co., Ltd. <www.allwinnertech.com>
 * Jerry Wang<wangflord@allwinnertech.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

//#define DEBUG  1
#undef DEBUG

#ifndef __KERNEL__
#define __KERNEL__
#endif

#define LINUX_MACHINE_ID        4137

#define UBOOT_VERSION			"1.1.0"
#define UBOOT_PLATFORM		    "1.0.0"

#define CONFIG_TARGET_NAME      sun8iw8p1_nor
#define CONFIG_PLATFORM_NAME    sun8iw8p1

#define CONFIG_SUNXI_SPINOR_PLATFORM

#define CONFIG_SUN8IW8P1_SPI 
#define CONFIG_SUNXI_SPINOR 
#define CONFIG_SPINOR_LOGICAL_OFFSET        ((512 - 16) * 1024/512)

#define CONFIG_SPI_DUAL_MODE
/*
 * High Level Configuration Options
 */
#define CONFIG_ARM_A7
#define CONFIG_ALLWINNER			/* It's a Allwinner chip */
#define	CONFIG_SUNXI				/* which is sunxi family */

#define CONFIG_ARCH_SUN8IW8P1
#define CONFIG_ARCH_SUN8IW8
//#define FORCE_BOOT_STANDBY
#define CONFIG_NO_BOOT_STANDBY
#define CONFIG_SYS_SDRAM_BASE		     (0x40000000)
#define CONFIG_SYS_TEXT_BASE		     (0x40900000)
// the sram base address, and the stack address in stage1
#define CONFIG_SYS_INIT_RAM_ADDR	     (0x00000000)
#define CONFIG_SYS_INIT_RAM_SIZE	     (0x00008000) //0x00048000

#define CONFIG_SYS_INIT_SP_OFFSET \
	(CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)
#define CONFIG_SYS_INIT_SP_ADDR \
	(CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_SP_OFFSET)

#define CONFIG_NR_DRAM_BANKS		1
#define PHYS_SDRAM_1				CONFIG_SYS_SDRAM_BASE	/* SDRAM Bank #1 */
#define PHYS_SDRAM_1_SIZE			(512 << 20)				/* 0x20000000, 512 MB Bank #1 */

#define CONFIG_NONCACHE_MEMORY
#define CONFIG_NONCACHE_MEMORY_SIZE (20 * 1024 * 1024)
/*
 * define malloc space
 * Size of malloc() pool
 * 1MB = 0x100000, 0x100000 = 1024 * 1024
 */
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + (4 << 20))


/*
* define all parameters
*/
//define storage in boot0 
#define CONFIG_STORAGE_MEDIA_SPINOR
#define CONFIG_STORAGE_MEDIA_MMC

#define UBOOT_START_SECTOR_IN_SPINOR     (24*1024/512)
#define CONFIG_STANDBY_RUN_ADDR          (0x1000)
#define BOOT_STANDBY_DRAM_PARA_ADDR      (0xf00)

#define MMU_BASE_ADDRESS		 	     (0x8000)
#define BOOT0_SYS_MMU_BASE                            (0x8000)          

#define SUNXI_RUN_EFEX_ADDR			     (0x01c20400 + 0x108)


#define DRAM_PARA_STORE_ADDR		     (CONFIG_SYS_SDRAM_BASE + 0x00800000)

#define SYS_CONFIG_MEMBASE               (CONFIG_SYS_SDRAM_BASE + SZ_16M)
#define CONFIG_SMALL_MEMSIZE                    

#define CONFIG_SUNXI_LOGBUFFER
#define CONFIG_READ_LOGO_FOR_KERNEL
#define SUNXI_DISPLAY_FRAME_BUFFER_ADDR  (CONFIG_SYS_SDRAM_BASE + 0x03200000)
#define SUNXI_DISPLAY_FRAME_BUFFER_SIZE  0x0100000

#define FEL_BASE                         0xFFFF0020
/*
* define const value
*/
#define BOOT_USB_DETECT_DELAY_TIME       (1000)

#define BOOT_STANDBY_MOD_ENTER_STANDBY	  0xf0
#define BOOT_STANDBY_MOD_EXIT_STANDBY	  0xf1

#define  FW_BURN_UDISK_MIN_SIZE		     (2 * 1024)

#define SUNXI_RUN_EFEX_FLAG              (0x5AA5A55A)

#define BOOT_MOD_ENTER_STANDBY       (0)
#define BOOT_MOD_EXIT_STANDBY        (1)

#define MEMCPY_TEST_DST                  (CONFIG_SYS_SDRAM_BASE)
#define MEMCPY_TEST_SRC                  (CONFIG_SYS_SDRAM_BASE + 0x06000000)
/****************************************************************************************/
/*																						*/
/*      the fowllowing defines are used in sbrom                                        */
/*																						*/
/****************************************************************************************/
#define BOOT_PUB_HEAD_VERSION           "1100"
#define EGON_VERSION                    "1100"

#define SUNXI_DRAM_PARA_MAX              32

#define CONFIG_BOOT0_STACK_BOTTOM        (0x8000)

#define CONFIG_SYS_SRAM_BASE             (0x0000)
//#define CONFIG_SYS_SRAMA2_BASE           (0x44000)
//#define CONFIG_SYS_SRAMA2_SIZE           (0x8000)

#define CONFIG_STACK_BASE                (CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_RAM_SIZE + CONFIG_SYS_SRAM_C_SIZE - 0x10)

#define CONFIG_HEAP_BASE                 (CONFIG_SYS_SDRAM_BASE + 0x800000)
#define CONFIG_HEAP_SIZE                 (16 * 1024 * 1024)

#define CONFIG_BOOT0_RET_ADDR            (CONFIG_SYS_SRAM_BASE)
#define CONFIG_BOOT0_RUN_ADDR            (0x0000)

#define CONFIG_FES1_RET_ADDR             (CONFIG_SYS_SRAM_BASE + 0x7210)
#define CONFIG_FES1_RUN_ADDR             (0x2000)
/***************************************************************
*
* all the config command
*
***************************************************************/
//#define CONFIG_SUNXI_RSB
#define CONFIG_SUNXI_I2C
#define CONFIG_PMU_USE_I2C
#define CONFIG_SYS_I2C_SPEED 400000
#define CONFIG_SYS_I2C_SLAVE 0x68
#define CONFIG_USE_IRQ
#define CONFIG_CMD_IRQ
//#define CONFIG_CMD_ELF
#define CONFIG_DOS_PARTITION
//#define CONFIG_CMD_BOOTA
#define CONFIG_SUNXI_DMA
//#define CONFIG_CMD_MEMORY
//#define CONFIG_SUNXI_DISPLAY


#define CONFIG_SUNXI_AXP
#define CONFIG_SUNXI_AXP20
#define CONFIG_SUNXI_AXP_MAIN        PMU_TYPE_20X
#define PMU_SCRIPT_NAME                 "pmu1_para"
//#define CONFIG_SUNXI_AXP_CONFIG_ONOFF

//#define CONFIG_SUNXI_SCRIPT_REINIT

#define BOARD_LATE_INIT				/* init the fastboot partitions */

#define CONFIG_USE_ARCH_MEMCPY       (1)
#define CONFIG_USE_ARCH_MEMSET       (1)
/*
 * Display CPU and Board information
 */
//#define CONFIG_DISPLAY_CPUINFO
//#define CONFIG_DISPLAY_BOARDINFO
#undef CONFIG_DISPLAY_CPUINFO
#undef CONFIG_DISPLAY_BOARDINFO

/* Serial & console */
#define CONFIG_SYS_NS16550
#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_SYS_NS16550_REG_SIZE	(-4)		/* ns16550 reg in the low bits of cpu reg */
#define CONFIG_SYS_NS16550_CLK		(24000000)
#define CONFIG_SYS_NS16550_COM1		SUNXI_UART0_BASE
#define CONFIG_SYS_NS16550_COM2		SUNXI_UART1_BASE
#define CONFIG_SYS_NS16550_COM3		SUNXI_UART2_BASE
#define CONFIG_SYS_NS16550_COM4		SUNXI_UART3_BASE

#define CONFIG_CONS_INDEX			1			/* which serial channel for console */


/* Nand config */
//#define CONFIG_NAND
//#define CONFIG_STORAGE_NAND
//#define CONFIG_NAND_SUNXI
//#define CONFIG_CMD_NAND                         /* NAND support */
#define CONFIG_SYS_MAX_NAND_DEVICE      1
#define CONFIG_SYS_NAND_BASE            0x00

#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_CMDLINE_TAG
#define CONFIG_INITRD_TAG
#define CONFIG_CMDLINE_EDITING

/* mmc config */
//#define CONFIG_MMC
//#define CONFIG_GENERIC_MMC
//#define CONFIG_CMD_MMC
//#define CONFIG_MMC_SUNXI
#define CONFIG_MMC_SUNXI_USE_DMA
#define CONFIG_ENV_IS_IN_MMC
#define CONFIG_STORAGE_EMMC
#define CONFIG_MMC_LOGICAL_OFFSET   (20 * 1024 * 1024/512)
//#define USE_EMMC_BOOT_PART

#define CONFIG_SUNXI_KEY_BURN
#define CONFIG_SUNXI_PRIVATE_KEY
#define CONFIG_SUNXI_MODULE_USB
#define CONFIG_SUNXI_KEY_SUPPORT
#define CONFIG_SUNXI_MODULE_SPRITE
#ifdef CONFIG_SUNXI_KEY_BURN
    #define CONFIG_CMD_SUNXI_BURN
#endif

//#define CONFIG_DOS_PARTITION
/*
 * Miscellaneous configurable options
 */
#define CONFIG_SYS_LONGHELP				/* undef to save memory */
#define CONFIG_SYS_HUSH_PARSER			/* use "hush" command parser	*/
#define CONFIG_SYS_PROMPT_HUSH_PS2	"> "
#define CONFIG_SYS_PROMPT		"sunxi#"
#define CONFIG_SYS_CBSIZE	256			/* Console I/O Buffer Size */
#define CONFIG_SYS_PBSIZE	384			/* Print Buffer Size */
#define CONFIG_SYS_MAXARGS	16			/* max number of command args */

/* Boot Argument Buffer Size */
#define CONFIG_SYS_BARGSIZE			CONFIG_SYS_CBSIZE

/* memtest works on */
#define CONFIG_SYS_MEMTEST_START	CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_MEMTEST_END		((CONFIG_SYS_SDRAM_BASE + 256)<<20)	/* 256M */
#define CONFIG_SYS_LOAD_ADDR		0x50000000					/* default load address */

#define CONFIG_SYS_HZ				1000

/* valid baudrates */
#define CONFIG_BAUDRATE				115200
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }

/*-----------------------------------------------------------------------
 * Stack sizes
 *
 * The stack sizes are set up in start.S using the settings below
 */
#define CONFIG_STACKSIZE			(256 << 10)				/* 256 KiB */
#define LOW_LEVEL_SRAM_STACK		0x00003FFC

#ifdef CONFIG_USE_IRQ
#define CONFIG_STACKSIZE_IRQ    (4*1024)        /* IRQ stack */
#define CONFIG_STACKSIZE_FIQ    (4*1024)        /* FIQ stack */
#endif

/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */
#define CONFIG_SYS_NO_FLASH

#define CONFIG_SYS_MONITOR_LEN		(256 << 10)	/* 256 KiB */
#define CONFIG_IDENT_STRING			" Allwinner Technology "

#define CONFIG_ENV_IS_IN_NAND_SUNXI	    /* we store env in one partition of our nand */
#define CONFIG_SUNXI_ENV_PARTITION		"env"	/* the partition name */

/*------------------------------------------------------------------------
 * we save the environment in a nand partition, the partition name is defined
 * in sysconfig.fex, which must be the same as CONFIG_SUNXI_NAND_ENV_PARTITION
 * if not, below CONFIG_ENV_ADDR and CONFIG_ENV_SIZE will be where to store env.
 * */
#define CONFIG_ENV_ADDR				(53 << 20)  /* 16M */
#define CONFIG_ENV_SIZE				(128 << 10)	/* 128KB */
#define CONFIG_CMD_SAVEENV

#define CONFIG_EXTRA_ENV_SETTINGS \
	"bootdelay=3\0" \
	"bootcmd=run setargs_nand boot_normal\0" \
	"console=ttyS0,115200\0" \
	"nand_root=/dev/nandd\0" \
	"mmc_root=/dev/mmcblk0p7\0" \
	"init=/init\0" \
	"loglevel=8\0" \
	"setargs_nand=setenv bootargs console=${console} root=${nand_root}" \
	"init=${init} loglevel=${loglevel} partitions=${partitions}\0" \
	"setargs_mmc=setenv bootargs console=${console} root=${mmc_root}" \
	"init=${init} loglevel=${loglevel} partitions=${partitions}\0" \
	"boot_normal=sunxi_flash read 40007800 boot;boota 40007800\0" \
	"boot_recovery=sunxi_flash read 40007800 recovery;boota 40007800\0" \
	"boot_fastboot=fastboot\0"

#define CONFIG_SUNXI_SPRITE_ENV_SETTINGS	\
	"bootdelay=0\0" \
	"bootcmd=run sunxi_sprite_test\0" \
	"console=ttyS0,115200\0" \
	"sunxi_sprite_test=sprite_test read\0"

#define CONFIG_BOOTDELAY	1
#define CONFIG_BOOTCOMMAND	"nand read 50000000 boot;boota 50000000"
#define CONFIG_SYS_BOOT_GET_CMDLINE
#define CONFIG_AUTO_COMPLETE

#define HAVE_BLOCK_DEVICE

#define CONFIG_CMD_FAT			/* with this we can access bootfs in nand */
#define CONFIG_CMD_BOOTA		/* boot android image */
#define CONFIG_CMD_RUN			/* run a command */
#define CONFIG_CMD_BOOTD		/* boot the default command */

/* Configuaration of Network and net-driver */
#define CONFIG_CMD_NET
#define CONFIG_NET_MULTI
#define CONFIG_SUNXI_GETH

//#define CONFIG_CMD_NFS		/* NFS support                  */
#define CONFIG_CMD_DHCP                /* DHCP Support                 */
//#define CONFIG_CMD_MII		/* MII support                  */
#define CONFIG_ETHADDR         02:AC:BD:3F:29:E0       /* Ethernet hardware address    */
#define CONFIG_CMD_PING
#define CONFIG_HARD_CHECKSUM

#define CONFIG_IPADDR  192.168.0.23
#define CONFIG_SERVERIP        192.168.0.20
#define CONFIG_NETMASK 255.255.255.0
#define CONFIG_GATEWAYIP 192.168.0.1
#define CONFIG_BOOTFILE        "uImage"
#define CONFIG_LOADADDR        0x40008000

#define CONFIG_PWR_GPIO

#endif /* __CONFIG_H */
