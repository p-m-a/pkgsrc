# $NetBSD: Makefile,v 1.14 2013/04/06 03:59:24 rodent Exp $

DISTNAME=		#
PKGNAME=		cnprint-3.30b
PKGREVISION=		1
CATEGORIES=		print
MASTER_SITES=		http://nba184.med.uth.tmc.edu:3006/~cai/software/cnp/ \
			http://nba184.med.uth.tmc.edu:3006/~cai/software/cnp/metrics/ \
			http://nba184.med.uth.tmc.edu:3006/~cai/software/cnp/fonts/ \
			ftp://ftp.csc.cuhk.edu.hk/pub/chinese/ifcss/software/fonts/misc/
EXTRACT_SUFX=		#empty
DISTFILES+=		cnprint330b.c \
			cnprint330b.readme \
			ttfb330b.c \
			cnprint330b.hlp \
			cnprint33.cmd \
			helvet.dat  \
			mssong.ttf.gz mssong.htf \
			mshei.ttf.gz mshei.htf \
			cc48s.hbf cc48.sym.gz \
			cc48s.1.gz \
			cc48s.2.gz \
			hbf.tar.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.neurophys.wisc.edu/~cai/software/index.html
COMMENT=		Print & convert CJK style text to PostScript

DIST_SUBDIR=		${PKGNAME_NOREV}
USE_TOOLS+=		tar gunzip gzcat
INSTALLATION_DIRS=	bin share/cnprint

do-extract:
	${MKDIR} ${WRKSRC}
.for i in ${DISTFILES}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${i} ${WRKSRC}
.endfor
	cd ${WRKSRC} && (${GZCAT} hbf.tar.gz || ${TRUE}) | ${TAR} xf -
	${MV} ${WRKSRC}/hbf/* ${WRKSRC}/
	${RM} -fr ${WRKSRC}/hbf
	${GUNZIP_CMD} ${WRKSRC}/*.gz || ${TRUE}

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} cnprint330b.c ttfb330b.c -o cnprint -DPREFIX=\"${PREFIX}\" && \
	${SED} \
		-e 's/\(DEFAULT_JIS_FONT\):.*$$/\1: kanji48.hbf/' \
		>cnprint.cmd <cnprint33.cmd

do-install:
	${INSTALL_DATA} ${WRKSRC}/cnprint.cmd ${DESTDIR}${PREFIX}/share/cnprint
	${INSTALL_DATA} ${WRKSRC}/*.sym ${DESTDIR}${PREFIX}/share/cnprint
	${INSTALL_DATA} ${WRKSRC}/*.htf ${DESTDIR}${PREFIX}/share/cnprint
	${INSTALL_DATA} ${WRKSRC}/*.hbf ${DESTDIR}${PREFIX}/share/cnprint
	${INSTALL_DATA} ${WRKSRC}/*.bin ${DESTDIR}${PREFIX}/share/cnprint
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DESTDIR}${PREFIX}/share/cnprint
	${INSTALL_PROGRAM} ${WRKSRC}/cnprint ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
