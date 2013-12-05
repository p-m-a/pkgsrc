$NetBSD: patch-includes.h,v 1.1.4.1 2013/12/05 09:52:53 tron Exp $

Interix support

--- includes.h.orig	2013-03-22 01:51:09.000000000 +0000
+++ includes.h
@@ -126,6 +126,10 @@
 #ifdef HAVE_READPASSPHRASE_H
 # include <readpassphrase.h>
 #endif
+#ifdef HAVE_INTERIX
+# include <interix/env.h>
+# include <interix/security.h>
+#endif
 
 #ifdef HAVE_IA_H
 # include <ia.h>
