PORTNAME=	yukon
PORTVERSION=	2010011201
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	LOCAL/bms

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Real-time capture tool for OpenGL applications
WWW=		https://github.com/wereHamster/yukon

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libseom.so:graphics/seom

USES=		gl gmake tar:bzip2 xorg
USE_XORG=	x11 xv
USE_GL=		gl
USE_LDCONFIG=	${PREFIX}/lib/yukon

# NOTE: These should be bumped if the underlying GL or Xorg ports change.
LIBGL_MAJOR=	1
LIBX11_MAJOR=	6

MAKE_ENV+=	LIBGL_MAJOR="${LIBGL_MAJOR}" LIBX11_MAJOR="${LIBX11_MAJOR}"
PLIST_SUB+=	LIBGL_MAJOR="${LIBGL_MAJOR}" LIBX11_MAJOR="${LIBX11_MAJOR}"

#
# To roll snapshot: as bms: make BOOTSTRAP=defined fetch
#
.if defined(BOOTSTRAP)
.if ${WITH_SUBVERSION_VER:U} == LTS
FETCH_DEPENDS+=	svn:devel/subversion-lts
.else
FETCH_DEPENDS+=	svn:devel/subversion
.endif
SVN_REV=	158		# svn tip at epoch 2009120801
SVNROOT_URI=	https://devel.neopsis.com/svn/yukon

do-fetch:
	@${MKDIR} ${WRKDIR}
	svn export -r ${SVN_REV} ${SVNROOT_URI}/trunk ${WRKSRC}
	cd ${WRKDIR}; tar cvfy ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}
.if ${USER} == bms
	${CHMOD} ugo+r ${DISTDIR}/${DISTNAME}.tar.bz2
	scp -p ${DISTDIR}/${DISTNAME}.tar.bz2 \
	    freefall.freebsd.org:public_distfiles/
.endif
.endif # defined(BOOTSTRAP)

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/yukon,${PREFIX}/etc/yukon,' \
	    ${WRKSRC}/src/core/conf.c ${WRKSRC}/src/scripts/yukon

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/yukon/lib*.so.[0-9]* \
		${STAGEDIR}${PREFIX}/lib/yukon/yukon-core-lib
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/yukon/system
	@${PRINTF} 'LDPATH="%s"\n' ${PREFIX}/lib/yukon \
		>> ${WRKSRC}/yukon-system-conf
	${INSTALL_DATA} ${WRKSRC}/yukon-system-conf \
		${STAGEDIR}${PREFIX}/etc/yukon/system/default
	${INSTALL_DATA} ${WRKSRC}/tools/yukon.conf \
		${STAGEDIR}${PREFIX}/etc/yukon/conf.sample

.include <bsd.port.mk>
