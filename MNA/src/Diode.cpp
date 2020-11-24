#include "Diode.h"

using namespace ELCT350::Mna;

const double CONVERGENCE_TYPE_VOLTAGE_THRESHOLD = 0.75;
const double MINIMUM_EQUIVALENT_CONDUCTANCE = 1e-12;

Diode::Diode()
     : SimulationBlock(3), MnaBlock(2)
{
}

void Diode::updateMna(double timeStep, double time, bool nrIteration)
{
  double voltage = getAcross(Anode) - getAcross(Cathode);
	double current = getThrough(Anode);
  double saturationCurrent = getParameterValue(SaturationCurrent);
  double thermalVoltage = getParameterValue(IdealityFactor) * getParameterValue(ThermalVoltage);

  //During a minor iteration, it is possible to start with a highly unstable condition:
  //A high forward voltage and a small current.  Since this is impossible for a diode, we reset our guess
  //by giving us a new voltage and computing the current based on it
	if ((voltage > CONVERGENCE_TYPE_VOLTAGE_THRESHOLD) && (current <= saturationCurrent))
	{
		voltage = CONVERGENCE_TYPE_VOLTAGE_THRESHOLD;
	}
    
  if ((voltage <= CONVERGENCE_TYPE_VOLTAGE_THRESHOLD) || (current <= saturationCurrent))
	{
    //At low voltages or low currents, we'll try to compute the diode current and attempt to converge
		current = saturationCurrent * exp(voltage / thermalVoltage) - saturationCurrent;
	}
	else
	{
    //At high voltages and high currents, we'll try to compute the diode voltage and attempt to converge
		voltage = thermalVoltage * log(current / saturationCurrent + 1.0);
	}

  //Equivalent conductance is the ∂I/∂V value.  Found by:
  //I = Is*(e^(V/Vt) - 1)
  //I + Is = Is * e^(V/Vt)
  //(I + Is)/Is = e^(V/Vt)
  //ln((I + Is)/Is) = V/Vt
  //V = Vt*ln((I + Is)/Is)
  //
  //By the chain rule
  //∂V/∂I = [∂V/∂u]*[∂u/∂I] = [Vt*Is/(I + Is)]*[1/Is] = Vt/(I + Is)
  //∂I/∂V = (I + Is)/Vt
  double currentPlusSaturation = current + saturationCurrent;
  double jacobian = currentPlusSaturation / thermalVoltage;
  if (jacobian < MINIMUM_EQUIVALENT_CONDUCTANCE)
    jacobian = MINIMUM_EQUIVALENT_CONDUCTANCE;
  
  setJacobianValue(Anode, Anode, jacobian);
  setJacobianValue(Anode, Cathode, -jacobian);
  setJacobianValue(Cathode, Anode, -jacobian);
  setJacobianValue(Cathode, Cathode, jacobian);

  //The above equivalent conductance contributes to a portion of the current of the diode
  //when a voltage is applied.  The B-Equivalent contribution is found by subtracting
  //the desired diode current from the above contribution
  double intercept = voltage * jacobian - current;
  setInterceptValue(Anode, intercept);
  setInterceptValue(Cathode, -intercept);
}