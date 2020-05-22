// Fill out your copyright notice in the Description page of Project Settings.

#include "FProject.h"
#include "MeleeWeapon.h"
#include "Monster.h"
#include "Monster.cpp"
//#include "FProject.h"
//#include "NPC.h"
//#include "MyHUD.h"
//#include "Avatar.h"
// ����������� �����
AMeleeWeapon::AMeleeWeapon(const class FPostConstructInitializeProperties& PCIP) : Super(PCIP)
{

	AttackDamage = 1;
	Swinging = false;
	WeaponHolder = NULL;
	//Mesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	//Mesh = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("Mesh"));
	
	Mesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	//RootComponent = Mesh;
	Mesh->AttachTo(RootComponent);
	
	ProxBox = PCIP.CreateDefaultSubobject<UBoxComponent>(this, TEXT("ProxBox"));
	RootComponent = ProxBox;
	ProxBox->OnComponentBeginOverlap.AddDynamic(this, &AMeleeWeapon::Prox);


}





void AMeleeWeapon::Prox_Implementation(AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& SweepResult)
{
	// ���� �� ��������� �� �������� �����������
	if (OtherComp != OtherActor->GetRootComponent())
	{
		return;
	}
	// ��������, ����� ���� �� ��������
	// ����
	// ������ ������
	// ����� ��� ������
	if (Swinging && OtherActor != WeaponHolder && !ThingsHit.Contains(OtherActor))
	{
		OtherActor->TakeDamage(AttackDamage + WeaponHolder->BaseAttackDamage, FDamageEvent(), NULL, this);
		ThingsHit.Add(OtherActor);
	}
}


void AMeleeWeapon::Swing()
{
	ThingsHit.Empty(); 
	Swinging = true;
}
void AMeleeWeapon::Rest()
{
	ThingsHit.Empty();
	Swinging = false;
}
