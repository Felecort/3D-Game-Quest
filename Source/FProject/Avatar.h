// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Avatar.generated.h"


// ИНВЕНТАРИЗАЦИЯ И ПОДДБОР ПРЕДМЕТОВ

//TMap<FString,int >
/*
Fstrinf    int   UTexture2D*

Имя    количество  текстура

*/



// Объявление класса для функционирования рюкзака
// Предварительное объявление нужно для работы компилятора 
class APickupItem;





/*
UCLASS()
class FPROJECT_API AAvatar : public ACharacter
{
	GENERATED_UCLASS_BODY()

	// Карты предметов в инвентаре

	// FString - предмет, который держит игрок
	TMap<FString, int> Backpack;

	// Icons - иконка предмета, который держит игрок
	TMap<FString, UTexture2D*> Icons;

	// Флаг.  Открыт инвентарь или нет
	bool inventoryShowing;

	// Подбор предмета
	void Pickup(APickupItem* item);

};


struct Item
{
	FString name;
	int qty;
	UTexture2D* tex;
};


*/

// УПРАВЛЕНИЕ ПЕРСОНАЖЕМ

// Макрос, необходимый для работы в UE Editor
UCLASS()
class FPROJECT_API AAvatar : public ACharacter
{
	// Макрос, необходимый для функционирования внутри UE
	GENERATED_UCLASS_BODY()


	// Карта для рюкзака – backpack игрока
	TMap<FString, int> Backpack;

	// Значки для предметов в рюкзаке, просматриваются строкой
	TMap<FString, UTexture2D*> Icons;

	// Флаг.  Открыт инвентарь или нет
	bool inventoryShowing;

	// Подбор предмета
	void Pickup(APickupItem* item);


	// Настройка ХП
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerProperties)
		float Hp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerProperties)
		float MaxHp;

	// Функции, работающие при движении игрока
	// SetupPlayerInputComponent - виртуальная функция в базовом классе Apawn
	void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	
	// Перемещение игрока
	void MoveForward(float amount);
	void MoveRight(float amount);
	void MoveBack(float amount);
	void MoveLeft(float amount);

	// Поворот камеры 
	void Yaw(float amount);
	void Pitch(float amount);


	// Отображение инвентаря
	void ToggleInventory();

	
	
};



