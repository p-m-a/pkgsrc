# $NetBSD: Makefile,v 1.10 2013/06/04 22:15:43 tron Exp $
#

.include "../../multimedia/xine-lib/Makefile.common"

PKGNAME=	${XINE_PKGNAME:S/lib/alsa/}
PKGREVISION=	3
CATEGORIES=	audio
COMMENT=	The ALSA output plugin for xine-lib

DEPENDS+=	xine-lib>=1rc3a:../../multimedia/xine-lib

BUILD_DIRS=	src/audio_out
CONFIGURE_ARGS+=	--without-x --disable-xinerama
CONFIGURE_ARGS+=	--disable-vcd
CONFIGURE_ARGS+=	--with-alsa

INSTALLATION_DIRS=	lib/xine/plugins/${XINE_MOD_DIR_VER}

do-install:
	cd ${WRKSRC}/src/audio_out && \
		${LIBTOOL} --mode=install ${INSTALL_DATA} \
		xineplug_ao_out_alsa.la \
		${DESTDIR}${PREFIX}/lib/xine/plugins/${XINE_MOD_DIR_VER}

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
