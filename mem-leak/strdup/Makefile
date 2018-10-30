CFLAGS+= -DWITH_DBG_STRDUP
MEMDIR:=../3rd/memleak-0.3.1/
OBJ=$(MEMDIR)memleak.o strdup-mem-leak.o
BIN=strdup-memleak

INCDIR := -I. -I$(MEMDIR)

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCDIR) $< -o $@

clean:
	$(RM) $(OBJ) $(BIN)
