main: main.o my_tools.o my_math.o face.o wavefront_obj.o wavefront_obj_parser.o 
	g++ -o main main.o my_tools.o my_math.o face.o wavefront_obj.o wavefront_obj_parser.o -lgdi32
	del *.o
parse: face.o wavefront_obj.o wavefront_obj_parser.o my_math.o 
	g++ -o parse ./obj_parser/test.cpp face.o wavefront_obj.o wavefront_obj_parser.o my_math.o
	del *.o
main.o:
	g++ -o main.o -c ./main.cpp 
my_tools.o:
	g++ -o my_tools.o -c ./my_tools/my_tools.cpp

my_math.o:
	g++ -o my_math.o -c ./my_math/my_math.cpp
face.o:
	g++ -o face.o -c ./my_models/face.cpp
wavefront_obj.o:
	g++ -o wavefront_obj.o -c ./my_models/wavefront_obj.cpp
wavefront_obj_parser.o:
	g++ -o wavefront_obj_parser.o -c ./obj_parser/wavefront_obj_parser.cpp