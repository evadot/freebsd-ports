PORTNAME=	Project-Gantt
PORTVERSION=	1.03
PORTREVISION=	11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Create Gantt charts to manage project scheduling
WWW=		https://metacpan.org/release/Project-Gantt

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Date>=0:devel/p5-Class-Date

USES=		magick:run perl5
USE_PERL5=	configure
WRKSRC=		${WRKDIR}/Gantt

.include <bsd.port.mk>
