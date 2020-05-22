// Fill out your copyright notice in the Description page of Project Settings.


/*
#pragma once

#include "GameFramework/Actor.h"
#include "PickupItem.generated.h"


class AMyHUD;

// Макрос, необходимый для работы в UE Editor
UCLASS()

class FPROJECT_API APickupItem : public AActor
{
	// Макрос, необходимый для функционирования внутри UE
	GENERATED_UCLASS_BODY()


	// Объявления UPROPERTY необходимы для корректной конфигурации с BP



	// Название получаемого предмета
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item) FString Name;


	// Количество получаемых предметов
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item) int32 Quantity;


	// Сфера, пересекая которую игрок получает предмет
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Item)
		TSubobjectPtr<USphereComponent> ProxSphere;


	// Сетка предмета
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Item)
		TSubobjectPtr<UStaticMeshComponent> Mesh;




	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Item)
		USphereComponent* ProxSphere;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Item)
		UStaticMeshComponent* Mesh;




	// Иконка предмета
	// (На земле или в инвентаре)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
		UTexture2D* Icon;

	// Когда что-то попадает в ProxSphere, вызывается данная функция
	UFUNCTION(BlueprintNativeEvent, Category = Collision)

	// Prox -- Prox_Implementation
	void Prox(AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


};


// Иконки предметов
struct Icon
{

	
	FString name;
	UTexture2D* tex;
	Icon() { name = "UNKNOWN ICON"; tex = 0; }
	Icon(FString& iName, UTexture2D* iTex)
	{
		name = iName;
		tex = iTex;
	}
};

// Виджет/графическое отображение инвентаря
struct Widget
{
	Icon icon;
	FVector2D pos, size;
	Widget(Icon iicon)
	{
		icon = iicon;
	}

	// Функции для перемещения в виджете
	float left() {return pos.X;}
	float right() {return pos.X + size.X;}
	float top() {return pos.Y;}
	float bottom() {return pos.Y + size.Y;}
};



// RootComponent - ссылка на примитив столкновений
// Редактируется в BP
// Определение взаимодействия с чем-либо

UPROPERTY()
class USceneComponent* RootComponent;



*/

