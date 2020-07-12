/**
 * @file LedControl.cpp
 */

#define LOG_TAG "LedControl"

#include <fstream>
#include <vector>

#include <log/log.h>

#include <vendor/gl/hardware/ledcontrol/1.0/types.h>
#include "LedControl.h"

namespace vendor {
namespace gl {
namespace hardware {
namespace ledcontrol {
namespace V1_0 {
namespace implementation {

LedControl::LedControl() {
    ALOGD("->LedControl::LedControl()");

    for (int i = 0; i < int(Led::LED_QUANTITY); ++i)
    {
        const std::string ledNum = std::to_string(i + 1);
        ledStates.push_back(0);
        ledNames.push_back(ledSystemName + ledNum);
    }
}

Return<LedState> LedControl::ledSwitchState(Led led) {
    if (led >= Led::LED_QUANTITY) {
        ALOGE("Wrong Led ID %hhu", led);
        return LedState::LED_ERR;
    }

    unsigned int ledIdx = unsigned(led);

    const std::string filePath = ledSystemPath + ledNames.at(ledIdx) + ledSystemCmd;
    std::ofstream file(filePath);
    
    if (!file.is_open()) {
        ALOGE("Cannot open a file %s", filePath.c_str());
        return LedState::LED_ERR;
    }

    // Switch the state of the led
    ledStates.at(ledIdx) = !ledStates.at(ledIdx);
    file << int(ledStates.at(ledIdx));

    if (!file.good()) {
        ALOGE("Cannot write a file %s", filePath.c_str());
        return LedState::LED_ERR;
    }
    
    file.close();
    ALOGD("File was written %s ", filePath.c_str());
    return (ledStates.at(ledIdx) ? LedState::LED_ON : LedState::LED_OFF);
}

LedControl::~LedControl() {
    ALOGD("->LedControl::~LedControl()");
}

} // namespace implementation
} // namespace V1_0
} // namespace ledcontrol
} // namespace hardware
} // namespace gl
} // namespace vendor
