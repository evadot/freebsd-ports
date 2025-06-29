--- src/3rdparty/chromium/chrome/browser/ui/webui/certificate_manager/certificate_manager_handler.cc.orig	2024-10-22 08:31:56 UTC
+++ src/3rdparty/chromium/chrome/browser/ui/webui/certificate_manager/certificate_manager_handler.cc
@@ -154,7 +154,7 @@ CertificateManagerPageHandler::GetCertSource(
             "distrusted_certs",
             cert_verifier::mojom::CertificateTrust::kDistrusted);
         break;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       case certificate_manager_v2::mojom::CertificateSource::
           kProvisionedClientCert:
         source_ptr = CreateProvisionedClientCertSource(profile_);
