###############################################################################
# File        : Makefile                                                      #
# Author      : Aditya Saripalli                                              #
# Description : A generic Makefile for building any c++ project with the      #
#               following directory structure.                                #
#               ./src                                                         #
#               ./obj                                                         #
#               ./bin                                                         #
###############################################################################

# Add your preferred binary name.
TARGET  = ems

CC      = g++
CCFLAGS = -Wall -std=c++1z
SRCDIR  = ./src
OBJDIR  = ./obj
BINDIR  = ./bin

FILES   := $(wildcard $(SRCDIR)/*.C)
OBJECTS := $(FILES:$(SRCDIR)/%.C=$(OBJDIR)/%.o)

$(BINDIR)/$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
	@echo "Linking Complete."
	@echo "To start the program run --> "$(BINDIR)"/"$(TARGET)

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.C
	$(CC) $(CCFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully."

clean:
	@echo "Cleaning all the object files and binaries."
	rm -f core $(OBJECTS) $(BINDIR)/$(TARGET)

run:
	make clean;make
	$(BINDIR)/ems
