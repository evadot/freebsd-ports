--- etc/report.pl.orig	2020-09-23 14:55:01 UTC
+++ etc/report.pl
@@ -30,7 +30,7 @@ $pass="rtgdefault";
 $onedaysec=60*60*24;
 
 # Default locations to find RTG configuration file
-@configs = ("rtg.conf", "/usr/local/rtg/etc/rtg.conf", "/etc/rtg.conf");
+@configs = ("rtg.conf", "%%PREFIX%%/etc/rtg/rtg.conf", "/usr/local/rtg/etc/rtg.conf", "/etc/rtg.conf");
 foreach $conf (@configs) {
   if (open CONF, "<$conf") {
     print "Reading [$conf].\n" if $DEBUG;
