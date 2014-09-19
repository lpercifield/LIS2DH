/** Based on ST MicroElectronics LIS2DH datasheet http://www.st.com/web/en/resource/technical/document/datasheet/DM00042751.pdf
* 18/06/2014 by Conor Forde <me@conorforde.com>
* Updates should be available at https://github.com/Snowda/LIS2DH
*
* Changelog:
*     ... - ongoing development release

* NOTE: THIS IS ONLY A PARIAL RELEASE. 
* THIS DEVICE CLASS IS CURRENTLY UNDERGOING ACTIVE DEVELOPMENT AND IS MISSING MOST FEATURES. 
* PLEASE KEEP THIS IN MIND IF YOU DECIDE TO USE THIS PARTICULAR CODE FOR ANYTHING.
*/

#ifndef _LIS2DH_H_
#define _LIS2DH_H_

//Registers
#define LIS2DH_STATUS_REG_AUX 	0x07
#define LIS2DH_OUT_TEMP_L 		0x0C
#define LIS2DH_OUT_TEMP_H 		0x0D
#define LIS2DH_INT_COUNTER_REG 	0x0E
#define LIS2DH_WHO_AM_I 		0x0F
#define LIS2DH_TEMP_CFG_REG 	0x1F
#define LIS2DH_CTRL_REG1 		0x20
#define LIS2DH_CTRL_REG2 		0x21
#define LIS2DH_CTRL_REG3 		0x22
#define LIS2DH_CTRL_REG4 		0x23
#define LIS2DH_CTRL_REG5 		0x24
#define LIS2DH_CTRL_REG6 		0x25
#define LIS2DH_REFERENCE 		0x26
#define LIS2DH_STATUS_REG2 		0x27
#define LIS2DH_OUT_X_L 			0x28
#define LIS2DH_OUT_X_H 			0x29
#define LIS2DH_OUT_Y_L 			0x2A
#define LIS2DH_OUT_Y_H 			0x2B
#define LIS2DH_OUT_Z_L 			0x2C
#define LIS2DH_OUT_Z_H 			0x2D
#define LIS2DH_FIFO_CTRL_REG 	0x2E
#define LIS2DH_FIFO_SRC_REG 	0x2F
#define LIS2DH_INT1_CFG 		0x30
#define LIS2DH_INT1_SOURCE 		0x31
#define LIS2DH_INT1_THS 		0x32
#define LIS2DH_INT1_DURATION 	0x33
#define LIS2DH_INT_CFG 			0x34
#define LIS2DH_INT2_SOURCE 		0x35
#define LIS2DH_INT2_THS 		0x36
#define LIS2DH_INT2_DURATION 	0x37
#define LIS2DH_CLICK_CFG 		0x38
#define LIS2DH_CLICK_SRC 		0x39
#define LIS2DH_CLICK_THS 		0x3A
#define LIS2DH_TIME_LIMIT 		0x3B
#define LIS2DH_TIME_LATENCY 	0x3C
#define LIS2DH_TIME_WINDOW 		0x3D
#define LIS2DH_ACT_THS 			0x3E
#define LIS2DH_ACT_DUR 			0x3F

//Register Masks

#define LIS2DH_ 0x