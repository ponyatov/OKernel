
MODULE ?= Piumarta

$(MODULE).log: $(MODULE).src ./$(MODULE).exe
	./$(MODULE).exe < $< > $@ && tail $(TAIL) $@

C = src/$(MODULE).cpp
H = src/$(MODULE).hpp

C += $(MODULE).tab.cpp
H += $(MODULE).tab.hpp
$(MODULE).tab.cpp $(MODULE).tab.hpp: src/$(MODULE).ypp
	bison $<

C += lex.yy.c
lex.yy.c: src/$(MODULE).lpp
	flex $<

CXXFLAGS += -I. -I./src

./$(MODULE).exe: $(C) $(H)
	$(CXX) $(CXXFLAGS) -o $@ $(C)

