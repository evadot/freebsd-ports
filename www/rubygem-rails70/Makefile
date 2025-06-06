PORTNAME=	rails
PORTVERSION=	7.0.8.7
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	70

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Full-stack web application framework
WWW=		https://rubyonrails.org/ \
		https://github.com/rails/rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actioncable70>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actioncable70 \
		rubygem-actionmailbox70>=${PORTVERSION}<${PORTVERSION}_99:mail/rubygem-actionmailbox70 \
		rubygem-actionmailer70>=${PORTVERSION}<${PORTVERSION}_99:mail/rubygem-actionmailer70 \
		rubygem-actionpack70>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack70 \
		rubygem-actiontext70>=${PORTVERSION}<${PORTVERSION}_99:textproc/rubygem-actiontext70 \
		rubygem-actionview70>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-actionview70 \
		rubygem-activejob70>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob70 \
		rubygem-activemodel70>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activemodel70 \
		rubygem-activerecord70>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activerecord70 \
		rubygem-activestorage70>=${PORTVERSION}<${PORTVERSION}_99:net/rubygem-activestorage70 \
		rubygem-activesupport70>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport70 \
		rubygem-bundler>=1.15.0:sysutils/rubygem-bundler \
		rubygem-railties70>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-railties70 \
		rubygem-bootsnap>=1.4.4:devel/rubygem-bootsnap \
		rubygem-capybara>=3.26:devel/rubygem-capybara \
		rubygem-connection_pool>=0:net/rubygem-connection_pool \
		rubygem-cssbundling-rails-rails70>=0:www/rubygem-cssbundling-rails-rails70 \
		rubygem-dalli>=3.0.1:databases/rubygem-dalli \
		rubygem-image_processing>=1.2<2:graphics/rubygem-image_processing \
		rubygem-importmap-rails-rails70>=0:www/rubygem-importmap-rails-rails70 \
		rubygem-jsbundling-rails-rails70>=0:www/rubygem-jsbundling-rails-rails70 \
		rubygem-json>=2.0.0:devel/rubygem-json \
		rubygem-libxml-ruby>=0:textproc/rubygem-libxml-ruby \
		rubygem-listen>=3.3<4:devel/rubygem-listen \
		rubygem-minitest>=5.15.0:devel/rubygem-minitest \
		rubygem-nokogiri>=1.8.1:textproc/rubygem-nokogiri \
		rubygem-propshaft-rails70>=0.1.7:www/rubygem-propshaft-rails70 \
		rubygem-puma>=5.0.3:www/rubygem-puma \
		rubygem-que>=0:devel/rubygem-que \
		rubygem-rack-cache>=1.2<2:www/rubygem-rack-cache \
		rubygem-rake>=13:devel/rubygem-rake \
		rubygem-readline-ext>=0:devel/rubygem-readline-ext \
		rubygem-redis-namespace>=0:databases/rubygem-redis-namespace \
		rubygem-rexml>=0:textproc/rubygem-rexml \
		rubygem-selenium-webdriver>=4.11.0:www/rubygem-selenium-webdriver \
		rubygem-sprockets-rails-rails70>=2.0.0:devel/rubygem-sprockets-rails-rails70 \
		rubygem-sqlite3>=1.4:databases/rubygem-sqlite3 \
		rubygem-stimulus-rails-rails70>=0:www/rubygem-stimulus-rails-rails70 \
		rubygem-sucker_punch>=0:devel/rubygem-sucker_punch \
		rubygem-tailwindcss-rails-rails70>=0:www/rubygem-tailwindcss-rails-rails70 \
		rubygem-turbo-rails-rails70>=0:www/rubygem-turbo-rails-rails70 \
		rubygem-webmock>=0:www/rubygem-webmock \
		rubygem-webrick>=0:www/rubygem-webrick

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	ruby_on_rails

PORTSCOUT=	limit:^7\.0\.

.include <bsd.port.pre.mk>

.if ${RUBY_VER} <= 3.1
RUN_DEPENDS+=	rubygem-cgi>=0.3.6:www/rubygem-cgi
.endif

.include <bsd.port.post.mk>
