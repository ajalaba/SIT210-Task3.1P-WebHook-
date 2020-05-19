#include "HC_SR04.h"

double cm = 0.0;
double inches = 0.0;

int trigPin = D3;
int echoPin = D4;

HC_SR04 rangefinder = HC_SR04(trigPin, echoPin);

void setup() 
{
    Spark.variable("cm", &cm, DOUBLE);

}

void loop() 
{
    cm = rangefinder.getDistanceCM();
    Particle.publish("ultra", String(cm), PRIVATE);
    delay(10000);
}

