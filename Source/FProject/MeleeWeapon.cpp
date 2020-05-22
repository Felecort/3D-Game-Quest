
#include "FProject.h"
#include "MeleeWeapon.h"
#include "Monster.h"
#include "Monster.cpp"
//#include "FProject.h"
//#include "NPC.h"
//#include "MyHUD.h"
//#include "Avatar.h"

// Рукопашная атака
AMeleeWeapon::AMeleeWeapon(const class FPostConstructInitializeProperties& PCIP) : Super(PCIP)
{

	// Урон
	AttackDamage = 1;

	// В процессе удара враг или нет
	Swinging = false;

	// Держит ли оружие
	WeaponHolder = NULL;
	
	//Mesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	//Mesh = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("Mesh"));
	
	// Меш меча
	Mesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	//RootComponent = Mesh;
	Mesh->AttachTo(RootComponent);
	

	// Объём столкновений 
	ProxBox = PCIP.CreateDefaultSubobject<UBoxComponent>(this, TEXT("ProxBox"));
	
	RootComponent = ProxBox;
	ProxBox->OnComponentBeginOverlap.AddDynamic(this, &AMeleeWeapon::Prox);


}





void AMeleeWeapon::Prox_Implementation(AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& SweepResult)
{
	// Предотвращение удара корневых компонентов, к примеру Меш
	if (OtherComp != OtherActor->GetRootComponent())
	{
		return;
	}
	// Урон не проходит, если
	// Бъёт самого себя
	// Нет замаха 
	// Уже ударил
	if (Swinging && OtherActor != WeaponHolder && !ThingsHit.Contains(OtherActor))
	{
		OtherActor->TakeDamage(AttackDamage + WeaponHolder->BaseAttackDamage, FDamageEvent(), NULL, this);
		ThingsHit.Add(OtherActor);
	}
}


void AMeleeWeapon::Swing()
{

	// Очистка списка 
	ThingsHit.Empty(); 
	Swinging = true;
}
void AMeleeWeapon::Rest()
{
	// Очистка списка 
	ThingsHit.Empty();
	Swinging = false;
}
