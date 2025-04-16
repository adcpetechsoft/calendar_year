# Variables
PREFIX ?= 
BINDIR ?= $(PREFIX)/bin
TARGET = my_program

# Install and Uninstall
install:
	@echo "Installing $(TARGET) to $(BINDIR)"
	@mkdir -p $(BINDIR)
	@cp $(TARGET) $(BINDIR)/$(TARGET)

uninstall:
	@echo "Uninstalling $(TARGET) from $(BINDIR)"
	@rm -f $(BINDIR)/$(TARGET)

# Phony targets
.PHONY: install uninstall