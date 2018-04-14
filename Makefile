rctank: rctank.cpp main.cpp
	g++ -Wall -pthread -o rctank rctank.cpp main.cpp -lpigpio -lrt  
