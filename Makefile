SRCDIR := src
BUILDDIR := build
TARGET := bin/main
 
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS=-ggdb -std=c++14 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant
INC := -I include

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	g++ $^ -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	g++ $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."; 
	/bin/rm -rf $(BUILDDIR) $(TARGET)