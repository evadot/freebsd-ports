--- src/3rdparty/chromium/content/shell/renderer/shell_content_renderer_client.cc.orig	2024-05-21 18:07:39 UTC
+++ src/3rdparty/chromium/content/shell/renderer/shell_content_renderer_client.cc
@@ -54,7 +54,7 @@
 #include "media/base/media_switches.h"
 #endif
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && \
     (defined(ARCH_CPU_X86_64) || defined(ARCH_CPU_ARM64))
 #define ENABLE_WEB_ASSEMBLY_TRAP_HANDLER_LINUX
 #include "base/debug/stack_trace.h"
