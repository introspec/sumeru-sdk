include ${SUMERU_DIR}/conf/mk/sumeru-pre.mk

LIB = libsumeru_fs_sdfat.a

CFLAGS += -I. -Werror

CXXFILES += $(wildcard FsLib/*.cpp)
CXXFILES += $(wildcard ExFatLib/*.cpp)
CXXFILES += $(wildcard FatLib/*.cpp)
CXXFILES += $(wildcard common/*.cpp)

include ${SUMERU_DIR}/conf/mk/sumeru-lib-post.mk
