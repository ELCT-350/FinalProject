#include "VelocitySensor.h"

using namespace ELCT350::Hybrid;

#pragma region Constructors
VelocitySensor::VelocitySensor()
              : SimulationBlock(0), SignalBlock(0, 1), MnaBlock(1)
{
}
#pragma endregion

#pragma region SignalBlock
void VelocitySensor::updateSignal(double timeStep, double time)
{
  setOutputPortValue(Velocity, getAcross(Shaft));
}
#pragma endregion

#pragma region MnaBlock
void VelocitySensor::updateMna(double timeStep, double time, bool nrIteration)
{
}
#pragma endregion