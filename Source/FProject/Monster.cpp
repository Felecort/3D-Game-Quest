// Fill out your copyright notice in the Description page of Project Settings.

#include "FProject.h"
#include "Monster.h"
#include "MyHUD.h"


//#include "FProject.h"
//#include "NPC.h"
//#include "MyHUD.h"
#include "Avatar.h"


//#include "MyHUD.h"
//#include "Avatar.h"
AMonster::AMonster(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// Скорость NPC, Редактируется в BP
	Speed = 45; 
	
	// Здоровье NPC 
	HitPoints = 20; 

	// Опыт NPC
	Experience = 0;

	// Лут
	BPLoot = NULL; 

	// Урон 
	BaseAttackDamage = 1; 

	// Задержка между ударами
	AttackTimeout = 1.5f; 

	// Время с последней атаки
	TimeSinceLastStrike = 0; 
	
	//ProxSphere = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("Proximity Sphere"));
	SightSphere = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("SightSphere"));
	
	SightSphere->AttachTo(RootComponent);
	
	//ProxSphere = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("AttackRangeSphere"));
	AttackRangeSphere = PCIP.CreateDefaultSubobject <USphereComponent>(this, TEXT("AttackRangeSphere"));
	
	AttackRangeSphere->AttachTo(RootComponent);

}


void AMonster::Tick(float DeltaSeconds)
{
	// Вызов суперкласса
	Super::Tick(DeltaSeconds);
	
	// Интеллект NPC - движение в сторону игрока
	
	// UGameplayStatics::GetPlayerPawn - получение координат игрока
	AAvatar* avatar = Cast<AAvatar>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	
	// Если не Avatar, выходим из функции 
	if (!avatar)
		return;

	// GetActorLocation - получаем координаты игрока
	FVector toPlayer = avatar->GetActorLocation() - GetActorLocation();
	
	// Расстояние до игрока
	float distanceToPlayer = toPlayer.Size();
	
	// Если игрок вне поля зрения NPC (SightSphere)
	// выходим  из функции 
	if (distanceToPlayer > SightSphere->GetScaledSphereRadius())
	{
 
		return;
	}

	// Нормализация вектора для оптимизации 
	//toPlayer /= distanceToPlayer; 

	// Перемещение NPC
	AddMovementInput(toPlayer, Speed * DeltaSeconds);

	// Нормализация вектора для оптимизации
	toPlayer.Normalize(); 
	
	// Поворот NPC лицом к игроку
	FRotator toPlayerRotation = toPlayer.Rotation();
	toPlayerRotation.Pitch = 0; 
	RootComponent->SetWorldRotation(toPlayerRotation);
}

