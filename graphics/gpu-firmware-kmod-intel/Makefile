# Created by: Emmanuel Vadot <manu@FreeBSD.org>

PORTNAME=	gpu-firmware-kmod-intel
PORTVERSION=	g20211014
CATEGORIES=	graphics

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Firmware modules for ${FLAVOR} Intel GPUs

LICENSE=	INTEL
LICENSE_NAME=	Intel firmware license (i915)
LICENSE_FILE=	${WRKSRC}/LICENSE.i915
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

PKGNAMESUFFIX=	-${FLAVOR:C/_/-/g}
FLAVORS=	skylake \
		broxton \
		kabylake \
		geminilake \
		coffeelake \
		icelake \
		elkhartlake \
		tigerlake
FLAVOR?=	skylake

USES=		kmod uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_PROJECT=	drm-kmod-firmware
GH_TAGNAME=	20211014_1

MAKE_ENV=	KMODS="i915kmsfw"
MAKE_ENV+=	I915KMODS="${FLAVOR}"

.include <bsd.port.pre.mk>

PLIST_SUB+=	${FLAVORS:N${FLAVOR}:@v@${v:tu}="\@comment "@}
PLIST_SUB+=	${FLAVOR:tu}=""

.include <bsd.port.post.mk>
