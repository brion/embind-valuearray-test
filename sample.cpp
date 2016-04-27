#include <emscripten/emscripten.h>
#include <emscripten/bind.h>

using namespace emscripten;

struct Point2f {
    float x;
    float y;
};

Point2f samplePoint {16.0f, 9.0f};

Point2f getPoint2fVal() {
  return samplePoint;
}

Point2f* getPoint2fPtr() {
  return &samplePoint;
}

Point2f* getPoint2fNull() {
  return nullptr; // JS value: [3.5733110840282835e-43, 0]
}

//...
EMSCRIPTEN_BINDINGS(Foo) {
	value_array<Point2f>("Point2f")
		.element(&Point2f::x)
		.element(&Point2f::y);
	function("getPoint2fVal", &getPoint2fVal);
	function("getPoint2fPtr", &getPoint2fPtr);
	function("getPoint2fNull", &getPoint2fNull);
}
