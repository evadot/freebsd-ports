PORTNAME=	denature
PORTVERSION=	0.6.5
PORTREVISION=	3
CATEGORIES=	textproc java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTML to PDF converter
WWW=		https://denature.sourceforge.net/

LICENSE=	GPLv2

RUN_DEPENDS=	p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-HTML-Tagset>=0:www/p5-HTML-Tagset \
		p5-HTML-Tree>=0:www/p5-HTML-Tree \
		p5-CSS-Tiny>=0:textproc/p5-CSS-Tiny \
		fop:textproc/fop

USES=		java perl5
POD2MAN?=	pod2man
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/denature share/man/man1/denature.1.gz

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
			-e 's|%%JAVA_HOME%%|${JAVA_HOME}|' \
		 ${WRKSRC}/denature

do-build:
	cd ${WRKSRC} && ${POD2MAN} denature > denature.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/denature ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/denature.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
