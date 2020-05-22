
#pragma once

#include "Avatar.h"
#include "FProject.h"
#include "GameFramework/Character.h"
#include "Monster.generated.h"


 // ������, ����������� ��� ������ � UE Editor
UCLASS()
class FPROJECT_API AMonster : public ACharacter
{
	// ������, ����������� ��� ���������������� ������ UE
	GENERATED_UCLASS_BODY()

	
	// �������� ����������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float Speed;
	
	// �� �����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float HitPoints;
	// ����, �������� ��� ������ �����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		int32 Experience;
	
	// Blueprint �������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		UClass* BPLoot;
	
	// ���� �������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float BaseAttackDamage;
	
	// �������� ����� �������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float AttackTimeout;
	
	// ����� � ���������� �����
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = MonsterProperties)
		float TimeSinceLastStrike;
	
	// ������ ������ �����
	//UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Collision)
	//	USphereComponent* SightSphere;
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision)
		//TSubobjectPtr<class USphereComponent> ProxSphere;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Collision)
		TSubobjectPtr<class USphereComponent> SightSphere;



	// ��������� ����
	//UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Collision)
		//USphereComponent* AttackRangeSphere;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Collision)
		TSubobjectPtr<class USphereComponent> AttackRangeSphere;



	// �� ������
	// �������, ������������� ������ ���
	virtual void Tick(float DeltaSeconds) override;


	// ��������� �� ����� � ���� ������ ����� 
	inline bool isInSightRange(float d)
	{
		return d < SightSphere->GetScaledSphereRadius();
	}

	// ��������� �� ����� �� ���������� ����� �� �����
	inline bool isInAttackRange(float d)
	{
		return d < AttackRangeSphere->GetScaledSphereRadius();
	}


};


