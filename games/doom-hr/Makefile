PORTNAME=	hr
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	https://ftp.fu-berlin.de/pc/msdos/games/idgames/themes/hr/
PKGNAMEPREFIX=	${DMPKGNAMEPREFIX}
DISTFILES=	${PORTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hell Revealed is a megawad, a 32-level replacement for DooM II

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
EXTRACT_BEFORE_ARGS=	-Lqo

OPTIONS_DEFINE=	DEMO_NM DEMO_UV DOCS
OPTIONS_DEFAULT=	DEMO_NM DEMO_UV
DEMO_NM_DESC=	Install demos with -nomonsters
DEMO_UV_DESC=	Install Ultra-Violence demos

OPTIONS_SUB=	yes

DATADIR=	${DMDIR}/${PORTNAME}

DEMO_NM_DISTFILES=	hrhelp${EXTRACT_SUFX}
DEMO_UV_DISTFILES=	hruvlmp2${EXTRACT_SUFX}

.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.wad ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MDEMO_NM} || !empty(PORT_OPTIONS:MDEMO_UV)
	${INSTALL_DATA} ${WRKSRC}/*.lmp ${STAGEDIR}${DATADIR}
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
