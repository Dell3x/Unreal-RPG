#pragma once

#include "DrawDebugHelpers.h"

#define DRAW_SPHERE(Location, Color) if(GetWorld()) DrawDebugSphere(GetWorld(), Location, 100.f, 12, Color, true);
#define DRAW_SINGLEFRAMESPHERE(Location, Color) if(GetWorld()) DrawDebugSphere(GetWorld(), Location, 100.f, 12, Color, false, -1.f);
#define DRAW_LINE(ActorLocation, ForwardVector) if(GetWorld()) DrawDebugLine(GetWorld(),ActorLocation, ForwardVector, FColor::Red, true, -1.f, 0, 1.f);
#define DRAW_SINGLEFRAMELINE(ActorLocation, ForwardVector) if(GetWorld()) DrawDebugLine(GetWorld(),ActorLocation, ForwardVector, FColor::Red, false, -1.f, 0, 1.f);
#define DRAW_POINT(ForwardVector, Size) if(GetWorld()) DrawDebugPoint(GetWorld(),ForwardVector, Size, FColor::Red, true);
#define DRAW_SINGLEFRAMEPOINT(ForwardVector, Size) if(GetWorld()) DrawDebugPoint(GetWorld(),ForwardVector, Size, FColor::Red, false, -1.f);
#define DRAW_VECTOR(StartLocation, EndLocation, Size) if(GetWorld()) \
{\
DrawDebugLine(GetWorld(),ActorLocation, EndLocation, FColor::Red, true, -1.f, 0, 1.f);\
DrawDebugPoint(GetWorld(),EndLocation, Size, FColor::Red, true);\
}
#define DRAW_SINGLEFRAMEVECTOR(StartLocation, EndLocation, Size) if(GetWorld()) \
{\
DrawDebugLine(GetWorld(),ActorLocation, EndLocation, FColor::Red, false, -1.f, 0, 1.f);\
DrawDebugPoint(GetWorld(),EndLocation, Size, FColor::Red, false, -1.f);\
}\
