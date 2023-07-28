#include "BoxCollider.h"
#include "Rigidbody.h"
#include "TinyMathLib/TinyMathLib.h"

BoxCollider::BoxCollider(Rigidbody* _rigidbody, float _xHalf, float _yHalf) {
	rb = _rigidbody;
	xHalf = _xHalf;
	yHalf = _yHalf;
}

void BoxCollider::OnCollision(Rigidbody other) {
	rb->actor->OnCollision(&other);

}

bool BoxCollider::CheckCollision(BoxCollider other) {
	if (TinyMathLib::Mathf::Abs(rb->position.x - other.rb->position.x) < xHalf + other.xHalf && TinyMathLib::Mathf::Abs(rb->position.y - other.rb->position.y) < yHalf + other.yHalf) {
		OnCollision(*other.rb);
		return true;
	}
	else return false;
}
