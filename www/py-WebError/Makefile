PORTNAME=	WebError
PORTVERSION=	0.13.1
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Web Error handling and exception catching
WWW=		https://pypi.org/project/WebError/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Paste>=1.7:www/py-paste@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Tempita>=0.3:textproc/py-Tempita@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=0.9.6.1:www/py-webob@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
