# $NetBSD: Makefile,v 1.33 2014/01/25 10:29:59 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-gdbm-0
PKGREVISION=	5
CATEGORIES=	databases python

MAINTAINER=	dolecek@ics.muni.cz
HOMEPAGE=	http://www.python.org/doc/lib/module-gdbm.html
COMMENT=	Python interface to gdbm - GNU database manager

EVAL_PREFIX+=	GDBMDIR=gdbm

USE_TOOLS+=	patch

.include "../../lang/python/pyversion.mk"
.if !empty(PYPKGPREFIX:Mpy3?)
GDBM_MODNAME=	_gdbm
.else
GDBM_MODNAME=	gdbm
.endif

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/${GDBM_MODNAME}module.c
PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

PY_SETUP_SUBST+= GDBMPREFIX=${GDBMDIR}
PY_SETUP_SUBST+= GDBM_MODNAME=${GDBM_MODNAME}
PLIST_SUBST+=	GDBM_MODNAME=${GDBM_MODNAME}
PYSETUPINSTALLARGS+=	--install-lib ${PREFIX}/${PYLIB}/lib-dynload

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	set -e;								\
	cd ${WRKSRC};							\
	for f in ${PATCHDIR}/patch-*; do				\
		${PATCH} --batch < "$$f" || ${TRUE};			\
	done

.include "../../databases/gdbm/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"
