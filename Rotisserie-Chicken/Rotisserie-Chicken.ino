/*******************************************************************************
*
* FILE: 
* 		Rotisserie-Chicken.ino
*
* DESCRIPTION: 
* 		Body tube epoxy drying firmware (MISSION-CRITICAL).
*
*******************************************************************************/

/*------------------------------------------------------------------------------
 Static Constants
------------------------------------------------------------------------------*/

const int motorDirectionPin = 13; // for motor A
const int motorSpeedPin = 11; // for motor A
const int motorBrakePin = 9; // for motor A

const int CW  = HIGH;
const int CCW = LOW;

int motorSpeed = 200;
int initMotorSpeed = 255;

long int current_time, start_time;

/*------------------------------------------------------------------------------
 Procedures
------------------------------------------------------------------------------*/

/*******************************************************************************
*                                                                              *
* PROCEDURE:                                                                   * 
* 		setup                                                                    *
*                                                                              *
* DESCRIPTION:                                                                 * 
* 		Configure pinouts and perform initialization.                            *
*                                                                              *
*******************************************************************************/
void setup
    (
    void
    ) 
{
/* motor A pin assignment */
pinMode(motorDirectionPin, OUTPUT);
pinMode(motorSpeedPin, OUTPUT);
pinMode(motorBrakePin, OUTPUT);

digitalWrite(motorDirectionPin, CW); /* set direction */
analogWrite(motorSpeedPin, initMotorSpeed); /* set speed at maximum */
delay(100);


Serial.begin(9600); /* initialize serial monitor */
start_time = millis();

} /* setup */


/*******************************************************************************
*                                                                              *
* PROCEDURE:                                                                   * 
* 		loop                                                                     *
*                                                                              *
* DESCRIPTION:                                                                 * 
* 		Core logic for the rotisserie chicken assembly.                          *
*                                                                              *
*******************************************************************************/
void loop
    (
    void
    ) 
{

current_time = millis() - start_time;
if( current_time <= 7200000 )
    {
    digitalWrite(motorDirectionPin, CW); /* set direction */
    analogWrite(motorSpeedPin, motorSpeed); /* set speed at maximum */
    delay(500);
    analogWrite(motorSpeedPin, motorSpeed); /* set speed at maximum */
    analogWrite(motorSpeedPin, 0); /* set speed at maximum */
    delay(10000);
    } /* if( current_time <= 7200000 ) */
    
} /* loop */
