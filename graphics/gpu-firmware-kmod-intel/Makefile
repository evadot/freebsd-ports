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

.if ${FLAVOR} == skylake
MAKE_ENV+=	I915KMODS="skylake"
PLIST_SUB=	SKYLAKE=""
PLIST_SUB+=	BROXTON="@comment "
PLIST_SUB+=	KABYLAKE="@comment "
PLIST_SUB+=	GEMINILAKE="@comment "
PLIST_SUB+=	COFFEELAKE="@comment "
PLIST_SUB+=	ICELAKE="@comment "
PLIST_SUB+=	ELKHARTLAKE="@comment "
PLIST_SUB+=	TIGERLAKE="@comment "
.endif

.if ${FLAVOR} == broxton
MAKE_ENV+=	I915KMODS="broxton"
PLIST_SUB=	SKYLAKE="@comment "
PLIST_SUB+=	BROXTON=""
PLIST_SUB+=	KABYLAKE="@comment "
PLIST_SUB+=	GEMINILAKE="@comment "
PLIST_SUB+=	COFFEELAKE="@comment "
PLIST_SUB+=	ICELAKE="@comment "
PLIST_SUB+=	ELKHARTLAKE="@comment "
PLIST_SUB+=	TIGERLAKE="@comment "
.endif

.if ${FLAVOR} == kabylake
MAKE_ENV+=	I915KMODS="kabylake"
PLIST_SUB=	SKYLAKE="@comment "
PLIST_SUB+=	BROXTON="@comment "
PLIST_SUB+=	KABYLAKE=""
PLIST_SUB+=	GEMINILAKE="@comment "
PLIST_SUB+=	COFFEELAKE="@comment "
PLIST_SUB+=	ICELAKE="@comment "
PLIST_SUB+=	ELKHARTLAKE="@comment "
PLIST_SUB+=	TIGERLAKE="@comment "
.endif

.if ${FLAVOR} == geminilake
MAKE_ENV+=	I915KMODS="geminilake"
PLIST_SUB=	SKYLAKE="@comment "
PLIST_SUB+=	BROXTON="@comment "
PLIST_SUB+=	KABYLAKE="@comment "
PLIST_SUB+=	GEMINILAKE=""
PLIST_SUB+=	COFFEELAKE="@comment "
PLIST_SUB+=	ICELAKE="@comment "
PLIST_SUB+=	ELKHARTLAKE="@comment "
PLIST_SUB+=	TIGERLAKE="@comment "
.endif

.if ${FLAVOR} == coffeelake
MAKE_ENV+=	I915KMODS="coffeelake"
PLIST_SUB=	SKYLAKE="@comment "
PLIST_SUB+=	BROXTON="@comment "
PLIST_SUB+=	KABYLAKE="@comment "
PLIST_SUB+=	GEMINILAKE="@comment "
PLIST_SUB+=	COFFEELAKE=""
PLIST_SUB+=	ICELAKE="@comment "
PLIST_SUB+=	ELKHARTLAKE="@comment "
PLIST_SUB+=	TIGERLAKE="@comment "
.endif

.if ${FLAVOR} == icelake
MAKE_ENV+=	I915KMODS="icelake"
PLIST_SUB=	SKYLAKE="@comment "
PLIST_SUB+=	BROXTON="@comment "
PLIST_SUB+=	KABYLAKE="@comment "
PLIST_SUB+=	GEMINILAKE="@comment "
PLIST_SUB+=	COFFEELAKE="@comment "
PLIST_SUB+=	ICELAKE=""
PLIST_SUB+=	ELKHARTLAKE="@comment "
PLIST_SUB+=	TIGERLAKE="@comment "
.endif

.if ${FLAVOR} == elkhartlake
MAKE_ENV+=	I915KMODS="elkhartlake"
PLIST_SUB=	SKYLAKE="@comment "
PLIST_SUB+=	BROXTON="@comment "
PLIST_SUB+=	KABYLAKE="@comment "
PLIST_SUB+=	GEMINILAKE="@comment "
PLIST_SUB+=	COFFEELAKE="@comment "
PLIST_SUB+=	ICELAKE="@comment "
PLIST_SUB+=	ELKHARTLAKE=""
PLIST_SUB+=	TIGERLAKE="@comment "
.endif

.if ${FLAVOR} == tigerlake
MAKE_ENV+=	I915KMODS="tigerlake"
PLIST_SUB=	SKYLAKE="@comment "
PLIST_SUB+=	BROXTON="@comment "
PLIST_SUB+=	KABYLAKE="@comment "
PLIST_SUB+=	GEMINILAKE="@comment "
PLIST_SUB+=	COFFEELAKE="@comment "
PLIST_SUB+=	ICELAKE="@comment "
PLIST_SUB+=	ELKHARTLAKE="@comment "
PLIST_SUB+=	TIGERLAKE=""
.endif

.include <bsd.port.mk>
