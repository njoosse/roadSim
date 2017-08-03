#include <iostream>
#include <math.h>

// http://www.engineeringtoolbox.com/car-acceleration-d_1309.html

float laneWidth = 3.5; // metres
float speedLimit = 50.0; // km/h
float acceleration = 3.0; // m/s^2
// assuming 1500kg car from 0-50km/h over 5 seconds
float lagTime = 0.564;  // seconds between car ahead moving and car moving
                        // also light turning green and first car accelerating
                        // 2* average human visual reaction time from
                        // humanbenchmark.com/tests/reactiontime/statistics

float kmph2mps(float kmph)
{
    return kmph/3.6;
}

float distance2MaxSpeed(float initialVelocity)
{
    float seconds = (kmph2mps(speedLimit) - initialVelocity)/acceleration;
    return 0.5*acceleration*pow(seconds, 2.0);
}

float Time2TravelDistwAccel(float distance)
{
    return sqrt((2*distance)/acceleration);
}

class Automobile
{
    public:
        float length = 4.7;
        char heading = 'N';
        int lastIX = 1;
        int nextIX = 2;
};

class Intersection
{
    int lanes1, lanes2;
    public:
        Intersection(int,int);
        float width1, width2;
        float travelTime(int laneSet)
        {
            if (laneSet == 1)
            {
                return width1/kmph2mps(speedLimit);
            }
            else
            {
                return width2/kmph2mps(speedLimit);
            }
        }
};

Intersection::Intersection(int lanes1, int lanes2)
{
    width1 = (laneWidth*lanes1);
    width2 = (laneWidth*lanes2);
}

int main()
{
    Intersection ix (3, 4);
    Intersection ix1 (4,4);
    Intersection ix2 (5,3);
    std::cout << "Test 1: Travelling and Speed Limit" << std::endl;
    std::cout << "Travel Time: " << ix.travelTime(1) << " seconds" << std::endl;
    std::cout << "Test 2: Travelling From Stopped" << std::endl;
    std::cout << "Travel Time: " << Time2TravelDistwAccel(10.5) << " seconds" << std::endl;
    return 0;
}
