SRCDIR := src
BUILDDIR := build
TARGET := bin/time_sorts
 
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS=-ggdb -std=c++14 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant
INC := -I include

$(TARGET): $(OBJECTS)
	g++ $^ -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	g++ $(CFLAGS) $(INC) -c -o $@ $<

clean:
	/bin/rm -rf $(BUILDDIR) $(TARGET) timings.csv