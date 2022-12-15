# contrib/oauth_token_validator/Makefile

MODULE_big = oauth_token_validator
OBJS = oauth_token_validator.o

EXTENSION = oauth_token_validator
PGFILEDESC = "oauth_token_validator - validate provider specific token"
DATA = oauth_token_validator--1.0.sql

ifdef USE_PGXS
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
else
subdir = contrib/oauth_token_validator
top_builddir = ../..
include $(top_builddir)/src/Makefile.global
include $(top_srcdir)/contrib/contrib-global.mk
endif
