PORTNAME=	libdrm
PORTVERSION=	2.4.120
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	https://dri.freedesktop.org/libdrm/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Direct Rendering Manager library and headers
WWW=		https://dri.freedesktop.org/

LICENSE=	MIT

SUBPACKAGES?=	amdgpu radeon tools

BUILD_DEPENDS=	rst2man:textproc/py-docutils@${PY_FLAVOR}
LIB_DEPENDS=	libpciaccess.so:devel/libpciaccess

SELF_DEPENDS.amdgpu=	main
SELF_DEPENDS.radeon=	main
SELF_DEPENDS.intel=	main
SELF_DEPENDS.vmwgfx=	main
SELF_DEPENDS.tools=	main

USES=		gnome meson pkgconfig tar:xz
USE_LDCONFIG=	yes
MESON_ARGS=	-Dvalgrind=disabled

# avoid circular dependency in case cairo supports OpenGL (cairo->mesa-libs->libdrm->cairo)
MESON_ARGS+=	-Dcairo-tests=disabled

# Disable some targets known to not work on FreeBSD
MESON_ARGS+=	-Domap=disabled \
		-Dexynos=disabled \
		-Dfreedreno=disabled \
		-Dfreedreno-kgsl=false \
		-Dvc4=disabled \
		-Detnaviv=disabled \
		-Dnouveau=disabled

MESON_ARGS+=	-Dman-pages=enabled \
		-Dinstall-test-programs=true

.include <bsd.port.options.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386
MESON_ARGS+=	-Dvmwgfx=enabled \
		-Dintel=enabled
SUBPACKAGES+=	intel \
		vmwgfx
.else
MESON_ARGS+=	-Dvmwgfx=disabled \
		-Dintel=disabled
.endif

.include <bsd.port.mk>
