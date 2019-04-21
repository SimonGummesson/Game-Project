#pragma once
#ifndef COMPONENT_TYPES_H
#define COMPONENT_TYPES_H

// create new components here and add them to the variant below

struct PositionComponent
{
	PositionComponent() {};
	float x, y, z;
	PositionComponent(float x, float y, float z) : x(x), y(y), z(z) {};
};
struct ColorComponent
{
	ColorComponent() {};
	float r, g, b, a;
	ColorComponent(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}
};

using ComponentTypes = std::variant<
	PositionComponent,
	ColorComponent>;

#endif
