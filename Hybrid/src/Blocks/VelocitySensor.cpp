#include "Blocks/VelocitySensor.h"

using namespace ELCT350::Hybrid::Blocks;

VelocitySensor::VelocitySensor()
              : SimulationBlock(0),
                MnaBlock(1),
                SignalBlock(0, 1)
{
}

void VelocitySensor::mnaStep(double timeStep, double time)
{
}

void VelocitySensor::signalStep(double timeStep, double time)
{
  setOutputPortValue(Velocity, getAcross(S));
}