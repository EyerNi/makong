CC 			= 	gcc
TARGET 			= 	a.o
OBJ			=   c_generic_program_sample.o
CFLAGS  		=   -c -Wall -g
#
#
#
#
$(TARGET):	$(OBJ)
	$(CC) $(OBJ) -g -o $(TARGET)
#
#
#
#
c_generic_program_sample.o : src/c_generic_program_sample.c
	$(CC) src/c_generic_program_sample.c $(CFLAGS) -o c_generic_program_sample.o
#
#
#
#
.PHONY:	clean
clean:
	rm -r $(OBJ) $(TARGET)
