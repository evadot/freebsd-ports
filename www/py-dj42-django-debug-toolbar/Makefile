PORTNAME=	django-debug-toolbar
PORTVERSION=	4.3.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj42-
DISTNAME=	django_debug_toolbar-${PORTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Configurable set of panels to display debug information
WWW=		https://github.com/jazzband/django-debug-toolbar

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Obsolete, please use www/py-django-debug-toolbar instead
EXPIRATION_DATE=2024-06-15

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=3.2.4:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlparse>=0.2.0:databases/py-sqlparse@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*django-debug-toolbar

.include <bsd.port.mk>
