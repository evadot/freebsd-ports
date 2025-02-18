--- include/renderdoc_app.h.orig	2025-02-18 08:24:43 UTC
+++ include/renderdoc_app.h
@@ -39,6 +39,8 @@
 #define RENDERDOC_CC
 #elif defined(__APPLE__)
 #define RENDERDOC_CC
+#elif defined(__FreeBSD__)
+#define RENDERDOC_CC
 #else
 #error "Unknown platform"
 #endif
