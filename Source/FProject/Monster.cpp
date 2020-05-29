
#include "FProject.h"
#include "Monster.h"
#include "MyHUD.h"
#include "Avatar.h"




AMonster::AMonster(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// Параметры можно редактировать в BP 
	// благодаря инициализации через UPROPERTY() в .h файле

	// Скорость NPC
	Speed = 45; 
	
	// Здоровье NPC 
	HitPoints = 20; 

	// Урон 
	BaseAttackDamage = 1; 

	// Задержка между ударами
	AttackTimeout = 1.5f; 

	// Время с последней атаки
	TimeSinceLastStrike = 0; 
	

	SightSphere = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("SightSphere"));
	

	SightSphere->AttachTo(RootComponent);
	

	AttackRangeSphere = PCIP.CreateDefaultSubobject <USphereComponent>(this, TEXT("AttackRangeSphere"));
	

	AttackRangeSphere->AttachTo(RootComponent);

}


void AMonster::Tick(float DeltaSeconds)
{
	// Вызов суперкласса
	// Необходимо для работы UE
	Super::Tick(DeltaSeconds);
	
	// Интеллект NPC - движение в сторону игрока
	
	// UGameplayStatics::GetPlayerPawn - получение координат игрока
	// UGameplayStatics - класс с набором функций игрового процесса
	AAvatar* avatar = Cast<AAvatar>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	
	// Если не игрок - выходим из функции 
	if (!avatar)
		return;

	// GetActorLocation - получаем координаты NPC
	// FVector GetActorLocation () const
	FVector targetPlayer = avatar->GetActorLocation() - GetActorLocation();
	
	// Расстояние до игрока
	float distanceToPlayer = targetPlayer.Size();
	
	// Если игрок вне поля зрения NPC (SightSphere)
	// выходим  из функции 
	// GetScaledSphereRadius - получение радиуса сферы с масштабом 1
	if (distanceToPlayer > SightSphere->GetScaledSphereRadius())
	{
		return;
	}

	// Нормализация вектора для оптимизации 
	//targetPlayer /= distanceToPlayer; 

	// Перемещение NPC
	AddMovementInput(targetPlayer, Speed * DeltaSeconds);

	// Нормализация вектора для оптимизации
	targetPlayer.Normalize(); 
	
	// Поворот NPC лицом к игроку
	FRotator toPlayerRotation = targetPlayer.Rotation();

	// Крен по умолчанию 0
	toPlayerRotation.Pitch = 0; 

	// Вращение корневых компонентов (SightSphere,
	// AttackRangeSphere и капсулы коллизии)
	RootComponent->SetWorldRotation(toPlayerRotation);
}

