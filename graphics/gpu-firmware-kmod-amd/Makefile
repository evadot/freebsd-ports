# Created by: Emmanuel Vadot <manu@FreeBSD.org>

PORTNAME=	gpu-firmware-kmod-amd
PORTVERSION=	g20211014
CATEGORIES=	graphics

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Firmware modules for ${FLAVOR} AMD GPUs

LICENSE=	AMD
LICENSE_NAME=	AMD firmware license (amdgpu/radeon)
LICENSE_FILE=	${WRKSRC}/LICENSE.radeon
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

PKGNAMESUFFIX=	-${FLAVOR:C/_/-/g}
FLAVORS=	banks \
		bonaire \
		carrizo \
		fiji \
		hainan \
		hawaii \
		kabini \
		kaveri \
		mullins \
		navi10 \
		navi12 \
		navi14 \
		oland \
		picasso \
		pitcairn \
		polaris10 \
		polaris11 \
		polaris12 \
		raven \
		raven2 \
		renoir \
		si58 \
		stoney \
		tahiti \
		tonga \
		topaz \
		vega10 \
		vega12 \
		vega20 \
		vegam \
		verde

FLAVOR?=	banks

USES=		kmod uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_PROJECT=	drm-kmod-firmware
GH_TAGNAME=	20211014_1

MAKE_ENV=	KMODS="amdgpukmsfw"
MAKE_ENV+=	AMDGPUKMODS="${FLAVOR}"

PLIST_SUB=	${BANKS} \
		${BONAIRE} \
		${CARRIZO} \
		${FIJI} \
		${HAINAN} \
		${HAWAII} \
		${KABINI} \
		${KAVERI} \
		${MULLINS} \
		${NAVI10} \
		${NAVI12} \
		${NAVI14} \
		${OLAND} \
		${PICASSO} \
		${PITCAIRN} \
		${POLARIS10} \
		${POLARIS11} \
		${POLARIS12} \
		${RAVEN} \
		${RAVEN2} \
		${RENOIR} \
		${SI58} \
		${STONEY} \
		${TAHITI} \
		${TONGA} \
		${TOPAZ} \
		${VEGA10} \
		${VEGA12} \
		${VEGA20} \
		${VEGAM} \
		${VERDE}

.if ${FLAVOR} == banks
BANKS=		BANKS=""
.endif

.if ${FLAVOR} == bonaire
BONAIRE=	BONAIRE=""
.endif

.if ${FLAVOR} == carrizo
CARRIZO=	CARRIZO=""
.endif

.if ${FLAVOR} == fiji
FIJI=		FIJI=""
.endif

.if ${FLAVOR} == hainan
HAINAN=		HAINAN=""
.endif

.if ${FLAVOR} == hawaii
HAWAII=		HAWAII=""
.endif

.if ${FLAVOR} == kabini
KABINI=		KABINI=""
.endif

.if ${FLAVOR} == kaveri
KAVERI=		KAVERI=""
.endif

.if ${FLAVOR} == mullins
MULLINS=	MULLINS=""
.endif

.if ${FLAVOR} == navi10
NAVI10=		NAVI10=""
.endif

.if ${FLAVOR} == navi12
NAVI12=		NAVI12=""
.endif

.if ${FLAVOR} == navi14
NAVI14=	NAVI14=""
.endif

.if ${FLAVOR} == oland
OLAND=		OLAND=""
.endif

.if ${FLAVOR} == picasso
PICASSO=	PICASSO=""
.endif

.if ${FLAVOR} == pitcairn
PITCAIRN=	PITCAIRN=""
.endif

.if ${FLAVOR} == polaris10
POLARIS10=	POLARIS10=""
.endif

.if ${FLAVOR} == polaris11
POLARIS11=	POLARIS11=""
.endif

.if ${FLAVOR} == polaris12
POLARIS12=	POLARIS12=""
.endif

.if ${FLAVOR} == raven
RAVEN=		RAVEN=""
.endif

.if ${FLAVOR} == raven2
RAVEN2=		RAVEN2=""
.endif

.if ${FLAVOR} == renoir
RENOIR=		RENOIR=""
.endif

.if ${FLAVOR} == si58
SI58=		SI58=""
.endif

.if ${FLAVOR} == stoney
STONEY=		STONEY=""
.endif

.if ${FLAVOR} == tahiti
TAHITI=		TAHITI=""
.endif

.if ${FLAVOR} == tonga
TONGA=		TONGA=""
.endif

.if ${FLAVOR} == topaz
TOPAZ=		TOPAZ=""
.endif

.if ${FLAVOR} == vega10
VEGA10=		VEGA10=""
.endif

.if ${FLAVOR} == vega12
VEGA12=		VEGA12=""
.endif

.if ${FLAVOR} == vega20
VEGA20=		VEGA20=""
.endif

.if ${FLAVOR} == vegam
VEGAM=		VEGAM=""
.endif

.if ${FLAVOR} == verde
VERDE=		VERDE=""
.endif

BANKS?=		BANKS="@comment "
BONAIRE?=	BONAIRE="@comment "
CARRIZO?=	CARRIZO="@comment "
FIJI?=		FIJI="@comment "
HAINAN?=	HAINAN="@comment "
HAWAII?=	HAWAII="@comment "
KABINI?=	KABINI="@comment "
KAVERI?=	KAVERI="@comment "
MULLINS?=	MULLINS="@comment "
NAVI10?=	NAVI10="@comment "
NAVI12?=	NAVI12="@comment "
NAVI14?=	NAVI14="@comment "
OLAND?=		OLAND="@comment "
PICASSO?=	PICASSO="@comment "
PITCAIRN?=	PITCAIRN="@comment "
POLARIS10?=	POLARIS10="@comment "
POLARIS11?=	POLARIS11="@comment "
POLARIS12?=	POLARIS12="@comment "
RAVEN?=		RAVEN="@comment "
RAVEN2?=	RAVEN2="@comment "
RENOIR?=	RENOIR="@comment "
SI58?=		SI58="@comment "
STONEY?=	STONEY="@comment "
TAHITI?=	TAHITI="@comment "
TONGA?=		TONGA="@comment "
TOPAZ?=		TOPAZ="@comment "
VEGA10?=	VEGA10="@comment "
VEGA12?=	VEGA12="@comment "
VEGA20?=	VEGA20="@comment "
VEGAM?=		VEGAM="@comment "
VERDE?=		VERDE="@comment "

.include <bsd.port.mk>
