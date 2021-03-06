#include <pigpio.h>

typedef enum{
    STOP,
    FORWARD,
    BACKWARD,
    CW,
    CCW
}Mode;
    
class DcMotor
{
 public:
    DcMotor(int, int);
    ~DcMotor();
    void pwmWrite(double);

 private:
    int pin1;
    int pin2;
};

void ChangeDriveMode(Mode, int, DcMotor, DcMotor); 

    
