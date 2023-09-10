CC = gcc
LD = gcc
TARGET = main

BIN_DIR = bin
ROOT_DIR = $(shell pwd)

CFLAGS = -g -O0 -Wall -Wextra
CFILES = $(ROOT_DIR)/main.c
INCS = -I -I/$(ROOT_DIR)

export ROOT_DIR CFLAGS

include $(ROOT_DIR)/src/module.mk
include $(ROOT_DIR)/test/module.mk

.PHONY : clean all $(SUB_DIRS)

all : prepare $(TARGET)
	@echo "Making $^"

$(TARGET) : $(CFILES)
	@echo "Building $@"
	$(CC) $(CFLAGS) $(INCS) $^ -o $(BIN_DIR)/$@

prepare :
	@-mkdir -p $(BIN_DIR)

clean :
	@-rm -rf ./$(BIN_DIR)
