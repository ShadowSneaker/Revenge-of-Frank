#pragma once
#include "../Entity.h"


class CEnemy :public CEntity
{
private:
	/// Properties

	CEntity* PlayerRef;

	class CCircle* CircleCollider;

	class CCircle* AttackRange;

	bool IsAgro = false;


public:
	/// Constructors

	CEnemy(OBJECT_CONSTRUCTOR_BASE Base, STransform InTransform);

	virtual ~CEnemy() override;

	/// Functions

	virtual void Update() override;


	virtual void ReadInput(CInput* Input) override {};

	void CheckPlayer();


	virtual void OnOverlap(SHitInfo Info, std::string Tag) override;
 
	/// Setters
	inline void SetPlayerRef(CEntity* Player) { PlayerRef = Player; }

	/// Getters
};