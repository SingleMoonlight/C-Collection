CC = gcc
LD = gcc
TARGET = main

BIN_DIR = bin
ROOT_DIR = $(shell pwd)

CFLAGS = -g -O0 -Wall -Wextra
CFILES = $(ROOT_DIR)/main.c
CINCS = -I

export ROOT_DIR CFLAGS

include $(ROOT_DIR)/module.mk

.PHONY : clean all $(SUB_DIRS)

all : prepare $(TARGET)
	@echo "Making $^"

$(TARGET) : $(CFILES)
	@echo "Building $@"
	@$(CC) $(CFLAGS) $(CINCS) $^ -o $(BIN_DIR)/$@

prepare :
	@-mkdir -p $(BIN_DIR)

clean :
	@-rm -rf ./$(BIN_DIR)
