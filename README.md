# Nevermore
This project is an example of how to optimize an Animation Blueprint.

The project contains a non-optimized animation blueprint `ABP_Manny` that uses only blueprints.
Also, the project contains an optimized animation blueprint `ABP_Manny_Native` that uses native class `UMannyAnimInstance`.

The class `UMannyAnimInstance` uses a structure `FMannyAnimInstanceProxy` to support a thread-safe parallel evaluation of the animation blueprint logic.
`UMannyAnimInstance` also implements methods that are evaluated only when they're needed by animation graph, as example `GetGroundSpeed` is used only when a character is playing locomoting animation. 

Please first take a look at the implementation of `UMannyAnimInstance` with `FMannyAnimInstanceProxy` and then take a look at how they're used in `ABP_Manny_Native`.

For a better understanding of the difference between `ABP_Manny` and `ABP_Manny_Native`, I recommend comparing their evaluation times in Unreal Insights.

Best wishes,
Kirill
