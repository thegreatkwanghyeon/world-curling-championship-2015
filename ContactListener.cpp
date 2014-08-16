#include "stdafx.h"
#include "ContactListener.h"

ContactListener::ContactListener()
{
	buffer.loadFromFile("sound/hit.wav");
	sound.setBuffer(buffer);
}

ContactListener::~ContactListener()
{

}

void ContactListener::BeginContract(b2Contact *contact)
{

}
void ContactListener::EndContact(b2Contact *contact)
{

}
void ContactListener::PreSolve(b2Contact *contact, const b2Manifold *oldManifold)
{
	sound.play();
}
void ContactListener::PostSolve(b2Contact *contact, const b2ContactImpulse *impulse)
{
	
}