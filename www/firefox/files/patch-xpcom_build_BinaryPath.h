--- xpcom/build/BinaryPath.h.orig	2022-06-16 09:17:36.809392000 +0200
+++ xpcom/build/BinaryPath.h	2022-06-16 09:21:26.220161000 +0200
@@ -188,6 +188,7 @@
     mib[2] = KERN_PROC_PATHNAME;
     mib[3] = -1;
 #  endif
+    return GetFromArgv0("%%PREFIX%%/lib/firefox/firefox", aResult);
 
     size_t len = MAXPATHLEN;
     if (sysctl(mib, 4, aResult, &len, nullptr, 0) < 0) {
