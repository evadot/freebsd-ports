PORTNAME=	syncthing
PORTVERSION=	1.19.2
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Encrypted file sync tool

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules

USE_RC_SUBR=	syncthing syncthing-discosrv syncthing-relaysrv syncthing-relaypoolsrv

BINS=		syncthing stdiscosrv strelaysrv strelaypoolsrv

GO_MODULE=	github.com/syncthing/syncthing

.for x in ${BINS}
PLIST_FILES+=	bin/${x}
.endfor

PORTDOCS=	*

USERS=		syncthing
GROUPS=		syncthing

# Anonymize
MAKE_ENV+=	BUILD_USER=ports BUILD_HOST=freebsd

OPTIONS_DEFINE=	DOCS

do-build:
	@( cd ${WRKSRC} ; \
		${SETENV} ${MAKE_ENV} ${GO_ENV} CGO_ENABLED=0 go run build.go -version v${PORTVERSION} -no-upgrade build ; \
		${SETENV} ${MAKE_ENV} ${GO_ENV} CGO_ENABLED=0 go run build.go -version v${PORTVERSION} -no-upgrade build stdiscosrv ; \
		${SETENV} ${MAKE_ENV} ${GO_ENV} CGO_ENABLED=0 go run build.go -version v${PORTVERSION} -no-upgrade build strelaysrv ; \
		${SETENV} ${MAKE_ENV} ${GO_ENV} CGO_ENABLED=0 go run build.go -version v${PORTVERSION} -no-upgrade build strelaypoolsrv ; \
		)

do-install:
.for x in ${BINS}
	${INSTALL_PROGRAM} ${WRKSRC}/${x} \
		${STAGEDIR}${PREFIX}/bin/
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for x in AUTHORS LICENSE README.md
	${INSTALL_DATA} ${WRKSRC}/${x} \
		${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
