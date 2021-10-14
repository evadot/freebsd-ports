# Created by: Johannes Dieterich <jmd@FreeBSD.org>

PORTNAME=	gpu-firmware-kmod
PORTVERSION=	20211014
PORTEPOCH=	1
CATEGORIES=	graphics

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Firmware modules for the drm-kmod drivers

USES=		metaport

RUN_DEPENDS=	gpu-firmware-kmod-amd-banks>0:graphics/gpu-firmware-kmod-amd@banks \
		gpu-firmware-kmod-amd-bonaire>0:graphics/gpu-firmware-kmod-amd@bonaire \
		gpu-firmware-kmod-amd-carrizo>0:graphics/gpu-firmware-kmod-amd@carrizo \
		gpu-firmware-kmod-amd-fiji>0:graphics/gpu-firmware-kmod-amd@fiji \
		gpu-firmware-kmod-amd-hainan>0:graphics/gpu-firmware-kmod-amd@hainan \
		gpu-firmware-kmod-amd-hawaii>0:graphics/gpu-firmware-kmod-amd@hawaii \
		gpu-firmware-kmod-amd-kabini>0:graphics/gpu-firmware-kmod-amd@kabini \
		gpu-firmware-kmod-amd-kaveri>0:graphics/gpu-firmware-kmod-amd@kaveri \
		gpu-firmware-kmod-amd-mullins>0:graphics/gpu-firmware-kmod-amd@mullins \
		gpu-firmware-kmod-amd-navi10>0:graphics/gpu-firmware-kmod-amd@navi10 \
		gpu-firmware-kmod-amd-navi12>0:graphics/gpu-firmware-kmod-amd@navi12 \
		gpu-firmware-kmod-amd-navi14>0:graphics/gpu-firmware-kmod-amd@navi14 \
		gpu-firmware-kmod-amd-oland>0:graphics/gpu-firmware-kmod-amd@oland \
		gpu-firmware-kmod-amd-picasso>0:graphics/gpu-firmware-kmod-amd@picasso \
		gpu-firmware-kmod-amd-pitcairn>0:graphics/gpu-firmware-kmod-amd@pitcairn \
		gpu-firmware-kmod-amd-polaris10>0:graphics/gpu-firmware-kmod-amd@polaris10 \
		gpu-firmware-kmod-amd-polaris11>0:graphics/gpu-firmware-kmod-amd@polaris11 \
		gpu-firmware-kmod-amd-polaris12>0:graphics/gpu-firmware-kmod-amd@polaris12 \
		gpu-firmware-kmod-amd-raven>0:graphics/gpu-firmware-kmod-amd@raven \
		gpu-firmware-kmod-amd-raven2>0:graphics/gpu-firmware-kmod-amd@raven2 \
		gpu-firmware-kmod-amd-renoir>0:graphics/gpu-firmware-kmod-amd@renoir \
		gpu-firmware-kmod-amd-si58>0:graphics/gpu-firmware-kmod-amd@si58 \
		gpu-firmware-kmod-amd-stoney>0:graphics/gpu-firmware-kmod-amd@stoney \
		gpu-firmware-kmod-amd-tahiti>0:graphics/gpu-firmware-kmod-amd@tahiti \
		gpu-firmware-kmod-amd-tonga>0:graphics/gpu-firmware-kmod-amd@tonga \
		gpu-firmware-kmod-amd-topaz>0:graphics/gpu-firmware-kmod-amd@topaz \
		gpu-firmware-kmod-amd-vega10>0:graphics/gpu-firmware-kmod-amd@vega10 \
		gpu-firmware-kmod-amd-vega12>0:graphics/gpu-firmware-kmod-amd@vega12 \
		gpu-firmware-kmod-amd-vega20>0:graphics/gpu-firmware-kmod-amd@vega20 \
		gpu-firmware-kmod-amd-vegam>0:graphics/gpu-firmware-kmod-amd@vegam \
		gpu-firmware-kmod-amd-verde>0:graphics/gpu-firmware-kmod-amd@verde \
		gpu-firmware-kmod-intel-skylake>0:graphics/gpu-firmware-kmod-intel@skylake \
		gpu-firmware-kmod-intel-broxton>0:graphics/gpu-firmware-kmod-intel@broxton \
		gpu-firmware-kmod-intel-kabylake>0:graphics/gpu-firmware-kmod-intel@kabylake \
		gpu-firmware-kmod-intel-geminilake>0:graphics/gpu-firmware-kmod-intel@geminilake \
		gpu-firmware-kmod-intel-coffeelake>0:graphics/gpu-firmware-kmod-intel@coffeelake \
		gpu-firmware-kmod-intel-icelake>0:graphics/gpu-firmware-kmod-intel@icelake \
		gpu-firmware-kmod-intel-elkhartlake>0:graphics/gpu-firmware-kmod-intel@elkhartlake \
		gpu-firmware-kmod-intel-tigerlake>0:graphics/gpu-firmware-kmod-intel@tigerlake \
		gpu-firmware-kmod-radeon-aruba>0:graphics/gpu-firmware-kmod-radeon@aruba \
		gpu-firmware-kmod-radeon-barts>0:graphics/gpu-firmware-kmod-radeon@barts \
		gpu-firmware-kmod-radeon-bonaire>0:graphics/gpu-firmware-kmod-radeon@bonaire \
		gpu-firmware-kmod-radeon-btc>0:graphics/gpu-firmware-kmod-radeon@btc \
		gpu-firmware-kmod-radeon-caicos>0:graphics/gpu-firmware-kmod-radeon@caicos \
		gpu-firmware-kmod-radeon-cayman>0:graphics/gpu-firmware-kmod-radeon@cayman \
		gpu-firmware-kmod-radeon-cedar>0:graphics/gpu-firmware-kmod-radeon@cedar \
		gpu-firmware-kmod-radeon-cypress>0:graphics/gpu-firmware-kmod-radeon@cypress \
		gpu-firmware-kmod-radeon-hainan>0:graphics/gpu-firmware-kmod-radeon@hainan \
		gpu-firmware-kmod-radeon-hawaii>0:graphics/gpu-firmware-kmod-radeon@hawaii \
		gpu-firmware-kmod-radeon-juniper>0:graphics/gpu-firmware-kmod-radeon@juniper \
		gpu-firmware-kmod-radeon-kabini>0:graphics/gpu-firmware-kmod-radeon@kabini \
		gpu-firmware-kmod-radeon-kaveri>0:graphics/gpu-firmware-kmod-radeon@kaveri \
		gpu-firmware-kmod-radeon-mullins>0:graphics/gpu-firmware-kmod-radeon@mullins \
		gpu-firmware-kmod-radeon-oland>0:graphics/gpu-firmware-kmod-radeon@oland \
		gpu-firmware-kmod-radeon-palm>0:graphics/gpu-firmware-kmod-radeon@palm \
		gpu-firmware-kmod-radeon-pitcairn>0:graphics/gpu-firmware-kmod-radeon@pitcairn \
		gpu-firmware-kmod-radeon-r100>0:graphics/gpu-firmware-kmod-radeon@r100 \
		gpu-firmware-kmod-radeon-r200>0:graphics/gpu-firmware-kmod-radeon@r200 \
		gpu-firmware-kmod-radeon-r300>0:graphics/gpu-firmware-kmod-radeon@r300 \
		gpu-firmware-kmod-radeon-r420>0:graphics/gpu-firmware-kmod-radeon@r420 \
		gpu-firmware-kmod-radeon-r520>0:graphics/gpu-firmware-kmod-radeon@r520 \
		gpu-firmware-kmod-radeon-r600>0:graphics/gpu-firmware-kmod-radeon@r600 \
		gpu-firmware-kmod-radeon-r700>0:graphics/gpu-firmware-kmod-radeon@r700 \
		gpu-firmware-kmod-radeon-redwood>0:graphics/gpu-firmware-kmod-radeon@redwood \
		gpu-firmware-kmod-radeon-rs600>0:graphics/gpu-firmware-kmod-radeon@rs600 \
		gpu-firmware-kmod-radeon-rs690>0:graphics/gpu-firmware-kmod-radeon@rs690 \
		gpu-firmware-kmod-radeon-rs780>0:graphics/gpu-firmware-kmod-radeon@rs780 \
		gpu-firmware-kmod-radeon-rv610>0:graphics/gpu-firmware-kmod-radeon@rv610 \
		gpu-firmware-kmod-radeon-rv620>0:graphics/gpu-firmware-kmod-radeon@rv620 \
		gpu-firmware-kmod-radeon-rv630>0:graphics/gpu-firmware-kmod-radeon@rv630 \
		gpu-firmware-kmod-radeon-rv635>0:graphics/gpu-firmware-kmod-radeon@rv635 \
		gpu-firmware-kmod-radeon-rv670>0:graphics/gpu-firmware-kmod-radeon@rv670 \
		gpu-firmware-kmod-radeon-rv710>0:graphics/gpu-firmware-kmod-radeon@rv710 \
		gpu-firmware-kmod-radeon-rv730>0:graphics/gpu-firmware-kmod-radeon@rv730 \
		gpu-firmware-kmod-radeon-rv740>0:graphics/gpu-firmware-kmod-radeon@rv740 \
		gpu-firmware-kmod-radeon-rv770>0:graphics/gpu-firmware-kmod-radeon@rv770 \
		gpu-firmware-kmod-radeon-sumo>0:graphics/gpu-firmware-kmod-radeon@sumo \
		gpu-firmware-kmod-radeon-sumo2>0:graphics/gpu-firmware-kmod-radeon@sumo2 \
		gpu-firmware-kmod-radeon-tahiti>0:graphics/gpu-firmware-kmod-radeon@tahiti \
		gpu-firmware-kmod-radeon-turks>0:graphics/gpu-firmware-kmod-radeon@turks \
		gpu-firmware-kmod-radeon-verde>0:graphics/gpu-firmware-kmod-radeon@verde

.include <bsd.port.mk>
