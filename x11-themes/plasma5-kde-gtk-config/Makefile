PORTNAME=	kde-gtk-config
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-themes kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 GTK2 and GTK3 configurator

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		sassc:textproc/sassc
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

USES=		cmake compiler:c++11-lib cpe gettext gnome \
		kde:5 pkgconfig qt:5 tar:xz xorg
USE_GNOME=	cairo gdkpixbuf2 gtk20 gtk30 glib20
USE_KDE=	archive attica auth codecs completion config configwidgets \
		coreaddons dbusaddons decoration guiaddons i18n iconthemes \
		jobwidgets kcmutils kio newstuff service widgetsaddons xmlgui \
		ecm_build
USE_QT=		concurrent core dbus gui network svg widgets xml \
		buildtools_build qmake_build testlib_build
USE_XORG=	xcursor

.include <bsd.port.mk>
