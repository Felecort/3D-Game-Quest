// Fill out your copyright notice in the Description page of Project Settings.
/*
#include "FProject.h"
#include "PickupItem.h"
#include "Avatar.h"
#include "MyHUD.h"
*/

/*APickupItem::APickupItem(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

	// Г„Г®ГЎГ ГўГ«ГїГ¬ ГЁГ§Г­Г Г·Г Г«ГјГ­Г»ГҐ Г¤Г Г­Г­Г»ГҐ
	Name = "UNKNOWN_ITEM";
	Quantity = 0;

	// Г‡Г Г¤Г ВёГ¬ Г®ГЎГєГҐГЄГІ Г¤Г«Гї UE
	// Г‘ГґГҐГ°Г  ГўГ§Г ГЁГ¬Г®Г¤ГҐГ©Г±ГІГўГЁГ©
	ProxSphere = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("ProxSphere"));

	// Г€Г­ГЁГ¶ГЁГ Г«ГЁГ§Г Г¶ГЁГї (ГІГҐГЄГ±ГІГіГ°)
	// Г‘ГҐГІГЄГі Г­ГҐГ®ГЎГµГ®Г¤ГЁГ¬Г® Г§Г ГЈГ°ГіГ§ГЁГІГј Гў BP
	// Г‘ГҐГІГЄГ  Г¤Г®ГЎГ ГўГ«ГҐГ­Г  Г¤Г«Гї Г°ГҐГ Г«ГЁГ±ГІГЁГ·Г­Г®Г© ГґГЁГ§ГЁГЄГЁ Г®ГЎГєГҐГЄГІГ®Гў
	//Mesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	Mesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));


	// Г„ГҐГ«Г ГҐГ¬ ГЄГ®Г°Г­ГҐГўГ®Г© ГЅГ«ГҐГ¬ГҐГ­ГІ Mash'Г®Г¬
	RootComponent = Mesh;
	Mesh->SetSimulatePhysics(true);


	//ProxSphere = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("ProxSphere"));


	// ГЏГ°Г®ГўГҐГ°ГЄГ  ГЇГ°ГЁГЄГ°ГҐГЇГ«ГҐГ­ГЁГї ProxSphere ГЄ ГЄГ®Г°Г­ГҐГўГ®Г¬Гі ГЄГ®Г¬ГЇГ®Г­ГҐГ­ГІГі Mash
	// Г‘ГҐГІГЄГ  Г¤Г®Г«Г¦Г­Г  Г¤ГўГЁГЈГ ГІГјГ±Гї Г§Г  ProxSphere
	ProxSphere->AttachTo(Mesh);

	// ГЉГ®Г¤ Г§Г ГЇГіГ±ГЄГ  APickupItem::Prox() ГЇГ°ГЁ ГЇГҐГ°ГҐГ±ГҐГ·ГҐГ­ГЁГЁ Г±ГґГҐГ°Г»
	ProxSphere->OnComponentBeginOverlap.AddDynamic(this, &APickupItem::Prox);

}
*/