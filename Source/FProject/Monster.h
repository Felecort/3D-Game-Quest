//__2__
#pragma once

#include "Avatar.h"
#include "FProject.h"
#include "GameFramework/Character.h"
#include "Monster.generated.h"

// Макрос, необходимый для работы в UE Editor
UCLASS()

//__3__
class FPROJECT_API AMonster : public ACharacter
{


	// Объявления UPROPERTY необходимы для корректной конфигурации с BP
	

	// Макрос, необходимый для функционирования внутри UE
	GENERATED_UCLASS_BODY()

	
	// EditAnywhere - Можно редактировать где угодно внутри редактора UE


	// Скорость NPC
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float Speed;
	
	// Здоровье NPC
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float HitPoints;
	
	// Опыт, выпадающий с NPC
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		int32 Experience;
	
	// Blueprint выпавшего предмета 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		UClass* BPLoot;
	
	// Урон NPC
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float BaseAttackDamage;
	
	// Задержка между атаками (Анти спам атак)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float AttackTimeout;
	
	// Время с последнего урада NPC
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = MonsterProperties)
		float TimeSinceLastStrike;
	
	// VisibleDefaultsOnly - можно редактировать только во вкладке Defaults
	// но настраивать можно только для определённого компонента
	// например: для SightSphere, либо AttackRangeSphere

	// Радиус зрения NPC
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Collision)
		TSubobjectPtr<class USphereComponent> SightSphere;


	// Радиус атаки NPC
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Collision)
		TSubobjectPtr<class USphereComponent> AttackRangeSphere;


	// Запускается каждый тик
	// Объявление функции, которая проверяет состояние NPC 
	// 60 раз в секунду 
	virtual void Tick(float DeltaSeconds) override;


	// Отладка действий
	// Находится ли игрок в радиусе атаки
};


