PORTNAME=	django-js-asset
DISTVERSION=	2.2.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj42-
DISTNAME=	django_js_asset-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Insert script tags with additional attributes for django.forms.Media
WWW=		https://github.com/matthiask/django-js-asset

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Obsolete, please use www/py-django-js-asset instead
EXPIRATION_DATE=2024-06-15

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=3.2:www/py-django42@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=		yes

.include <bsd.port.mk>
