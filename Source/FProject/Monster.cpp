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
	// �������� ������
	Speed = 45; 
	
	// �� ������
	HitPoints = 20; 

	// ����, �������� � �������
	Experience = 0;

	// ������
	BPLoot = NULL; 

	// ����
	BaseAttackDamage = 1; 

	// ������������ �����
	AttackTimeout = 1.5f; 

	// �������� ����� �������
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
	// ��������� � �����������
	Super::Tick(DeltaSeconds);
	
	// �������� ����� �� ������

	// UGameplayStatics::GetPlayerPawn - ��������� ������� ������
	AAvatar* avatar = Cast<AAvatar>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	
	// ���� �� �����, �� ������� �� �������
	if (!avatar) return;

	// GetActorLocation - ������ �� ����� �� ���������
	FVector toPlayer = avatar->GetActorLocation() - GetActorLocation();
	

	float distanceToPlayer = toPlayer.Size();
	// ���� ����� �� � SightSphere �����, ��
	// ���� ���������� ������
	if (distanceToPlayer > SightSphere->GetScaledSphereRadius())
	{
		// ���� ����� � �� ���� ������, �����
		// ������� �� ������� 
		return;
	}

	// ����������� ������
	toPlayer /= distanceToPlayer; 

	// �������� ����� �� ������
	AddMovementInput(toPlayer, Speed * DeltaSeconds);

	// ��������� ������ ������������ �� ����������
	toPlayer.Normalize(); 
	
	// ������ ������������ � ������
	AddMovementInput(toPlayer, Speed * DeltaSeconds);
	
	
	// �������� ����� � ����
	FRotator toPlayerRotation = toPlayer.Rotation();
	toPlayerRotation.Pitch = 0; 
	RootComponent->SetWorldRotation(toPlayerRotation);
}

