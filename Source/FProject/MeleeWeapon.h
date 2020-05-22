// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MeleeWeapon.generated.h"


//class AMonster;

 // Макрос, необходимый для работы в UE Editor
UCLASS()

class FPROJECT_API AMeleeWeapon : public AActor
{
	// Макрос, необходимый для функционирования внутри UE
	GENERATED_UCLASS_BODY()
		
		

	// Объём урона от атаки оружием
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MeleeWeapon)
	float AttackDamage;
		
	// Список объектов, которых коснулся меч
	TArray<AActor*> ThingsHit;
	
	// Предотврщение урона там, где нет взмаха меча
	bool Swinging;
	
	// Не бей себя, плз
	// Используется, чтобы объект не наносил урон самому себе
	AActor*WeaponHolder;
	//AMonster* WeaponHolder;
	
	// коллизия оружия
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision)
		TSubobjectPtr<class USphereComponent> ProxBox;
	//UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = MeleeWeapon)
		//UBoxComponent* ProxBox;
	
	//UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = MeleeWeapon)
		//UStaticMeshComponent* Mesh;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision)
		TSubobjectPtr<class USphereComponent> Mesh;


	UFUNCTION(BlueprintImplementableEvent, Category = Collision)
	void Prox(AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult& SweepResult);
	
	
	virtual void Prox_Implementation(AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool
		bFromSweep, const FHitResult& SweepResult);
		


	// Состояние персонажа
	// Взмах или ожидание 
	void Swing();
	void Rest();

	
};


/*
 Ошибка: 
Ошибка	LNK2001	unresolved external symbol "public: 
virtual void __cdecl AMeleeWeapon::Prox_Implementation(class AActor *,
class UPrimitiveComponent *,int,bool,struct FHitResult const &)" 
(?Prox_Implementation@AMeleeWeapon@@UEAAXPEAVAActor@@PEAVUPrimitiveComponent@@H_NAEBUFHitResult@@@Z)	FProject	D:\Projects_UE\FProject\Intermediate\ProjectFiles\MeleeWeapon.cpp.obj	1

*/


