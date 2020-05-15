

#include "PRGame.h"
#include "NPCC.h"
#include "MyHUD.h"
#include "Avatar.h"

ANPCC::ANPCC(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

	//Инициализация в конструкторе путем вызова CreateDefaultSubobject
	//Убитые 8 часов на написание этой строки
	ProxSphere = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("Proximity Sphere"));


	// Натсройки сферы
	ProxSphere->AttachTo(RootComponent);
	
	// Радиус сферы
	// Не редактируется в BP. (А должен?)
	ProxSphere->SetSphereRadius(172.f);

	// Дефолтное сообщение
	// Можно изменить в BP
	ProxSphere->OnComponentBeginOverlap.AddDynamic(this, &ANPCC::Prox);
	NpcMessage = "Hello, this is a project at UE4"; 
}


// Действия, происходящие при пересечении сферы
void ANPCC::Prox_Implementation(AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	// Если пересечение с НЕ игроком, то выход из функции
	if (Cast<AAvatar>(OtherActor) == nullptr)
	{
		return;
	}
	// Иначе
	// Взаимодействие с игроком

	//Сообщение отображается, если расстояние 
	// от Игрока до NPC <= R сферы
	APlayerController* PController = GetWorld() -> GetFirstPlayerController();
	if (PController)
	{
		AMyHUD* hud = Cast<AMyHUD>(PController->GetHUD());
		hud->addMessage(Message(NpcMessage, 5.f, FColor::White));
	}

}