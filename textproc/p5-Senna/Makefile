PORTNAME=	Senna
PORTVERSION=	0.51
PORTREVISION=	5
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DMAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for Embeddable Fulltext Search Engine
WWW=		https://metacpan.org/release/Senna

LICENSE=	LGPL21

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	senna-cfg:textproc/senna

USES=		localbase perl5
USE_PERL5=	modbuild

CONFIGURE_ARGS+=	</dev/null

PORTSCOUT=	skipv:0.60000

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
