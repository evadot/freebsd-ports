PORTNAME=	icingaweb2-module-x509
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0-8
DISTVERSIONSUFFIX=	-g39fd7e1
CATEGORIES=	net-mgmt www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	gettoknowmi@yahoo.com
COMMENT=	Automates certificate monitoring with Icinga

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS+=	icingaweb2${PHP_PKGNAMESUFFIX}>=2.4.1:net-mgmt/icingaweb2@${PHP_FLAVOR} \
		php74-gmp>0:math/php74-gmp \
		openssl>0:security/openssl \
		icingaweb2-module-reactbundle${PHP_PKGNAMESUFFIX}>0:net-mgmt/icingaweb2-module-reactbundle@${PHP_FLAVOR} \
		icingaweb2-module-ipl${PHP_PKGNAMESUFFIX}>0:net-mgmt/icingaweb2-module-ipl@${PHP_FLAVOR}

USES=		php:web,flavors mysql:server

USE_GITHUB=	yes
GH_ACCOUNT=	Icinga

NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR?=	${PREFIX}/www/icingaweb2/modules/${PORTNAME:C/^.*-//}

do-install:
	@${RM} -r ${WRKSRC}/.github
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
