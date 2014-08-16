#include <Box2D/Box2D.h>
#include <SFML/Audio.hpp>
class ContactListener : public b2ContactListener
{

private:
	sf::SoundBuffer buffer;

	sf::Sound sound;

public :
	ContactListener();
	~ContactListener();

	virtual void BeginContract(b2Contact *contact);
	virtual void EndContact(b2Contact *contact);
	virtual void PreSolve(b2Contact *contact, const b2Manifold *oldManifold);
	virtual void PostSolve(b2Contact *contact, const b2ContactImpulse *impulse);
};