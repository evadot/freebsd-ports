bdrewery:
 - Refactor and simplify original commit.
 - Stop setting TERM=su without a term.

------------------------------------------------------------------------
r99055 | des | 2002-06-29 04:21:58 -0700 (Sat, 29 Jun 2002) | 6 lines
Changed paths:
   M /head/crypto/openssh/session.c

Make sure the environment variables set by setusercontext() are passed on
to the child process.

Reviewed by:    ache
Sponsored by:   DARPA, NAI Labs

--- session.c.orig	2021-04-15 20:55:25.000000000 -0700
+++ session.c	2021-04-27 13:11:13.515917000 -0700
@@ -942,7 +942,7 @@ read_etc_default_login(char ***env, u_int *envsize, ui
 }
 #endif /* HAVE_ETC_DEFAULT_LOGIN */
 
-#if defined(USE_PAM) || defined(HAVE_CYGWIN)
+#if defined(USE_PAM) || defined(HAVE_CYGWIN) || defined(HAVE_LOGIN_CAP)
 static void
 copy_environment_denylist(char **source, char ***env, u_int *envsize,
     const char *denylist)
@@ -1052,7 +1052,8 @@ do_setup_env(struct ssh *ssh, Session *s, const char *
 # endif /* HAVE_CYGWIN */
 #endif /* HAVE_LOGIN_CAP */
 
-	if (!options.use_pam) {
+	/* FreeBSD PAM doesn't set default "MAIL" */
+	if (1 || !options.use_pam) {
 		snprintf(buf, sizeof buf, "%.200s/%.50s",
 		    _PATH_MAILDIR, pw->pw_name);
 		child_set_env(&env, &envsize, "MAIL", buf);
@@ -1063,6 +1064,23 @@ do_setup_env(struct ssh *ssh, Session *s, const char *
 
 	if (getenv("TZ"))
 		child_set_env(&env, &envsize, "TZ", getenv("TZ"));
+#ifdef HAVE_LOGIN_CAP
+	/* Load environment from /etc/login.conf setenv directives. */
+	{
+		extern char **environ;
+		char **senv, **var;
+
+		senv = environ;
+		environ = xmalloc(sizeof(char *));
+		*environ = NULL;
+		(void) setusercontext(lc, pw, pw->pw_uid, LOGIN_SETENV);
+		copy_environment_denylist(environ, &env, &envsize, NULL);
+		for (var = environ; *var != NULL; ++var)
+			free(*var);
+		free(environ);
+		environ = senv;
+	}
+#endif
 	if (s->term)
 		child_set_env(&env, &envsize, "TERM", s->term);
 	if (s->display)
@@ -1281,7 +1299,7 @@ do_nologin(struct passwd *pw)
 #ifdef HAVE_LOGIN_CAP
 	if (login_getcapbool(lc, "ignorenologin", 0) || pw->pw_uid == 0)
 		return;
-	nl = login_getcapstr(lc, "nologin", def_nl, def_nl);
+	nl = (char*)login_getcapstr(lc, "nologin", def_nl, def_nl);
 #else
 	if (pw->pw_uid == 0)
 		return;
@@ -1365,7 +1383,7 @@ do_setusercontext(struct passwd *pw)
 	if (platform_privileged_uidswap()) {
 #ifdef HAVE_LOGIN_CAP
 		if (setusercontext(lc, pw, pw->pw_uid,
-		    (LOGIN_SETALL & ~(LOGIN_SETPATH|LOGIN_SETUSER))) < 0) {
+		    (LOGIN_SETALL & ~(LOGIN_SETENV|LOGIN_SETPATH|LOGIN_SETUSER))) < 0) {
 			perror("unable to set user context");
 			exit(1);
 		}
