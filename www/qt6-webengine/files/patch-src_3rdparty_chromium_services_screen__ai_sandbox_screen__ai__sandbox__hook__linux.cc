--- src/3rdparty/chromium/services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc.orig	2024-04-19 13:02:56 UTC
+++ src/3rdparty/chromium/services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc
@@ -53,6 +53,7 @@ bool ScreenAIPreSandboxHook(base::FilePath binary_path
     }
   }
 
+#if !BUILDFLAG(IS_BSD)
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
 
   std::vector<BrokerFilePermission> permissions{
@@ -75,6 +76,7 @@ bool ScreenAIPreSandboxHook(base::FilePath binary_path
                             sandbox::syscall_broker::COMMAND_OPEN}),
       permissions, options);
   instance->EngageNamespaceSandboxIfPossible();
+#endif
 
   return true;
 }
