PORTNAME=	cmakedoc
DISTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Command-line tool to read CMake documentation
WWW=		https://github.com/agateau/cmakedoc

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	cmake-doc>=0:devel/cmake-doc

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	agateau
USE_PYTHON=	autoplist distutils noflavors

.include <bsd.port.mk>
