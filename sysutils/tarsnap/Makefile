# $NetBSD: Makefile,v 1.7 2014/02/26 18:20:29 wiedi Exp $
#

DISTNAME=	tarsnap-autoconf-1.0.33
PKGNAME=	${DISTNAME:S/-autoconf//}
CATEGORIES=	sysutils archivers security
MASTER_SITES=	https://www.tarsnap.com/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tarsnap.com/
COMMENT=	Secure online backup service
LICENSE=	tarsnap-license

GNU_CONFIGURE=		yes
INSTALL_MAKE_FLAGS=	sysconfdir=${PREFIX}/share/examples/tarsnap

CONF_FILES=	${PREFIX}/share/examples/tarsnap/tarsnap.conf.sample ${PKG_SYSCONFDIR}/tarsnap.conf

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
