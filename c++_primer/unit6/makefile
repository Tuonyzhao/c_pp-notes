EXE=main
CXX_SOURCES=$(wildcard *.cpp)
CXX_OBJECTS=$(patsubst %.cpp,%.o,$(CXX_SOURCES))
DEP_FILES  =$(patsubst %.o,%.d,$(CXX_OBJECTS))

$(EXE):$(CXX_OBJECTS)
	g++ $(CXX_SOURCES) -o $(EXE)

%.o:%.cpp
	g++ -c -MMD $< -o $@

-include $(DEP_FILES)

clean:
	rm *.o *.d $(EXE)

test:
	echo $(CXX_OBJECTS)
