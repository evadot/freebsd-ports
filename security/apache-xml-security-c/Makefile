PORTNAME=	xml-security-c
DISTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://shibboleth.net/downloads/xml-security-c/${DISTVERSION}/
PKGNAMEPREFIX=	apache-

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Apache XML security libraries - C++ version
WWW=		https://shibboleth.atlassian.net/wiki/spaces/DEV/pages/3726671873/Santuario

LICENSE=	APACHE20

LIB_DEPENDS+=	libxerces-c.so:textproc/xerces-c3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking --without-xalan --with-openssl=${OPENSSLBASE}
USES=		cpe gmake libtool tar:bzip2 ssl pkgconfig autoreconf
USE_LDCONFIG=	yes
CONFIGURE_ENV+=	openssl_LIBS="-L${OPENSSLLIB} -lcrypto" openssl_CFLAGS=-I${OPENSSLBASE}

CPE_PRODUCT=	xml_security_for_c++
CPE_VENDOR=	apache

.include <bsd.port.mk>
