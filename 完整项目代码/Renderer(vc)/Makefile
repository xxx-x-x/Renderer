main: main.o my_tools.o my_triangle.o my_math.o
	g++ -o main main.o my_tools.o my_triangle.o my_math.o -lgdi32
	del *.o
main.o:
	g++ -o main.o -c ./main.cpp 
my_tools.o:
	g++ -o my_tools.o -c ./my_tools/my_tools.cpp
my_triangle.o:
	g++ -o my_triangle.o  -c ./my_models/my_triangle.cpp
my_math.o:
	g++ -o my_math.o -c ./my_math/my_math.cpp

