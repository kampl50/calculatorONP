CPPFLAGS=-IM:\CB\wxWidgets-3.0.4\include -IM:\CB\wxWidgets-3.0.4\lib\gcc_lib\mswud
LDFLAGS=-LM:\CB\wxWidgets-3.0.4\lib\gcc_lib -LM:\CB\CodeBlocks\minGW\lib
LDLIBS=-lwxmsw30ud -lwxpngd -lwxjpegd -lwxtiffd -lwxzlibd -lgdi32 -lcomctl32 -lcomdlg32 -lwinspool -lole32 -loleAut32 -luuid
CC=g++
SRC=calculator.cpp KALKULATORApp.cpp KALKULATORMain.cpp stack.cpp
OBJS=$(subst .cpp,.o,$(SRC))
 
all: KALKULATOR
clean:
	rm KALKULATOR
	rm $(OBJS)
%.o: %.c
	$(CC) $(CPPFLAGS) -c $<
 
KALKULATOR: $(OBJS)
	$(CC) $(LDFLAGS)  $(OBJS) -o KALKULATOR $(LDLIBS)
	