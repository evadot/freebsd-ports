--- xpcom/build/BinaryPath.h.orig	2022-10-10 16:00:29 UTC
+++ xpcom/build/BinaryPath.h
@@ -20,6 +20,7 @@
 #if defined(__FreeBSD__) || defined(__DragonFly__) || \
     defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #  include <sys/sysctl.h>
+#  include <sys/stat.h>
 #endif
 #if defined(__OpenBSD__)
 #  include <sys/stat.h>
@@ -188,6 +189,9 @@ class BinaryPath {
     mib[2] = KERN_PROC_PATHNAME;
     mib[3] = -1;
 #  endif
+#ifdef __FreeBSD__
+    return GetFromArgv0("%%PREFIX%%lib/firefox/firefox", aResult);
+#endif
 
     size_t len = MAXPATHLEN;
     if (sysctl(mib, 4, aResult, &len, nullptr, 0) < 0) {
@@ -218,6 +222,11 @@ class BinaryPath {
     return GetFromArgv0(argv[0], aResult);
   }
 
+#else
+#  error Oops, you need platform-specific code here
+#endif
+
+#if defined(__FreeBSD__) || defined(__OpenBSD__)
   static nsresult GetFromArgv0(const char* aArgv0, char aResult[MAXPATHLEN]) {
     struct stat fileStat;
     // 1) use realpath() on argv[0], which works unless we're loaded from the
@@ -256,9 +265,6 @@ class BinaryPath {
     }
     return NS_ERROR_FAILURE;
   }
-
-#else
-#  error Oops, you need platform-specific code here
 #endif
 
  public:
