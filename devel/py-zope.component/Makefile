PORTNAME=	zope.component
PORTVERSION=	4.2.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope Component Architecture
WWW=		https://pypi.org/project/zope.component/

LICENSE=	ZPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.event>=0:devel/py-zope.event@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=4.1.0:devel/py-zope.interface@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
