PORTNAME=	tinc
PORTVERSION=	1.1pre18
PORTREVISION=	4
CATEGORIES=	security net-vpn
MASTER_SITES=	https://www.tinc-vpn.org/packages/ \
		http://www.tinc-vpn.org/packages/
PKGNAMESUFFIX=	-devel

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Virtual Private Network (VPN) daemon
WWW=		https://www.tinc-vpn.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblzo2.so:archivers/lzo2

USERS=	tinc
GROUPS=	tinc
USES=		cpe ssl makeinfo readline localbase:ldflags
CPE_VENDOR=	tinc-vpn
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--localstatedir=/var --with-curses=/usr
USE_RC_SUBR=	tincd
INFO=		tinc
PLIST_FILES=	"@(root,tinc,2550) sbin/tincd" sbin/tinc \
		share/bash-completion/completions/tinc \
		share/man/man8/tinc-gui.8.gz share/man/man5/tinc.conf.5.gz \
		share/man/man8/tinc.8.gz share/man/man8/tincd.8.gz

.include <bsd.port.mk>
