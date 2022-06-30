# Created by: Eric Anholt <anholt@FreeBSD.org>

PORTNAME?=	xorg
PORTVERSION?=	21.1.3
PORTREVISION?=	0
PORTEPOCH?=	1
CATEGORIES=	x11-servers
MASTER_SITES=	XORG/individual/xserver
DISTNAME=	xorg-server-${PORTVERSION}

MAINTAINER=	x11@FreeBSD.org
COMMENT?=	X.Org X server and related programs

LICENSE=	MIT

FLAVORS=	xorg Xnest Xephyr Xvfb
FLAVOR?=	${FLAVORS:[1]}

EXTRA_PATCHES=	${FILESDIR}/0001-xkb-fix-XkbSetMap-when-changing-a-keysym-without-cha.patch:-p1 \
		${FILESDIR}/0003-dix_Correctly_save_replayed_event_into_GrabInfoRec.patch:-p1   \
		${FILESDIR}/0002-xephyr_Dont_check_for_SeatId_anymore.patch:-p1                 \
		${FILESDIR}/0004-present_Check_for_NULL_to_prevent_crash.patch:-p1

USES=		compiler:c11 cpe gl meson ssl tar:xz xorg
USE_GL+=	gl

.if ${FLAVOR} == Xephyr
PORTNAME=	xephyr
.elif  ${FLAVOR} == xorg
PKGNAMESUFFIX=	-server
.elif ${FLAVOR} == Xnest
PORTEPOCH=	2
PKGNAMESUFFIX= -nestserver
.elif ${FLAVOR} == Xvfb
PKGNAMESUFFIX=	-vfbserver
.endif

.if ${FLAVOR} != xorg
PLIST=
PKGMESSAGE=
PLIST_FILES=	bin/${FLAVOR} \
		man/man1/${FLAVOR}.1.gz
PLIST_DIRS=	/var/db/xkb
.endif

DESCR=	${.CURDIR}/pkg-descr-${FLAVOR}

RUN_DEPENDS+=	xkeyboard-config>=2.5:x11/xkeyboard-config \
		xkbcomp:x11/xkbcomp

MESON_ARGS+=	-Dxwin=false \
		-Dxquartz=false \
		-Ddtrace=false \
		-Dhal=false \
		-Dsystemd_logind=false \
		-Dxselinux=false \
		-Dfallback_input_driver=libinput \
		-Ddocs=false \
		-Dudev_kms=false \
		-Dxcsecurity=true \
		-Dsha1=libmd \
		-Dxkb_dir=${LOCALBASE}/share/X11/xkb \
		-Dxkb_output_dir=/var/db/xkb \
		-D${FLAVOR:tl}=true

.for f in ${FLAVORS:N${FLAVOR}}
MESON_ARGS+=	-D${f:tl}=false
.endfor

.if ${FLAVOR} == xorg
LIB_DEPENDS+=		libudev.so:devel/libudev-devd
MESON_ARGS+=	-Dudev=true

OPTIONS_SUB=	yes
OPTIONS_DEFINE+=	SUID

SUID_DESC=	Install setuid wrapper to allow startx as non-root

SUID_MESON_TRUE=	suid_wrapper
.else
MESON_ARGS+=	-Dudev=false \
		-Dxcsecurity=false
.endif

.if ${FLAVOR} == xorg || ${FLAVOR} == Xephyr
MESON_ARGS+=	-Ddrm=true
LIB_DEPENDS+=	libdrm.so:graphics/libdrm \
		libepoxy.so:graphics/libepoxy
.endif

FONTPATH_ROOT?=	${LOCALBASE}/share/fonts
FONTPATHD?=	${PREFIX}/etc/X11/fontpath.d
DEFAULT_FONTPATH_LIST= \
	${FONTPATH_ROOT}/misc/	\
	${FONTPATH_ROOT}/TTF/ \
	${FONTPATH_ROOT}/OTF/ \
	${FONTPATH_ROOT}/Type1/ \
	${FONTPATH_ROOT}/100dpi/ \
	${FONTPATH_ROOT}/75dpi/ \
	catalogue:${FONTPATHD}
MESON_ARGS+=	-Ddefault_font_path=${DEFAULT_FONTPATH_LIST:ts,}
PLIST_SUB+=	FONTPATHD="${FONTPATHD:S,^${PREFIX}/,,}"

USE_GL+=	gl
USE_XORG+=	pixman xau xdmcp xfont2 xkbfile xorgproto xshmfence xtrans
CPE_VENDOR=	x.org
CPE_PRODUCT=	xorg-server

.if ${FLAVOR} == xorg
USE_GL+=	gbm
USE_XORG+=	pciaccess
.endif

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
# The reason why I use this is cause openssl from base doesn't install a .pc file
# and configure will fail trying to find it. Setting both of those variables to
# a *non-empty* value by-passes the pkg-config check.
CONFIGURE_ENV=	SHA1_LIB="-L/usr/lib -lcrypto" SHA1_CFLAGS="-I/usr/include"
.endif

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == armv7 || ${ARCH} == i386 || ${ARCH} == powerpc64 || ${ARCH} == powerpc64le
LIB_DEPENDS+=	libunwind.so:devel/libunwind
.endif

.if ${ARCH} == "sparc64"
PLIST_SUB+=	SPARC64=""
.else
PLIST_SUB+=	SPARC64="@comment "
.endif

.if ${FLAVOR} == xorg
post-install:
# Avoid conflict with nvidia-driver, move libglx.so into .xorg directory
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/xorg/modules/extensions/.xorg
	${MV} ${STAGEDIR}${PREFIX}/lib/xorg/modules/extensions/libglx.so \
		${STAGEDIR}${PREFIX}/lib/xorg/modules/extensions/.xorg/
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/X11/xorg.conf.d
	@${MKDIR} ${STAGEDIR}${FONTPATHD}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/X11/xorg.conf.d
	@${INSTALL_DATA} ${FILESDIR}/20-evdev-kbd.conf \
		${STAGEDIR}${PREFIX}/share/X11/xorg.conf.d
	${MKDIR} -p ${STAGEDIR}/var/db/xkb
.else
post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/lib/xorg/protocol.txt
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/xorg
	${RM} ${STAGEDIR}${PREFIX}/man/man1/Xserver.1
	${MKDIR} -p ${STAGEDIR}/var/db/xkb
.endif

post-install-SUID-on:
	${RM} ${STAGEDIR}${PREFIX}/bin/X
	${RLN} ${STAGEDIR}${PREFIX}/libexec/Xorg.wrap ${STAGEDIR}${PREFIX}/bin/X
	${MV} -f ${STAGEDIR}${PREFIX}/libexec/Xorg ${STAGEDIR}${PREFIX}/bin/Xorg

.include <bsd.port.post.mk>
