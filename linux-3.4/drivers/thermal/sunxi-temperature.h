#ifndef _SUNXI_TEMPERATURE_H
#define _SUNXI_TEMPERATURE_H

#define THERMAL_DATA_DELAY	(1000)

#ifdef CONFIG_ARCH_SUN8IW3P1
#define THERMAL_BASSADDRESS	(0xf1c25000)

#define THS_CTRL_REG0		(0x00)
#define THS_CTRL_REG1		(0x04)
#define THS_PRO_CTRL_REG	(0x18)

#define THS_CTRL_REG0_VALUE	(0x00a300ff)
#define THS_CTRL_REG1_VALUE	(0x120)
#define THS_PRO_CTRL_REG_VALUE	(0x1005f)

#define THS_DATA_REG		(0x20)

#define THS_IRQNO		(0)

#elif defined(CONFIG_ARCH_SUN8IW5P1)

#define THERMAL_BASSADDRESS	(0xf1c25000)

#define THS_CTRL_REG0		(0x00)
#define THS_CTRL_REG1		(0x04)
#define THS_PRO_CTRL_REG	(0x18)

#define THS_CTRL_REG0_VALUE	(0x002000ff)
#define THS_CTRL_REG1_VALUE	(0x100)
#define THS_PRO_CTRL_REG_VALUE	(0x1005f)

#define THS_DATA_REG		(0x20)
#define TEMP_CATA		(0x40)

#define THS_IRQNO		(0)

#elif defined(CONFIG_ARCH_SUN9IW1P1)

#define THERMAL_BASSADDRESS	(0xf6004C00)

#define ADC_CTRL0_REG		(0x00)
#define ADC_CTRL1_REG		(0x04)
#define ADC_INT_CTRL_REG	(0x08)
#define ADC_INT_STA_REG		(0x0C)
#define ADC_DATA_REG		(0x10)
#define ADC_CO_DATA_REG		(0x14)
#define ADC_IO_CFG_REG		(0x18)
#define ADC_IO_DATA_REG		(0x20)

#define ADC_CTRL0_VALUE		(0x73fff)
#define ADC_CTRL1_VALUE		(0x1000f)
#define ADC_INT_CTRL_VALUE	(0x30f80)
#define ADC_IO_CFG_VALUE	(0x2222)

#define THS_CTRL_REG		(0x40)
#define THS_INT_CTRL_REG	(0x44)
#define THS_INT_STA_REG		(0x48)
#define THS_INT_ALM_TH_REG0	(0x50)
#define THS_INT_ALM_TH_REG1	(0x54)
#define THS_INT_ALM_TH_REG2	(0x58)
#define THS_INT_ALM_TH_REG3	(0x5C)
#define THS_INT_SHUT_TH_REG0	(0x60)
#define THS_INT_SHUT_TH_REG1	(0x64)
#define THS_INT_SHUT_TH_REG2	(0x68)
#define THS_INT_SHUT_TH_REG3	(0x6C)
#define THS_FILT_CTRL_REG	(0x70)
#define THS_0_1_CDAT_REG	(0x74)
#define THS_2_3_CDAT_REG	(0x78)
#define THS_DATA_REG0		(0x80)
#define THS_DATA_REG1		(0x84)
#define THS_DATA_REG2		(0x88)
#define THS_DATA_REG3		(0x8C)
#define THS_INT_ALM_TH_VALUE0	(0x50)
#define THS_INT_ALM_TH_VALUE1	(0x54)
#define THS_INT_ALM_TH_VALUE2	(0x58)
#define THS_INT_ALM_TH_VALUE3	(0x5C)
#define THS_INT_SHUT_TH_VALUE0	(0x60)
#define THS_INT_SHUT_TH_VALUE1	(0x64)
#define THS_INT_SHUT_TH_VALUE2	(0x68)
#define THS_INT_SHUT_TH_VALUE3	(0x6C)

#define THS_CTRL_VALUE		(0x002f000f)
#define THS_INT_CTRL_VALUE	(0x10ff)
#define THS_CLEAR_INT_STA	(0xfff)
#define THS_FILT_CTRL_VALUE	(0x05)

#define THS_INTS_DATA0		(0x100)
#define THS_INTS_DATA1		(0x200)
#define THS_INTS_DATA2		(0x400)
#define THS_INTS_DATA3		(0x800)
#define THS_INTS_SHT0		(0x010)
#define THS_INTS_SHT1		(0x020)
#define THS_INTS_SHT2		(0x040)
#define THS_INTS_SHT3		(0x080)
#define THS_INTS_ALARM0		(0x001)
#define THS_INTS_ALARM1		(0x002)
#define THS_INTS_ALARM2		(0x004)
#define THS_INTS_ALARM3		(0x008)

#define THS_IRQNO		(147)

#elif defined(CONFIG_ARCH_SUN8IW6P1) || defined(CONFIG_ARCH_SUN8IW9P1)
#ifdef CONFIG_ARCH_SUN8IW6P1
#define THERMAL_BASSADDRESS	(0xf1f04000)
#define TEM_MUL                   (14186)
#define TEM_MIN                   (2719)
#define REG_DIV                   (14186)
#define REG_MIN                   (192)
#else
#define THERMAL_BASSADDRESS	(0xf1c25000)
#define TEM_MUL                   (9122)
#define TEM_MIN                   (2215)
#define REG_DIV                   (9122)
#define REG_MIN                   (243)
#endif

#define THS_CTRL0_REG		(0x00)
#define THS_CTRL1_REG		(0x04)
#define ADC_CDAT_REG		(0x14)
#define THS_CTRL2_REG		(0x40)
#define THS_INT_CTRL_REG	(0x44)
#define THS_INT_STA_REG		(0x48)
#define THS_INT_ALM_TH_REG0	(0x50)
#define THS_INT_ALM_TH_REG1	(0x54)
#define THS_INT_ALM_TH_REG2	(0x58)
#define THS_INT_SHUT_TH_REG0	(0x60)
#define THS_INT_SHUT_TH_REG1	(0x64)
#define THS_INT_SHUT_TH_REG2	(0x68)
#define THS_FILT_CTRL_REG	(0x70)
#define THS_0_1_CDATA_REG	(0x74)
#define THS_2_CDATA_REG		(0x78)
#define THS_DATA_REG0		(0x80)
#define THS_DATA_REG1		(0x84)
#define THS_DATA_REG2		(0x88)

#define THS_INT_ALM_TH_VALUE0	(0x50)
#define THS_INT_ALM_TH_VALUE1	(0x54)
#define THS_INT_ALM_TH_VALUE2	(0x58)
#define THS_INT_SHUT_TH_VALUE0	(0x60)
#define THS_INT_SHUT_TH_VALUE1	(0x64)
#define THS_INT_SHUT_TH_VALUE2	(0x68)

#define THS_CTRL0_VALUE		(0x17)
#define THS_CTRL1_VALUE		(0x1<<17)
#define THS_CTRL2_VALUE		(0x00170007)
#define THS_INT_CTRL_VALUE	(0x1070)//gai
#define THS_CLEAR_INT_STA	(0x777)
#define THS_FILT_CTRL_VALUE	(0x05)

#define THS_INTS_DATA0		(0x100)
#define THS_INTS_DATA1		(0x200)
#define THS_INTS_DATA2		(0x400)
#define THS_INTS_SHT0		(0x010)
#define THS_INTS_SHT1		(0x020)
#define THS_INTS_SHT2		(0x040)
#define THS_INTS_ALARM0		(0x001)
#define THS_INTS_ALARM1		(0x002)
#define THS_INTS_ALARM2		(0x004)

#define THS_IRQNO		(73)

#elif defined(CONFIG_ARCH_SUN8IW7P1)

#define THERMAL_BASSADDRESS	(0xf1c25000)

#define THS_CTRL0_REG		(0x00)
#define THS_CTRL1_REG		(0x04)
#define ADC_CDAT_REG		(0x14)
#define THS_CTRL2_REG		(0x40)
#define THS_INT_CTRL_REG	(0x44)
#define THS_INT_STA_REG		(0x48)
#define THS_INT_ALM_TH_REG	(0x50)
#define THS_INT_SHUT_TH_REG	(0x60)
#define THS_FILT_CTRL_REG	(0x70)
#define THS_CDATA_REG		(0x74)
#define THS_DATA_REG		(0x80)

#define THS_INT_ALM_TH_VALUE	(0x50)
#define THS_INT_SHUT_TH_VALUE	(0x60)

#define THS_CTRL0_VALUE		(0x3f)
#define THS_CTRL1_VALUE		(0x1<<17)
#define THS_CTRL2_VALUE		(0x003f0001)
#define THS_INT_CTRL_VALUE	(0x39010)///gai
#define THS_CLEAR_INT_STA	(0x1111)
#define THS_FILT_CTRL_VALUE	(0x06)

#define THS_INTS_DATA0		(0x100)
#define THS_INTS_SHT0		(0x010)
#define THS_INTS_ALARM0		(0x001)

#define THS_IRQNO		(63)

#endif

enum {
	DEBUG_INIT = 1U << 0,
	DEBUG_CONTROL_INFO = 1U << 1,
	DEBUG_DATA_INFO = 1U << 2,
	DEBUG_SUSPEND = 1U << 3,
};

extern int ths_read_data(int value);

#endif /* _SUNXI_TEMPERATURE_H */
