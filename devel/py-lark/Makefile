PORTNAME=	lark
PORTVERSION=	1.2.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Modern parsing library
WWW=		https://github.com/lark-parser/lark

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.2.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		dos2unix python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	ATOMIC_CACHE INTEREGULAR NEARLEY REGEX
OPTIONS_DEFAULT=ATOMIC_CACHE INTEREGULAR REGEX
ATOMIC_CACHE_DESC=	Multiprocess caching and crash recovery support
INTEREGULAR_DESC=	Check regex collisions
NEARLEY_DESC=		Import grammars from Nearley.js
REGEX_DESC=		Use third-party regex instead of standard library re

ATOMIC_CACHE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}atomicwrites>=0:devel/py-atomicwrites@${PY_FLAVOR}
INTEREGULAR_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}interegular>=0.3.1<0.4.0:textproc/py-interegular@${PY_FLAVOR}
NEARLEY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Js2Py>=0:devel/py-Js2Py@${PY_FLAVOR}
REGEX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}regex>=0:textproc/py-regex@${PY_FLAVOR}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MATOMIC_CACHE}
DEPRECATED=	Depends on expired devel/py-atomicwrites
EXPIRATION_DATE=2025-06-21
.endif

.include <bsd.port.mk>
