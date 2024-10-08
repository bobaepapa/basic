CC:=gcc
LD:=ld
RM:=rm

ifeq ($(shell uname -s), Darwin)
	LDOPTIONS=-Wl,-map,$(TARGET).map
else
	LDOPTIONS=-Xlinker -Map=$(TARGET).map
endif

#OBJS:= $(patsubst %.c,%.o,$(wildcard *.c))
#TARGET:= $(basename $(OBJS))

OBJS := logging.o

OBJS += singleton-safe.o singleton-main.o
#OBJS += function-ptr.o
#OBJS += log_debug.o
#OBJS += flash-main.o flash-layer.o
#OBJS += struct.o
#OBJS += overflow.o
#OBJS += hexdump.o
# OBJS += sizeof.o
#OBJS += switch.o
#OBJS += array.o
#OBJS += func-ptrs.o func-body.o
# OBJS += string.o
#OBJS += pointer.o
# OBJS += char-pointer.o
#OBJS += calling.o
#OBJS += boolean.o
#OBJS += memcmp.o
#OBJS += iso8601.o
# OBJS += strlen.o
#OBJS += typedef_p.o
#OBJS += macro.o
#OBJS += float_to_byte.o
# OBJS += print.o
# OBJS += gen_buf.o
 

TARGET:=run

$(TARGET): $(OBJS)
	@echo Builing... $(TARGET)
	$(CC) -o $@ $^ $(LDOPTIONS)

clean:
	@echo Cleaning... $(TARGET) $(OBJS)
	$(RM) -f $(TARGET) $(OBJS) $(TARGET).map *.o

clang:
	@echo Code Formatting... $(wildcard *.c) $(wildcard *.h)
	@find -E . -regex '.+\.[ch]' -exec clang-format -style file -i {} \;
		
%o: %c
	@$(CC) -c $< 

test:
	@echo '"Hello Hi"'

.PHONY: clean

