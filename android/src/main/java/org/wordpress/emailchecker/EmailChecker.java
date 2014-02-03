package org.wordpress.emailchecker;

import android.util.Log;

public class EmailChecker {
    static boolean sInitialized;

    static {
        try {
            System.loadLibrary("gnustl_shared");
            System.loadLibrary("emailchecker");
            sInitialized = true;
        } catch (UnsatisfiedLinkError e) {
            Log.e("EmailChecker", "Unable to load native libraries, EmailChecker disabled");
        }
    }

    public String suggestDomainCorrection(String email) {
        if (sInitialized) {
            return suggestDomainCorrectionNative(email);
        }
        return email;
    }

    public native String suggestDomainCorrectionNative(String email);
}
