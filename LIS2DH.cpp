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

#include "LIS2DH.h"

LIS2DH::LIS2DH() {
    _address = MPU9250_DEFAULT_ADDRESS;
}


LIS2DH::LIS2DH(uint8_t address) {
    _address = address;
}

bool LIS2DH::writeRegister(const uint8_t register_addr, const uint8_t value) {
    //send write call to sensor address
    //send register address to sensor
    //send value to register
    bool write status = 0;
    return write_status; //returns whether the write succeeded or failed
}

bool MPU9250::writeRegisters(const uint8_t msb_register, const uint8_t msb_value, const uint8_t lsb_register, const uint8_t lsb_value) { 
    //send write call to sensor address
    //send register address to sensor
    //send value to register
    bool msb_bool, lsb_bool;
    msb_bool = writeRegister(msb_register, msb_value);
    lsb_bool = writeRegister(lsb_register, lsb_value);
    return msb_bool | lsb_bool; //returns whether the write succeeded or failed
}

bool MPU9250::writeMaskedRegister(const uint8_t register_addr, const uint8_t mask, const uint8_t value) {
    masked_value = (mask & value); //there has to be an easier way to do this.... I know, I know, shut up, I know it's that, I'll get around to it when I can ok?
    return writeRegister(register_addr, masked_value);
    //every reference to this is wrong (also)!! fix them!
}

uint8_t MPU9250::readRegister(const uint8_t register_addr) {
    //call sensor by address
    //call registers
    uint8_t data =0;
    return data; //return the data returned from the register
}

uint16_t MPU9250::readRegisters(const uint8_t msb_register, const uint8_t lsb_register) {
    uint8_t msb = readRegister(msb_register);
    uint8_t lsb = readRegister(lsb_register);
    return (((int16_t)msb) << 8) | lsb;

}

uint8_t MPU9250::readMaskedRegister(const uint8_t register_addr, const uint8_t mask) {
    uint8_t data = readRegister(register_addr);
    return (data & mask);

    //every reference to this is wrong!!! fix them
}

int16_t LIS2DH::getAxisX(void) {
	return readRegisters(LIS2DH_OUT_X_H, LIS2DH_OUT_X_L);
}

int16_t LIS2DH::getAxisY(void) {
	return readRegisters(LIS2DH_OUT_Y_H, LIS2DH_OUT_Y_L);
}

int16_t LIS2DH::getAxisZ(void) {
	return readRegisters(LIS2DH_OUT_Z_H, LIS2DH_OUT_Z_L);
}

bool LIS2DH::tempHasOverrun(void) {
    return (readMaskedRegister(LIS2DH_STATUS_REG_AUX, LIS2DH_TOR_MASK) != 0);
}

bool LIS2DH::tempDataAvailable(void) {
    return (readMaskedRegister(LIS2DH_STATUS_REG_AUX, LIS2DH_TDA_MASK) != 0);
}

uint16_t LIS2DH::getTemperature(void) {
    if(tempDataAvailable()){
        return readRegisters(LIS2DH_OUT_TEMP_H, LIS2DH_OUT_TEMP_L);
    } else {
        //if new data isn't available
        return 0;
    }
}

bool LIS2DH::whoAmI() {
    return (LIS2DH_I_AM_MASK == readRegister(LIS2DH_WHO_AM_I));
}

bool LIS2DH::getTempEnabled(void) {
    return (readMaskedRegister(LIS2DH_TEMP_CFG_REG, LIS2DH_TEMP_EN_MASK) != 0);
}

bool LIS2DH::setTempEnabled(bool enable) {
    return writeRegister(LIS2DH_TEMP_CFG_REG, enable ? LIS2DH_TEMP_EN_MASK : 0);
}

uint8_t LIS2DH::getDataRate(void) {
    return readMaskedRegister(LIS2DH_CTRL_REG1, LIS2DH_ODR_MASK);
}

bool LIS2DH::setDataRate(uint8_t rate) {
    if(rate > 9) {
        return 0;
    }
    return writeMaskedRegister(LIS2DH_CTRL_REG1, LIS2DH_ODR_MASK, rate << 4);
}


bool LIS2DH::enableLowPower(void) {
    return writeMaskedRegister(LIS2DH_CTRL_REG1, LIS2DH_LPEN_MASK, true);
}


bool LIS2DH::disableLowPower(void) {
    return writeMaskedRegister(LIS2DH_CTRL_REG1, LIS2DH_LPEN_MASK, false);
}


bool LIS2DH::isLowPowerEnabled(void) {
    return (readMaskedRegister(LIS2DH_CTRL_REG1, LIS2DH_LPEN_MASK) != 0);
}

bool LIS2DH::enableAxisX(void) {
    return writeMaskedRegister(LIS2DH_CTRL_REG1, LIS2DH_X_EN_MASK, true);
}

bool LIS2DH::disableAxisX(void) {
    return writeMaskedRegister(LIS2DH_CTRL_REG1, LIS2DH_X_EN_MASK, false);
}

bool LIS2DH::isXAxisEnabled(void) {
    return (readMaskedRegister(LIS2DH_CTRL_REG1, LIS2DH_X_EN_MASK) != 0);
}

bool LIS2DH::EnableAxisY(void) {
    return writeMaskedRegister(LIS2DH_CTRL_REG1, LIS2DH_Y_EN_MASK, true);
}

bool LIS2DH::disableAxisY(void) {
    return writeMaskedRegister(LIS2DH_CTRL_REG1, LIS2DH_Y_EN_MASK, false);
}

bool LIS2DH::isYAxisEnabled(void) {
    return (readMaskedRegister(LIS2DH_CTRL_REG1, LIS2DH_Y_EN_MASK) != 0);
}

bool LIS2DH::EnableAxisZ(void) {
    return writeMaskedRegister(LIS2DH_CTRL_REG1, LIS2DH_Z_EN_MASK, true);
}

bool LIS2DH::disableAxisZ(void) {
    return writeMaskedRegister(LIS2DH_CTRL_REG1, LIS2DH_Z_EN_MASK, false);
}

bool LIS2DH::isZAxisEnabled(void) {
    return (readMaskedRegister(LIS2DH_CTRL_REG1, LIS2DH_Z_EN_MASK) != 0);
}

bool LIS2DH::() {
    return 0;
}

bool LIS2DH::() {
    return 0;
}