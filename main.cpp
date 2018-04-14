#include "rctank.h"
#include <iostream>

int main(){
    if(gpioInitialise() < 0){ //initialize failed
	return 1; 
    }
    
    DcMotor motorL(5, 6);
    DcMotor motorR(13,19);
    int voltage_level = 5; // 0 ~ 10
    int mode;

    while(mode != 5){
	std::cout << "0:STOP 1:FORWARD 2:BACKWARD 3:CW 4:CCW 5:Terminate" << std::endl;
	std::cin >> mode;
	if( (mode == 0) || (mode == 5) ){
	    ChangeDriveMode(STOP, voltage_level, motorL, motorR);
	}
	else if(mode == 1){
	    ChangeDriveMode(FORWARD, voltage_level, motorL, motorR);
	}
	else if(mode == 2){
	    ChangeDriveMode(BACKWARD, voltage_level, motorL, motorR);
	}
	else if(mode == 3){
	    ChangeDriveMode(CW, voltage_level, motorL, motorR);
	}
	else if(mode == 4){
	    ChangeDriveMode(CCW, voltage_level, motorL, motorR);
	}
    }
    gpioTerminate();
    return 0;
}
    
    


