
IDIR = include
ODIR = obj
SDIR = src

CC = gcc
CFLAGS = -I"/usr/include/SDL2" -I$(IDIR) -lSDL2

_DEPS = $(shell ls $(IDIR))
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
__OBJ = $(shell ls $(SDIR))
_OBJ = $(__OBJ:.c=.o)
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

OUT = Breakout

.PHONY: clean

test:
	echo $(_DEPS)
	echo $(DEPS)
	echo $(_OBJ)
	echo $(OBJ)
	echo $(ODIR)/Breakout.o

Breakout: $(OBJ)
	$(CC) -o Breakout $^ $(CFLAGS)

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm $(OUT) $(ODIR)/*.o

