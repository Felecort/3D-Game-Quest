

/*
#include "FProject.h"
#include "PickupItem.h"
#include "Avatar.h"
#include "MyHUD.h"
*/

/*APickupItem::APickupItem(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

	// Устанавливаем название предмета
	Name = "UNKNOWN_ITEM";

	// Количество предметов
	Quantity = 0;

	// Задаём объекты Unreal Engine
	ProxSphere = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("ProxSphere"));

	// Изначально сетка пустая, необходимо настроить в BP
	// Сетка необходима для реалистичной физики объектов
	//Mesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	Mesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));


	// Подключение в форме корневого компонента 
	RootComponent = Mesh;
	Mesh->SetSimulatePhysics(true);


	//ProxSphere = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("ProxSphere"));


	// Прикрепление компонента ProxSphere к корневому компоненту Mesh
	// Когда сетак движется, ProxSphere движется за ней
	ProxSphere->AttachTo(Mesh);

	//ProxSphere->OnComponentBeginOverlap.AddDynamic(this, &APickupItem::Prox);

}
*/