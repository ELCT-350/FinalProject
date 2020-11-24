#pragma once
#include "MnaBlock.h"
#include "MnaNode.h"
#include <set>

namespace ELCT350
{
  namespace Mna
  {
    class MnaSolver final
    {
    public:
      #pragma region Constructors
      MnaSolver(double timeStep);
      #pragma endregion

      #pragma region Modifiers
      //1. Update all blocks
      //2. Update your system jacobian and intercept matrices
      //   (no reference nodes)
      //3. Solve for across (voltages in electrical)
      //4. Set across in all nodes
      //5. Tell all blocks to update through values (currents)
      //6. Update time
      void step();

      //Add ports to the same node
      //Combine nodes if necessary
      //Add or remove nodes from system
      void connect(MnaBlock& block1, size_t portIndex1,
                   MnaBlock& block2, size_t portIndex2);
      #pragma endregion

      #pragma region Observers
      //Gets the current time within this solver
      double getTime() const;
      #pragma endregion
    private:
      #pragma region Constants
      const double _timeStep;
      #pragma endregion

      #pragma region Variables
      double _time;
      std::set<MnaBlock*> _blocks;
      std::set<MnaNode*> _nodes;
      #pragma endregion
    };
  }
}