#include "Object3d.h"
#include "Miniball.hpp"

BoundingSphere::BoundingSphere(const vector<Vector3>& vertices) {
	if (vertices.empty()) {
		BoundingSphere::BoundingSphere();
		return;
	}

	// Convert vertices to list of coordinates
	list<vector<float>> lp;
	for (int i = 0; i < vertices.size(); ++i) {
		vector<float> p(3);
		p[0] = vertices[i].x;
		p[1] = vertices[i].y;
		p[2] = vertices[i].z;
		lp.push_back(p);
	}

	// Create an instance of Miniball
	Miniball::Miniball < Miniball::CoordAccessor
		< list<vector<float>>::const_iterator,
		vector<float>::const_iterator >>
		mb(3, lp.begin(), lp.end());

	const float* pCenter = mb.center();
	center.x = pCenter[0];
	center.y = pCenter[1];
	center.z = pCenter[2];

	radius = sqrt(mb.squared_radius());
}
