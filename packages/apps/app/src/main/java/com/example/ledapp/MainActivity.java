package com.example.ledapp;

import android.content.ComponentName;
import android.content.ServiceConnection;
import android.os.IBinder;
import android.os.RemoteException;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;

import com.example.ledservice.ILedAidlInterface;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private static final String LOG_TAG = "LED_CONTROL_APPLICATION: ";
    private ILedAidlInterface mService;

    private ServiceConnection mConnection = new ServiceConnection() {
        @Override
        public void onServiceConnected(ComponentName name, IBinder service) {
            if (service != null) {
                mService = ILedAidlInterface.Stub.asInterface(service);
            } else {
                Log.e(LOG_TAG, "Null pointer exception");
            }
        }

        @Override
        public void onServiceDisconnected(ComponentName name) {

        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final Button led1 = (Button)findViewById(R.id.led1);
        final Button led2 = (Button)findViewById(R.id.led2);
        final Button led3 = (Button)findViewById(R.id.led3);
        final Button led4 = (Button)findViewById(R.id.led4);

        led1.setOnClickListener(this);
        led2.setOnClickListener(this);
        led3.setOnClickListener(this);
        led4.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.led1:
                try {
                    mService.ledSwitch(0);
                } catch (RemoteException e) {
                    Log.e(LOG_TAG, "Cannot switch the Led 1");
                }
                break;
            case R.id.led2:
                try {
                    mService.ledSwitch(1);
                } catch (RemoteException e) {
                    Log.e(LOG_TAG, "Cannot switch the Led 2");
                }
                break;
            case R.id.led3:
                try {
                    mService.ledSwitch(2);
                } catch (RemoteException e) {
                    Log.e(LOG_TAG, "Cannot switch the Led 3");
                }
                break;
            case R.id.led4:
                try {
                    mService.ledSwitch(3);
                } catch (RemoteException e) {
                    Log.e(LOG_TAG, "Cannot switch the Led 4");
                }
                break;
        }
    }

    @Override
    protected void onDestroy () {
        super.onDestroy();
        unbindService(mConnection);
    }
}
