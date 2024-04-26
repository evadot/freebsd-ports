PORTNAME=	mesa-demos
PORTVERSION=	8.5.0
CATEGORIES=	graphics
MASTER_SITES=	https://mesa.freedesktop.org/archive/demos/${PORTVERSION}/ \
		ftp://ftp.freedesktop.org/pub/mesa/demos/ #${PORTVERSION}/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	OpenGL demos distributed with Mesa
WWW=		https://www.mesa3d.org/

LICENSE=	MIT

LIB_DEPENDS=	libdrm.so:graphics/libdrm

CONFLICTS_INSTALL=	glx-utils

USES=		gl localbase meson pkgconfig tar:bzip2 xorg
USE_GL=		egl gbm gl glesv2 glew glu glut
USE_XORG=	xorgproto x11 xdamage xext xfixes xi xxf86vm

MESON_ARGS+=	-Dwith-glut=${LOCALBASE} \
		-Dgles1=disabled \
		-Dosmesa=disabled \
		-Dwayland=disabled \
		-Dwith-system-data-files=true

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-stage:
	${MV} ${STAGEDIR}/${PREFIX}/bin/bitmap ${STAGEDIR}/${PREFIX}/bin/bitmap_demo

.include <bsd.port.mk>
