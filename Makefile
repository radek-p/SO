.PHONY: all clean

SRCS := $(wildcard ex*.c)
OBJS := $(SRCS:%.c=%.o)

all: ${OBJS}

%.o: %.c
	@echo "Creating object file $<..."
	gcc -c -Wall -Wextra -O2 -fno-omit-frame-pointer $<

clean:
	@echo "Cleaning up .o files..."
	rm *.o