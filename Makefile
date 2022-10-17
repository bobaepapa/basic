CC:=gcc
LD:=ld
RM:=rm
ifeq ($(shell uname -s), Darwin)
	LDOPTIONS=-Wl,-map,$(TARGET).map
else
	LDOPTIONS=-Xlinker -Map=$(TARGET).map
endif

#OBJS:= $(patsubst %.c,%.o,$(wildcard *.c))

#OBJS:= singleton-safe.o main.o
#OBJS:= function-ptr.o
OBJS:= log_debug.o

TARGET:= $(basename $(OBJS))

$(TARGET): $(OBJS)
	@echo Builing... $(TARGET)
	@$(CC) -o $@ $^ $(LDOPTIONS)

clean:
	@echo Cleaning... $(TARGET) $(OBJS)
	@$(RM) -f $(TARGET) $(OBJS) $(TARGET).map

%o: %c
	@$(CC) -c $< 

.PHONY: clean

