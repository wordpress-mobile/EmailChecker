package org.wordpress.emailchecker;

import android.util.Log;

public class EmailChecker {
    static boolean rInitialized;

    static {
        try {
            System.loadLibrary("gnustl_shared");
            System.loadLibrary("emailchecker");
            rInitialized = true;
        } catch (UnsatisfiedLinkError e) {
            Log.e("EmailChecker", "Unable to load native libraries, EmailChecker disabled");
        }
    }

    public String suggestDomainCorrection(String email) {
        if (rInitialized) {
            return suggestDomainCorrectionNative(email);
        }
        return email;
    }

    public native String suggestDomainCorrectionNative(String email);
}
