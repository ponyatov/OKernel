MODULE = Piumarta

$(MODULE).log: $(MODULE).src ./$(MODULE).exe
	./$(MODULE).exe < $< > $@ && tail $(TAIL) $@

C = src/Piumarta.cpp
H = src/Piumarta.hpp
$(MODULE).exe: $(C) $(H)
	$(CXX) -o $@ $(C)
