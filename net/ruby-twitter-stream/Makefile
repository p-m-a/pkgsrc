# $NetBSD: Makefile,v 1.12 2014/03/26 14:28:18 taca Exp $

DISTNAME=	twitter-stream-0.1.16
PKGREVISION=	1
CATEGORIES=	net

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://github.com/voloko/twitter-stream
COMMENT=	Twitter realtime API client
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0.12.8:../../devel/ruby-eventmachine
DEPENDS+=	${RUBY_PKGPREFIX}-simple_oauth>=0.1.4:../../security/ruby-simple_oauth
DEPENDS+=	${RUBY_PKGPREFIX}-http_parser.rb>=0.5.1:../../www/ruby-http_parser.rb

OVERRIDE_GEMSPEC+=	simple_oauth>=0.1.4

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
