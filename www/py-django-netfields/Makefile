PORTNAME=	django-netfields
DISTVERSION=	1.3.2
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Django PostgreSQL netfields implementation
WWW=		https://github.com/jimfunk/django-postgresql-netfields

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=1.8:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg2>0:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0:net/py-netaddr@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
