# $NetBSD: Makefile,v 1.40 2014/02/12 23:18:03 tron Exp $
#

DISTNAME=	zphoto-1.2
PKGREVISION=	32
CATEGORIES=	graphics
MASTER_SITES=	http://0xcc.net/zphoto/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://0xcc.net/zphoto/
COMMENT=	Flash-based photo album generator
LICENSE=	gnu-lgpl-v2.1

.include "options.mk"

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.libiconv:Q}
CONFIGURE_ARGS+=	--with-libintl-prefix=${BUILDLINK_PREFIX.gettext-lib:Q}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../multimedia/ming/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
