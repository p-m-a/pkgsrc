$NetBSD: patch-src_gd__bmp.c,v 1.2.2.2 2013/12/20 08:45:44 spz Exp $

Don't use ceill(); it isn't remotely needed here (it is probably a
typo) and causes build failure on platforms where it isn't available.
See PR 48334.

upstream report:
https://bitbucket.org/libgd/gd-libgd/issue/98/gd_bmpc-use-of-both-ceil-and-ceill

--- src/gd_bmp.c~	2013-06-25 09:58:23.000000000 +0000
+++ src/gd_bmp.c
@@ -792,7 +792,7 @@ static int bmp_read_1bit(gdImagePtr im, 
 	}
 
 	/* The line must be divisible by 4, else its padded with NULLs */
-	padding = ((int)ceill(0.1 * info->width)) % 4;
+	padding = ((int)ceil(0.1 * info->width)) % 4;
 	if (padding) {
 		padding = 4 - padding;
 	}
