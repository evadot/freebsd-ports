--- src/3rdparty/chromium/base/posix/file_descriptor_shuffle.h.orig	2024-10-22 08:31:56 UTC
+++ src/3rdparty/chromium/base/posix/file_descriptor_shuffle.h
@@ -26,6 +26,8 @@
 #include "base/base_export.h"
 #include "base/compiler_specific.h"
 
+#undef close
+
 namespace base {
 
 // A Delegate which performs the actions required to perform an injective
