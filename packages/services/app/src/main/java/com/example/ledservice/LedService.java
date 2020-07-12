package com.example.ledservice;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.os.RemoteException;
import android.util.Log;

import vendor.gl.hardware.ledcontrol.V1_0.ILedControl;

public class LedService extends Service {
    private static final String LOG_TAG = "LED_CONTROL_SERVICE: ";
    private ILedControl ledControl;

    public LedService() {
    }

    ILedAidlInterface.Stub mService = new ILedAidlInterface.Stub() {
        @Override
        public void ledSwitch(int ledId) throws RemoteException {
            Log.d(LOG_TAG, String.format("Trying to switch %d led)", ledId));

            try {
                Integer ledInt = new Integer(ledId);
                byte ledByte = ledInt.byteValue();
                int result = ledControl.ledSwitchState(ledByte);
                Log.d(LOG_TAG, String.format("Led %d was switched its state to %d", ledId, result));
            } catch (Exception e) {
                Log.e(LOG_TAG, "call Led service failed");
            }
        }
    };

    @Override
    public IBinder onBind(Intent intent) {
        Log.d(LOG_TAG, "Failed to call ILedControl HAL");
        return mService;
    }

    @Override
    public void onCreate() {
        try {
            ledControl = ILedControl.getService(true);
        } catch (Exception e) {
            Log.e(LOG_TAG, "Failed to call ILedControl HAL");
        }
    }
}
