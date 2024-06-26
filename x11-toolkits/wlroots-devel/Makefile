PORTNAME=	wlroots
DISTVERSION=	0.17.0-312
DISTVERSIONSUFFIX=	-gb1b34cd665
PORTREVISION=	2
CATEGORIES=	x11-toolkits
PKGNAMESUFFIX=	-devel

PATCH_SITES+=	https://github.com/hyprwm/wlroots-hyprland/raw/5c1d51c5a279/patches/:hyprland
PATCHFILES+=	surface-nondivisible-by-scale.patch:-p1:hyprland
PATCHFILES+=	nvidia-hardware-cursors.patch:-p1:hyprland
PATCH_SITES+=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	cc6a7a04418f.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/4697

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Modular Wayland compositor library (development snapshot)
WWW=		https://gitlab.freedesktop.org/wlroots/wlroots

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.33:graphics/wayland-protocols
LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libwayland-server.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gl meson pkgconfig xorg
USE_GITLAB=	yes
USE_GL=		gbm
USE_XORG=	pixman
USE_LDCONFIG=	yes
GL_SITE=	https://gitlab.freedesktop.org
MESON_ARGS=	-Dexamples=false -Dbackends=${BACKENDS:ts,} -Drenderers=${RENDERERS:ts,}

.ifdef PKGNAMESUFFIX
PORTSCOUT=	ignore:1
PREFIX=		${LOCALBASE}/${PKGBASE} # avoid conflict with the default
MESON_ARGS+=	-Ddatadir="${LOCALBASE}/share"
.endif

OPTIONS_DEFINE=	DRM OPENGL VULKAN X11
OPTIONS_DEFAULT=DRM OPENGL VULKAN X11
OPTIONS_SUB=	yes

DRM_DESC=		KMS console support
DRM_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
			hwdata>0:misc/hwdata
DRM_LIB_DEPENDS=	libudev.so:devel/libudev-devd \
			libliftoff.so:graphics/libliftoff \
			libdisplay-info.so:sysutils/libdisplay-info \
			libseat.so:sysutils/seatd \
			libinput.so:x11/libinput
DRM_MESON_ENABLED=	session
DRM_VARS=		BACKENDS+="drm libinput"

OPENGL_RUN_DEPENDS=	mesa-dri>0:graphics/mesa-dri
OPENGL_USE=		GL=egl,glesv2
OPENGL_VARS=		RENDERERS+=gles2

VULKAN_DESC=		Vulkan renderer
VULKAN_BUILD_DEPENDS=	glslangValidator:graphics/glslang \
			vulkan-headers>0:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
VULKAN_RUN_DEPENDS=	mesa-dri>0:graphics/mesa-dri
VULKAN_VARS=		RENDERERS+=vulkan

X11_LIB_DEPENDS=	libxcb-errors.so:x11/xcb-util-errors \
			libxcb-render-util.so:x11/xcb-util-renderutil \
			libxcb-icccm.so:x11/xcb-util-wm
X11_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
			Xwayland:x11-servers/xwayland
X11_RUN_DEPENDS=	Xwayland:x11-servers/xwayland
X11_USE=		XORG=xcb
X11_MESON_ENABLED=	xwayland
X11_VARS=		BACKENDS+=x11

post-patch:
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} "/STR/s/meson.project_version()/'${DISTVERSIONFULL}'/" \
		${WRKSRC}/include/wlr/meson.build
# XXX Drop after FreeBSD 12.4 EOL around 2023-12-31
# https://cgit.freebsd.org/src/commit/?id=d7535fb3e3cb
	@if [ ${OPSYS} = FreeBSD -a ${OSVERSION} -lt 1300515 ]; then \
		${REINPLACE_CMD} -e '/POSIX/s/199309/200112/' \
		${WRKSRC}/render/gles2/pass.c \
		${WRKSRC}/render/gles2/renderer.c \
		${WRKSRC}/types/wlr_presentation_time.c; \
	fi

.include <bsd.port.mk>
