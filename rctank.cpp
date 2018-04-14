#include "rctank.h"

#define PWM_RANGE 255



DcMotor::DcMotor(int pinA, int pinB)
{
    pin1 = pinA;
    pin2 = pinB;
 
    gpioSetMode(pin1, PI_OUTPUT);
    gpioSetMode(pin2, PI_OUTPUT);
    gpioSetPWMrange(pin1, PWM_RANGE);
    gpioSetPWMrange(pin2, PWM_RANGE);  
}

DcMotor::~DcMotor()
{
  // gpioPWM(pin1, 0);
  // gpioPWM(pin2, 0);
}


void DcMotor::pwmWrite(double ratio)
{
    if(ratio > 1.0) ratio = 1.0; // saturation
    else if(ratio < -1.0) ratio = -1.0;

    if( (ratio < 0.01) && (ratio > -0.01) ){ // Stop
	gpioPWM(pin1, 0);
	gpioPWM(pin2, 0);
    }
    else if(ratio > 0){ // Nomal rotation
	gpioPWM(pin1, (int)(ratio * PWM_RANGE) );
	gpioPWM(pin2, 0);
    }
    else{ // Reverse rotation
	gpioPWM(pin1, 0);
	gpioPWM(pin2, (int)(-ratio * PWM_RANGE) );
    }
}



void ChangeDriveMode(Mode mode, int voltage_level, DcMotor motorL, DcMotor motorR)
{
    //voltage_level : 0 〜 10
    double r = ((double)voltage_level / 10);

    if(mode == STOP){
	motorL.pwmWrite(0.0);
	motorR.pwmWrite(0.0);
    }
    else if(mode == FORWARD){
	motorL.pwmWrite(r);
	motorR.pwmWrite(r);
    }
    else if(mode == BACKWARD){
	motorL.pwmWrite(-r);
	motorR.pwmWrite(-r);
    }
    else if(mode == CW){
	motorL.pwmWrite(r);
	motorR.pwmWrite(-r);
    }
    else if(mode == CCW){
	motorL.pwmWrite(-r);
	motorR.pwmWrite(r);
    }
}

    
    
