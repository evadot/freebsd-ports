--- src/3rdparty/chromium/components/supervised_user/core/common/features.h.orig	2024-10-22 08:31:56 UTC
+++ src/3rdparty/chromium/components/supervised_user/core/common/features.h
@@ -25,7 +25,7 @@ BASE_DECLARE_FEATURE(
 // Applies new informative strings during the parental extension approval flow.
 BASE_DECLARE_FEATURE(kUpdatedSupervisedUserExtensionApprovalStrings);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kEnableExtensionsPermissionsForSupervisedUsersOnDesktop);
 #endif
 
@@ -59,11 +59,11 @@ BASE_DECLARE_FEATURE(kSupervisedUserProfileSigninIPH);
 
 // Displays a Family Link kite badge on the supervised user avatar in various
 // surfaces.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kShowKiteForSupervisedUsers);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // This hides the following guest mode entry points for supervised users:
 //
 // * In the Profile menu for supervised profiles
@@ -75,7 +75,7 @@ BASE_DECLARE_FEATURE(kHideGuestModeForSupervisedUsers)
 // unauthenticated (e.g. signed out of the content area) account.
 BASE_DECLARE_FEATURE(kForceSafeSearchForUnauthenticatedSupervisedUsers);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Force re-authentication when an unauthenticated supervised user tries to
 // access YouTube, so that content restrictions can be applied.
 BASE_DECLARE_FEATURE(kForceSupervisedUserReauthenticationForYouTube);
