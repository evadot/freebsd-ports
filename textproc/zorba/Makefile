PORTNAME=	zorba
PORTVERSION=	2.7.0
PORTREVISION=	41
CATEGORIES=	textproc java
MASTER_SITES=	https://launchpadlibrarian.net/119058962/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose C++ XQuery processor
WWW=		http://www.zorba.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Unmaintained, outdated and fails to build with ICU 76.1
EXPIRATION_DATE=2025-02-28

LIB_DEPENDS=	libxerces-c.so:textproc/xerces-c3 \
		libicudata.so:devel/icu \
		libcurl.so:ftp/curl \
		libtidy5.so:www/tidy-html5 \
		libuuid.so:misc/e2fsprogs-libuuid
RUN_DEPENDS=	fop:textproc/fop

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	PHP PYTHON RUBY JAVA DOCS DOXYGEN
OPTIONS_SUB=	yes

DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS+=	doxygen:devel/doxygen
JAVA_CATEGORIES=	java
JAVA_USES=		java
JAVA_CMAKE_BOOL=	WITH_JAVA
JAVA_CMAKE_ON=	-DJAVA_LIBDIR:PATH=${JAVALIBDIR}
JAVA_CONFIGURE_ENV=	JAVA_HOME=${JAVA_HOME}
JAVA_VARS=		WITH_SWIG=yes
PHP_CMAKE_BOOL=		WITH_PHP5
PYTHON_CMAKE_BOOL=	WITH_PYTHON
RUBY_CMAKE_BOOL=	WITH_RUBY

# Both install include/xqc.h
CONFLICTS=	xqilla
CONFLICTS_BUILD=	bison

USES=		cmake compiler:c++11-lib gnome libedit
USE_GNOME=	libxml2 libxslt
USE_LDCONFIG=	yes
USE_CXXSTD=	c++11
CXXFLAGS+=	-DU_USING_ICU_NAMESPACE=1
CXXFLAGS+=	-I${LOCALBASE}/include -O1 # compiler hangs with -O2 on CURRENT
LDFLAGS+=	-L${LOCALBASE}/lib
CMAKE_ARGS=	-DCMAKE_REQUIRED_FLAGS:STRING="-I${LOCALBASE}/include -L${LOCALBASE}/lib" \
		-DLOCALBASE:STRING=${LOCALBASE}

MAKE_JOBS_UNSAFE=	yes # due to consistent failures in bison-generated code compilation

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

PLIST_SUB+=	FULLVERSION=${PORTVERSION} \
		MIDVERSION=${PORTVERSION:R} \
		MINVERSION=${PORTVERSION:R:R}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPHP}
USE_PHP=	tokenizer
USES+=		php:build
WITH_SWIG=	yes
CMAKE_ARGS+=	-DPHP5_INSTALL_PATH:FILEPATH="lib/php/${PHP_EXT_DIR}"
PLIST_SUB+=	PHP_EXTLIBDIR="lib/php/${PHP_EXT_DIR}"
.endif

.if ${PORT_OPTIONS:MPYTHON}
USES+=		python
WITH_SWIG=	yes
CMAKE_ARGS+=	-DPYTHON_SWIG_INSTALL_DIR:FILEPATH=${PYTHONPREFIX_SITELIBDIR:S/${PREFIX}\///}
PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHONPREFIX_SITELIBDIR:S/${PREFIX}\///}
BROKEN=		Does not stage
.endif

.if ${PORT_OPTIONS:MRUBY}
USES+=	ruby
WITH_SWIG=	yes
.endif

.if defined(WITH_SWIG)
BUILD_DEPENDS+=	swig:devel/swig
.endif

post-patch:
	${REINPLACE_CMD} \
		-e 's|FreeBSD|${OPSYS}|g' ${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/cmake_modules/FindPHP5.cmake

post-patch-DOCS-on:
	${REINPLACE_CMD} -e '/ADD_SUBDIRECTORY(doc)/d' \
		${WRKSRC}/CMakeLists.txt

post-install:
	${LN} -sf libzorba_simplestore.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libzorba_simplestore.so.${PORTVERSION:R:R}

post-install-DOCS-on:
.if !${PORT_OPTIONS:MDOXYGEN}
	cd ${STAGEDIR}${DOCSDIR} && ${RMDIR} c/html code/html code cxx/html zorba/html zorba/xqdoc zorba
.endif

test:	build
	cd ${BUILD_WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
