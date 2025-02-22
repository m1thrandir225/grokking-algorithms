# Check if FOLDER is provided
ifndef FOLDER
$(error FOLDER is not set. Usage: make compile FOLDER=<folder_name>)
endif

# Variables
CC = gcc
CFLAGS = -Wall -Wextra
SOURCE = $(FOLDER)/algo.c
OUTPUT = $(FOLDER)/algo

# Default target
.PHONY: all
all: help

# Help target
.PHONY: help
help:
	@echo "Usage:"
	@echo "  make compile FOLDER=<folder_name>  - Compile algo.c from specified folder"
	@echo "  make run FOLDER=<folder_name>      - Compile and run algo from specified folder"
	@echo "  make clean FOLDER=<folder_name>    - Remove binary from specified folder"

# Compile target
.PHONY: compile
compile:
	@if [ ! -f $(SOURCE) ]; then \
		echo "Error: $(SOURCE) does not exist"; \
		exit 1; \
	fi
	$(CC) $(CFLAGS) $(SOURCE) -o $(OUTPUT)
	@echo "Compiled $(SOURCE) to $(OUTPUT)"

# Run target
.PHONY: run
run: compile
	@echo "Running $(OUTPUT)"
	@./$(OUTPUT)

# Clean target
.PHONY: clean
clean:
	@if [ -f $(OUTPUT) ]; then \
		rm $(OUTPUT); \
		echo "Removed $(OUTPUT)"; \
	fi

