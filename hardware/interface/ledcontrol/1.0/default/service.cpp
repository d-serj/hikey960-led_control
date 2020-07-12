/**
 * @file service.cpp
 */

#define LOG_TAG "vendor.gl.hardware.ledcontrol@1.0-service"

#include <hidl/HidlSupport.h>
#include <hidl/HidlTransportSupport.h>

#include "LedControl.h"

using ::android::hardware::configureRpcThreadpool;
using ::vendor::gl::hardware::ledcontrol::V1_0::implementation::LedControl;
using ::vendor::gl::hardware::ledcontrol::V1_0::ILedControl;
using ::android::hardware::joinRpcThreadpool;
using ::android::OK;
using ::android::sp;

int main(int /* argc */, char* /* argv */ []) {
    sp<ILedControl> ledControl = new LedControl();
    configureRpcThreadpool(1, true /* will join */);
    
    if (ledControl->registerAsService() != OK) {
        ALOGE("Couldn't register LedControl 1.0 service.");
        return 1;
    }
    
    ALOGD("Service LedControl 1.0 created!");
    joinRpcThreadpool();
    
    ALOGE("Service LedControl 1.0 exited!");
    return 1;
}