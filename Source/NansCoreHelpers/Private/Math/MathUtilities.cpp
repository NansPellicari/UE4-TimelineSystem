//  Copyright 2020-present Nans Pellicari (nans.pellicari@gmail.com).
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "Math/MathUtilities.h"

FZoneBox::FZoneBox()
{
	Origin = FVector::ZeroVector;
	Extent = FVector::ZeroVector;
	Rotation = FRotator::ZeroRotator;
}

FBox FZoneBox::GetBox() const
{
	return FBox(Origin - Extent, Origin + Extent);
}

FBox FZoneBox::GetBoundingBox() const
{
	FOrientedBox OBB = GetOrientedBox();
	FVector Vertices[8];
	OBB.CalcVertices(Vertices);
	FBox Box = FBox(Vertices, 8);
	return Box;
}

FSphere FZoneBox::GetSphere() const
{
	return FSphere(Origin, Extent.GetMax());
}

FSphere FZoneBox::GetSphereXY() const
{
	FVector OToE = Origin + FVector(Extent.X, Extent.Y, 0);
	FVector OToEOpposite = Origin - FVector(-Extent.X, Extent.Y, 0);
	FVector MiddlePoint = (OToEOpposite + OToE) / 2;
	float W = (Origin - MiddlePoint).Size();
	FSphere Sphere(Origin, W);
	return Sphere;
}

FOrientedBox FZoneBox::GetOrientedBox() const
{
	return NGeometry::CreateOrientedBox(GetBox(), Rotation);
}

bool FZoneBox::Intersect(const FZoneBox& Other) const
{
	// Sphere is the bigger volume, so it's require to test it first
	if (Other.CollideOn == EZoneCollider::Sphere)
	{
		return Intersect(Other.GetSphere());
	}

	// Try first the Bounding box cause all other volumes are inner bounding box
	if (!GetBoundingBox().Intersect(Other.GetBoundingBox())) return false;

	if (Other.CollideOn == EZoneCollider::AAB)
	{
		return Intersect(Other.GetBox());
	}
	if (Other.CollideOn == EZoneCollider::OBB)
	{
		return Intersect(Other.GetOrientedBox());
	}
	if (Other.CollideOn == EZoneCollider::SphereXY)
	{
		return Intersect(Other.GetSphereXY());
	}

	return false;
}

bool FZoneBox::Intersect(const FSphere& Other) const
{
	if (CollideOn == EZoneCollider::Sphere)
	{
		return GetSphere().Intersects(Other);
	}
	if (CollideOn == EZoneCollider::SphereXY)
	{
		return GetSphereXY().Intersects(Other);
	}
	if (CollideOn == EZoneCollider::AAB)
	{
		return FMath::SphereAABBIntersection(Other, GetBox());
	}
	if (CollideOn == EZoneCollider::OBB)
	{
		return NGeometry::Intersects(GetOrientedBox(), Other);
	}
	return false;
}

bool FZoneBox::Intersect(const FBox& Other) const
{
	if (CollideOn == EZoneCollider::Sphere)
	{
		return FMath::SphereAABBIntersection(GetSphere(), Other);
	}
	if (CollideOn == EZoneCollider::SphereXY)
	{
		return FMath::SphereAABBIntersection(GetSphereXY(), Other);
	}
	if (CollideOn == EZoneCollider::AAB)
	{
		return GetBox().Intersect(Other);
	}
	if (CollideOn == EZoneCollider::OBB)
	{
		return NGeometry::Intersects(Other, GetOrientedBox());
	}
	return false;
}

bool FZoneBox::Intersect(const FOrientedBox& Other) const
{
	if (CollideOn == EZoneCollider::Sphere)
	{
		return NGeometry::Intersects(Other, GetSphere());
	}
	if (CollideOn == EZoneCollider::SphereXY)
	{
		return NGeometry::Intersects(Other, GetSphereXY());
	}
	if (CollideOn == EZoneCollider::AAB)
	{
		return NGeometry::Intersects(GetBox(), Other);
	}
	if (CollideOn == EZoneCollider::OBB)
	{
		return NGeometry::Intersects(GetOrientedBox(), Other);
	}
	return false;
}

FVector NMathUtilities::GetClosestCorner(
	int32 SideToTest, const FZoneBox& Box, const TCorners& CornerData, ELateralityOrientation& Side, bool bDebug)
{
	FVector ClosestCorner;

	if (SideToTest & Left && SideToTest & Right)
	{
		float LeftDist = (Box.Origin - CornerData[0]).Size();
		float RightDist = (Box.Origin - CornerData[1]).Size();
		Side = LeftDist < RightDist ? Left : Right;
		ClosestCorner = LeftDist < RightDist ? CornerData[0] : CornerData[1];
		if (bDebug) UE_LOG(LogTemp, Warning, TEXT("%s - corner on  both"), ANSI_TO_TCHAR(__FUNCTION__));
	}
	else if (SideToTest & Left)
	{
		ClosestCorner = CornerData[0];
		Side = Left;
		if (bDebug) UE_LOG(LogTemp, Warning, TEXT("%s - corner on left"), ANSI_TO_TCHAR(__FUNCTION__));
	}
	else
	{
		ClosestCorner = CornerData[1];
		Side = Right;
		if (bDebug) UE_LOG(LogTemp, Warning, TEXT("%s - corner on right"), ANSI_TO_TCHAR(__FUNCTION__));
	}
	return ClosestCorner;
};

FVector2D NMathUtilities::FindCentroid(const TArray<FVector2D> Positions)
{
	FVector2D centroid;
	FVector2D MinPoint = Positions[0];
	FVector2D MaxPoint = Positions[0];

	for (FVector2D Pos : Positions)
	{
		if (Pos.X < MinPoint.X) MinPoint.X = Pos.X;
		if (Pos.X > MaxPoint.X) MaxPoint.X = Pos.X;
		if (Pos.Y < MinPoint.Y) MinPoint.Y = Pos.Y;
		if (Pos.Y > MaxPoint.Y) MaxPoint.Y = Pos.Y;
	}

	centroid = MinPoint + 0.5f * (MaxPoint - MinPoint);

	return centroid;
}

bool NGeometry::Intersect(FIntRect Rect1, FIntRect Rect2, bool bOnSideToSide)
{
	if (bOnSideToSide)
	{
		if ((Rect1.Min.X > Rect2.Max.X) || (Rect2.Min.X > Rect1.Max.X))
		{
			return false;
		}

		if ((Rect1.Min.Y > Rect2.Max.Y) || (Rect2.Min.Y > Rect1.Max.Y))
		{
			return false;
		}
	}
	else
	{
		if ((Rect1.Min.X >= Rect2.Max.X) || (Rect2.Min.X >= Rect1.Max.X))
		{
			return false;
		}

		if ((Rect1.Min.Y >= Rect2.Max.Y) || (Rect2.Min.Y >= Rect1.Max.Y))
		{
			return false;
		}
	}

	return true;
}

FIntRect NGeometry::UnionOnIntersect(TArray<FIntRect> Rects, bool bDebug)
{
	Rects.Sort(
		[](const FIntRect& LH, const FIntRect& RH)
		{
			return LH.Min.X <= RH.Min.X;
		}
	);

	FIntRect TotalArea;
	for (auto& Rect : Rects)
	{
		if (TotalArea.Min == FIntPoint(0, 0) && TotalArea.Max == FIntPoint(0, 0))
		{
			TotalArea = Rect;
		}
		else
		{
			TotalArea.Union(Rect);
		}
		// std::cout << "Rect: " << TCHAR_TO_ANSI(*Rect.ToString()) << "\n";
	}

	// std::cout << "TotalArea: " << TCHAR_TO_ANSI(*TotalArea.ToString()) << "\n";

	FIntRect OutRect;
	for (int32 Y = 1; Y <= TotalArea.Max.Y; ++Y)
	{
		int32 StartX = -1;
		int32 EndX = 0;
		for (auto& Rect : Rects)
		{
			if (Rect.Min.Y < Y && Rect.Max.Y >= Y)
			{
				if (StartX == -1)
				{
					StartX = Rect.Min.X;
				}

				// Means there is a gap between 2 blocks, so they are not contiguous and can't be merged 
				if (EndX > 0 && Rect.Min.X > EndX)
				{
					StartX = -1;
					EndX = 0;
					break;
				}
				EndX = Rect.Max.X;
			}
		}

		// Find a way to use std::cout for Engine
		// if (bDebug)
		// {
		// 	FString Row;
		// 	int32 PositionOnX = 0;
		// 	int32 RectIdx = 0;
		// 	for (auto& Rect : Rects)
		// 	{
		// 		if (Rect.Min.Y < Y && Rect.Max.Y >= Y)
		// 		{
		// 			FString Col;
		// 			if (Rect.Min.X > PositionOnX)
		// 			{
		// 				for (int32 B = 0; B < Rect.Min.X - PositionOnX; ++B)
		// 				{
		// 					Col.Append(TEXT(" |"));
		// 				}
		// 			}
		// 			PositionOnX = Rect.Max.X;
		// 			for (int32 B = 0; B < Rect.Max.X - Rect.Min.X; ++B)
		// 			{
		// 				Col.Append(*FString::FromInt(RectIdx));
		// 				Col.Append("|");
		// 			}
		// 			Row.Append(Col);
		// 		}
		// 		RectIdx++;
		// 	}
		// 	if (PositionOnX < TotalArea.Max.X)
		// 	{
		// 		for (int32 B = 0; B < TotalArea.Max.X - PositionOnX; ++B)
		// 		{
		// 			Row.Append(TEXT(" |"));
		// 		}
		// 	}
		//
		// 	std::cout << "|" << TCHAR_TO_ANSI(*Row);
		// 	std::cout << " \n";
		// }

		if (StartX == -1 && EndX == 0)
		{
			// Means no contiguous rectangles
			continue;
		}

		FIntRect NewLineRect(
			FIntPoint(StartX, Y - 1),
			FIntPoint(EndX, Y)
		);
		// std::cout << "StartX : " << StartX << "\n";
		// std::cout << "EndX   : " << EndX << "\n";
		if (OutRect.Min.X == 0 && OutRect.Max.Y == 0)
		{
			OutRect = NewLineRect;
		}
		else
		{
			FIntRect IntersectLineRect = UnionOnIntersect(OutRect, NewLineRect);
			if (IntersectLineRect.Area() > OutRect.Area())
			{
				OutRect = IntersectLineRect;
			}
		}
		// std::cout << "OutRect " << Y << ": " << TCHAR_TO_ANSI(*OutRect.ToString()) << "\n";
	}
	return OutRect;
}

FIntRect NGeometry::UnionOnIntersect(FIntRect Rect1, FIntRect Rect2)
{
	FIntRect RectOut;
	if (Rect1.Max.X <= Rect2.Min.X || Rect2.Max.X <= Rect1.Min.X)
	{
		RectOut.Min.X = FMath::Min<int32>(Rect1.Min.X, Rect2.Min.X);
		RectOut.Min.Y = FMath::Max<int32>(Rect1.Min.Y, Rect2.Min.Y);
		RectOut.Max.X = FMath::Max<int32>(Rect1.Max.X, Rect2.Max.X);
		RectOut.Max.Y = FMath::Min<int32>(Rect1.Max.Y, Rect2.Max.Y);
	}
	else
	{
		RectOut.Min.X = FMath::Max<int32>(Rect1.Min.X, Rect2.Min.X);
		RectOut.Min.Y = FMath::Min<int32>(Rect1.Min.Y, Rect2.Min.Y);
		RectOut.Max.X = FMath::Min<int32>(Rect1.Max.X, Rect2.Max.X);
		RectOut.Max.Y = FMath::Max<int32>(Rect1.Max.Y, Rect2.Max.Y);
	}

	return RectOut;
}

bool NGeometry::Intersects(const FBox& AABB, const FOrientedBox& OBB)
{
	// Thanks to this: https://github.com/gszauer/GamePhysicsCookbook/blob/master/Code/Geometry3D.cpp
	FVector O[8];
	OBB.CalcVertices(O);

	FVector Test[15] = {FVector(1, 0, 0), FVector(0, 1, 0), FVector(0, 0, 1), O[0], O[1], O[2]};

	for (int I = 0; I < 3; ++I)
	{
		// Fill out rest of axis
		Test[6 + I * 3 + 0] = FVector::CrossProduct(Test[I], Test[0]);
		Test[6 + I * 3 + 1] = FVector::CrossProduct(Test[I], Test[1]);
		Test[6 + I * 3 + 2] = FVector::CrossProduct(Test[I], Test[2]);
	}

	for (int I = 0; I < 15; ++I)
	{
		if (!OverlapOnAxis(AABB, OBB, Test[I]))
		{
			return false; // Seperating axis found
		}
	}

	return false;
}

FVector NGeometry::ClosestPoint(const FOrientedBox& OBB, const FVector& Point)
{
	FVector Result = OBB.Center;
	FVector Dir = Point - OBB.Center;
	float Size[3] = {OBB.ExtentX, OBB.ExtentY, OBB.ExtentZ};
	FVector Axis[3] = {OBB.AxisX, OBB.AxisY, OBB.AxisZ};

	for (int i = 0; i < 3; ++i)
	{
		float Distance = FVector::DotProduct(Dir, Axis[i]);

		if (Distance > Size[i])
		{
			Distance = Size[i];
		}
		if (Distance < -Size[i])
		{
			Distance = -Size[i];
		}

		Result = Result + (Axis[i] * Distance);
	}

	return Result;
}

bool NGeometry::Intersects(const FOrientedBox& OBB, const FSphere& Sphere)
{
	FVector ClosestPoint = NGeometry::ClosestPoint(OBB, Sphere.Center);
	float DistSq = (Sphere.Center - ClosestPoint).SizeSquared();
	float RadiusSq = Sphere.W * Sphere.W;
	return DistSq < RadiusSq;
}

bool NGeometry::Intersects(const FOrientedBox& OBB1, const FOrientedBox& OBB2)
{
	FVector O1[8];
	FVector O2[8];
	OBB1.CalcVertices(O1);
	OBB2.CalcVertices(O2);

	FVector Test[15] = {O1[0], O1[1], O1[2], O2[0], O2[1], O2[2]};

	// Or test this:
	// // // FVector Test[15] = {OBB1.AxisX, OBB1.AxisY, OBB1.AxisZ, OBB2.AxisX, OBB2.AxisY, OBB2.AxisZ};

	for (int I = 0; I < 3; ++I)
	{
		// Fill out rest of axis
		Test[6 + I * 3 + 0] = FVector::CrossProduct(Test[I], Test[0]);
		Test[6 + I * 3 + 1] = FVector::CrossProduct(Test[I], Test[1]);
		Test[6 + I * 3 + 2] = FVector::CrossProduct(Test[I], Test[2]);
	}

	for (int I = 0; I < 15; ++I)
	{
		if (!OverlapOnAxis(OBB1, OBB2, Test[I]))
		{
			return false; // Seperating axis found
		}
	}

	return false;
}

bool NGeometry::OverlapOnAxis(const FOrientedBox& OBB1, const FOrientedBox& OBB2, const FVector& Axis)
{
	FFloatInterval A = OBB1.Project(Axis);
	FFloatInterval B = OBB2.Project(Axis);
	return ((B.Min <= A.Max) && (A.Min <= B.Max));
}

bool NGeometry::OverlapOnAxis(const FBox& AABB, const FOrientedBox& OBB, const FVector& Axis)
{
	FFloatInterval A = GetInterval(AABB, Axis);
	FFloatInterval B = OBB.Project(Axis);
	return ((B.Min <= A.Max) && (A.Min <= B.Max));
}

FFloatInterval NGeometry::GetInterval(const FBox& AABB, const FVector& Axis)
{
	TArray<FVector> Vertices = GetVertices(AABB);
	FFloatInterval ProjectionInterval;

	for (int i = 1; i < 8; ++i)
	{
		ProjectionInterval.Include(FVector::DotProduct(Axis, Vertices[i]));
	}

	return ProjectionInterval;
}

TArray<FVector> NGeometry::GetVertices(const FBox& AABB)
{
	TArray<FVector> Vertices = {
		FVector(AABB.Min),
		FVector(AABB.Min.X, AABB.Min.Y, AABB.Max.Z),
		FVector(AABB.Min.X, AABB.Max.Y, AABB.Min.Z),
		FVector(AABB.Max.X, AABB.Min.Y, AABB.Min.Z),
		FVector(AABB.Max.X, AABB.Max.Y, AABB.Min.Z),
		FVector(AABB.Max.X, AABB.Min.Y, AABB.Max.Z),
		FVector(AABB.Min.X, AABB.Max.Y, AABB.Max.Z),
		FVector(AABB.Max)
	};
	return Vertices;
}

FOrientedBox NGeometry::CreateOrientedBox(const FBox& AABB, const FRotator& Rot)
{
	FOrientedBox OBB;
	OBB.Center = AABB.GetCenter();
	OBB.ExtentX = AABB.GetExtent().X;
	OBB.ExtentY = AABB.GetExtent().Y;
	OBB.ExtentZ = AABB.GetExtent().Z;
	FQuat Quat = Rot.Quaternion();
	OBB.AxisX = Quat.GetAxisX();
	OBB.AxisY = Quat.GetAxisY();
	OBB.AxisZ = Quat.GetAxisZ();
	return OBB;
}
