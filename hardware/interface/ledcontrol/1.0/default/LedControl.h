/**
 * @file LedControl.h
 */

#ifndef LEDCONTROL_V1_0_LEDCONTROL_H_
#define LEDCONTROL_V1_0_LEDCONTROL_H_

#include <string>
#include <vector>

#include <vendor/gl/hardware/ledcontrol/1.0/ILedControl.h>

namespace vendor {
namespace gl {
namespace hardware {
namespace ledcontrol {
namespace V1_0 {
namespace implementation {

using ::android::hardware::Return;

class LedControl : public ILedControl {

public:
    LedControl();
    ~LedControl();

    Return<ledcontrol::V1_0::LedState> ledSwitchState(ledcontrol::V1_0::Led led) override;

private:
    const std::string ledSystemName = "user_led";
    const std::string ledSystemPath = "/sys/class/leds/";
    const std::string ledSystemCmd  = "/trigger";
    std::vector<std::string> ledNames;
    std::vector<int> ledStates;
    
};

} // namespace implementation
} // namespace V1_0
} // namespace ledcontrol
} // namespace hardware
} // namespace gl
} // namespace vendor

#endif /* LEDCONTROL_V1_0_LEDCONTROL_H_ */
