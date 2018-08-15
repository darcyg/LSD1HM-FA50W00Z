#ifndef	_LINUX_AXP_SPLY_H_
#define	_LINUX_AXP_SPLY_H_

static struct input_dev *powerkeydev;

/*      AXP259      */
#define AXP259_CHARGE_STATUS		AXP259_STATUS
#define AXP259_IN_CHARGE			(1 << 5)
#define AXP259_STATUS_BATEN		(1 << 4)
#define AXP259_STATUS_ACEN			(1 << 0)
#define AXP259_STATUS_BATINACT		(1 << 3)
#define AXP259_STATUS_ICTEMOV		(1 << 7)

#define AXP259_PDBC			(0x32)
#define AXP259_CHARGE_CONTROL1		AXP259_CHARGE1
#define AXP259_CHARGER_ENABLE		(1 << 7)
#define AXP259_CHARGE_CONTROL2		AXP259_CHARGE2
#define AXP259_CHARGE_VBUS		AXP259_IPS_SET
#define AXP259_CAP			(0xB9)
#define AXP259_BATCAP0			(0xe0)
#define AXP259_BATCAP1			(0xe1)
#define AXP259_RDC0			(0xba)
#define AXP259_RDC1			(0xbb)
#define AXP259_VLTF_CHARGE  (0x38)
#define AXP259_VHTF_CHARGE  (0x39)
#define AXP259_VLTF_WORK    (0x3C)
#define AXP259_VHTF_WORK    (0x3D)
#define AXP259_ADJUST_PARA		(0xe8)
#define AXP259_FAULT_LOG1		AXP259_MODE_CHGSTATUS
#define AXP259_FAULT_LOG_CHA_CUR_LOW	(1 << 2)
#define AXP259_FAULT_LOG_BATINACT	(1 << 3)
#define AXP259_FAULT_LOG_OVER_TEMP	(1 << 7)
#define AXP259_FAULT_LOG2		AXP259_INTSTS2
#define AXP259_FAULT_LOG_COLD		(1 << 0)
#define AXP259_FINISH_CHARGE		(1 << 2)
#define AXP259_COULOMB_CONTROL		AXP259_COULOMB_CTL
#define AXP259_COULOMB_ENABLE		(1 << 7)
#define AXP259_COULOMB_SUSPEND		(1 << 6)
#define AXP259_COULOMB_CLEAR		(1 << 5)

#define AXP259_ADC_CONTROL				AXP259_ADC_EN
#define AXP259_ADC_BATVOL_ENABLE			(1 << 7)
#define AXP259_ADC_BATCUR_ENABLE			(1 << 6)
#define AXP259_ADC_DCINVOL_ENABLE			(1 << 5)
#define AXP259_ADC_DCINCUR_ENABLE			(1 << 4)
#define AXP259_ADC_DIETMP_ENABLE		(1 << 3)
#define AXP259_ADC_TSVOL_ENABLE				(1 << 0)

#define AXP259_ADC_INTERTEM_ENABLE			(1 << 7)
#define AXP259_ADC_GPIO0_ENABLE				(1 << 3)
#define AXP259_ADC_GPIO1_ENABLE				(1 << 2)
#define AXP259_ADC_GPIO2_ENABLE				(1 << 1)
#define AXP259_ADC_GPIO3_ENABLE				(1 << 0)
#define AXP259_ADC_CONTROL3				(0x84)
#define AXP259_VBATH_RES					(0x78)
#define AXP259_VTS_RES					(0x58)
#define AXP259_VBATL_RES					(0x79)
#define AXP259_OCVBATH_RES				(0xBC)
#define AXP259_OCVBATL_RES				(0xBD)
#define AXP259_INTTEMP					(0x56)
#define AXP259_DATA_BUFFER0				AXP259_BUFFER1
#define AXP259_DATA_BUFFER1				AXP259_BUFFER2
#define AXP259_DATA_BUFFER2				AXP259_BUFFER3
#define AXP259_DATA_BUFFER3				AXP259_BUFFER4
#define AXP259_DATA_BUFFER4				AXP259_BUFFER5
#define AXP259_DATA_BUFFER5				AXP259_BUFFER6
#define AXP259_DATA_BUFFER6				AXP259_BUFFER7
#define AXP259_DATA_BUFFER7				AXP259_BUFFER8
#define AXP259_DATA_BUFFER8				AXP259_BUFFER9
#define AXP259_DATA_BUFFER9				AXP259_BUFFERA
#define AXP259_DATA_BUFFERA				AXP259_BUFFERB

static const uint64_t AXP259_NOTIFIER_ON = (AXP259_IRQ_ACIN | AXP259_IRQ_ACRE |
					AXP259_IRQ_BATIN | AXP259_IRQ_BATRE |
					AXP259_IRQ_CHAST | AXP259_IRQ_CHAOV |
					AXP259_IRQ_LOWN1 | AXP259_IRQ_LOWN2 |
					AXP259_IRQ_PEKRE | AXP259_IRQ_PEKFE);

#define AXP_CHG_ATTR(_name)					\
{								\
	.attr = { .name = #_name, .mode = 0644 },		\
	.show =  _name##_show,					\
	.store = _name##_store,					\
}

struct axp_adc_res {		/*struct change*/
	uint16_t vbat_res;
	uint16_t ocvbat_res;
	uint16_t ibat_res;
	uint16_t ichar_res;
	uint16_t idischar_res;
	uint16_t vac_res;
	uint16_t iac_res;
	uint16_t vusb_res;
	uint16_t iusb_res;
	uint16_t ts_res;
};

struct axp_charger {
	/*power supply sysfs */
	struct power_supply batt;
	struct power_supply ac;
	struct power_supply usb;
	struct power_supply bubatt;

	/*i2c device */
	struct device *master;

	/* adc */
	struct axp_adc_res *adc;
	unsigned int sample_time;

	/*monitor */
	struct delayed_work work;
	unsigned int interval;

	/*battery info */
	struct power_supply_info *battery_info;

	/*charger control */
	bool chgen;
	bool limit_on;
	unsigned int chgcur;
	unsigned int chgvol;
	unsigned int chgend;

	/*charger time */
	int chgpretime;
	int chgcsttime;

	/*external charger */
	bool chgexten;
	int chgextcur;

	/* charger status */
	bool bat_det;
	bool is_on;
	bool is_finish;
	bool ac_not_enough;
	bool ac_det;
	bool usb_det;
	bool ac_valid;
	bool usb_valid;
	bool usb_adapter_valid;
	bool ext_valid;
	bool bat_current_direction;
	bool in_short;
	bool batery_active;
	bool low_charge_current;
	bool int_over_temp;
	uint8_t fault;
	int charge_on;

	int vbat;
	int ibat;
	int pbat;
	int vac;
	int iac;
	int vusb;
	int iusb;
	int ocv;

	int disvbat;
	int disibat;

	/*rest time */
	int rest_vol;
	int ocv_rest_vol;
	int base_restvol;
	int rest_time;

	/*ic temperature */
	int ic_temp;
	int bat_temp;

	/*irq */
	struct notifier_block nb;

	/* platform callbacks for battery low and critical events */
	void (*battery_low) (void);
	void (*battery_critical) (void);

	/* timer for report ac/usb type */
	struct timer_list usb_status_timer;

	struct dentry *debug_file;
};

static struct task_struct *main_task;
static struct axp_charger *axp_charger;
static int Total_Cap;
static int flag_state_change;
static int Bat_Cap_Buffer[AXP259_VOL_MAX];

#endif
