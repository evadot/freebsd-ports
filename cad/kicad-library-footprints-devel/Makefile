PORTNAME=	kicad
DISTVERSION=	r${GIT_FP_DATE}
PORTREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	https://gitlab.com/kicad/libraries/${PORTNAME}-footprints/-/archive/${GL_TAGNAME}/
PKGNAMESUFFIX=	-library-footprints-devel
DISTNAME=	${PORTNAME}-footprints-${GL_TAGNAME}

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Official KiCad Footprint Libraries (Git snapshot)
WWW=		https://github.com/KiCad/kicad-footprints

LICENSE=	GPLv2

RUN_DEPENDS=	kicad:cad/kicad-devel

CONFLICTS_INSTALL=	kicad-library-footprints # share/kicad/footprints/Audio_Module.pretty/Reverb_BTDR-1H.kicad_mod

USE_GITLAB=	nodefault
GL_ACCOUNT=	kicad
GL_PROJECT=	kicad/libraries
GL_TAGNAME=	${GIT_FP_HASH}
# WRKSRC=	${WRKDIR}/${PORTNAME}-${GL_TAGNAME}-${GL_TAGNAME}

USES=		cmake

CMAKE_ARGS=	-DLOCALBASE="${LOCALBASE}" \
		-DCMAKE_BUILD_TYPE="Release" \
		-DKICAD_TESTING_VERSION=ON \
		-DKICAD_BUILD_VERSION=${DISTVERSION}
INSTALL_TARGET=	install

NO_ARCH=	yes

.include "Makefile.git_rev"

# Updating to new rev:
# sh files/newVersion.sh
# make install #breaks probably due to plist differences
# make makeplist > pkg-plist #One has to edit/review the generated plist
# make generate-plist && make check-plist

.include <bsd.port.mk>
