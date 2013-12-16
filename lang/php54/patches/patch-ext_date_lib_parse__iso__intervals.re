$NetBSD: patch-ext_date_lib_parse__iso__intervals.re,v 1.1.2.2 2013/12/16 17:05:48 tron Exp $

Fix for CVE-2013-6712.

--- ext/date/lib/parse_iso_intervals.re.orig	2013-11-13 06:46:59.000000000 +0000
+++ ext/date/lib/parse_iso_intervals.re
@@ -383,7 +383,7 @@ isoweek          = year4 "-"? "W" weekof
 					break;
 			}
 			ptr++;
-		} while (*ptr);
+		} while (!s->errors->error_count && *ptr);
 		s->have_period = 1;
 		TIMELIB_DEINIT;
 		return TIMELIB_PERIOD;
