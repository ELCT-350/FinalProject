#pragma once
#include "SignalBlock.h"

namespace ELCT350
{
    namespace Signal
    {
        namespace Blocks
        {
            class Add : public SignalBlock
            {
            public:
                enum InputPorts : size_t
                {
                    Input1, Input2
                };

                enum OutputPorts : size_t
                {
                    Output
                };

                Add();

                virtual void signalStep(double timeStep, double time) override;
            };
        }
    }
}