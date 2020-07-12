// ILedAidlInterface.aidl
package com.example.ledservice;

interface ILedAidlInterface {
    /**
     * @brief Swith the state of the given Led on Hikey960 board
     * @param ledId .. Id of the Led to be switched
     */
    void ledSwitch(int ledId);
}
