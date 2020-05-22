// Fill out your copyright notice in the Description page of Project Settings.

#include "FProject.h"
#include "Avatar.h"


AAvatar::AAvatar(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	Hp = MaxHp = 100;
}

/*
AAvatar::AAvatar(const class FObjectInitializer& PCIP) : Super(PCIP)
{
	Hp = MaxHp = 100;
}
*/

// УПРАВЛЕНИЕ ПЕРСОНАЖЕМ

// Функция ищет привязки осей заданных в настройках UE
void AAvatar::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{

	// Проверка нажатия клавиши
	check(InputComponent);


	// Открытие инвентаря
	InputComponent->BindAction("Inventory", IE_Pressed, this, &AAvatar::ToggleInventory);


	// Пердвижение персонажа
	InputComponent->BindAxis("Forward", this, &AAvatar::MoveForward);
	InputComponent->BindAxis("Strafe", this, &AAvatar::MoveRight);

	// Поворот камеры
	InputComponent->BindAxis("Yaw", this, &AAvatar::Yaw);
	InputComponent->BindAxis("Pitch", this, &AAvatar::Pitch);
}

/*
				ПЕРЕМЕЩЕНИЕ

Axis Mapping

 Привязки клавиш:
 Forward:
		W, scale: 1
		S, scale: -1
 Strafe:
		D, scale: 1
		A, scale: -1

		
   Avatar просходит от ACharacter
   ACharacter просходит от APawn
   благодаря наследованию есть возможность использовать
   все функции базового класса APawn

*/



// Объекты Controller и GetActorForwardVector определены внутри
// базового класса APawn
// Функции для изменения координат в 2х полуосях
void AAvatar::MoveForward(float amount)
{

	/*Объект Controller и функции AddMovementInput
	определены в базовом классе APawn*/
	if (Controller && amount)
	{
		FVector fwd = GetActorForwardVector();
		AddMovementInput(fwd, amount);
	}
}
void AAvatar::MoveRight(float amount)
{
	if (Controller && amount)
	{
		FVector right = GetActorRightVector();
		AddMovementInput(right, amount);
	}
}





// Функции для изменения координат в инвертированных 2х полуосях
void AAvatar::MoveLeft(float amount)
{
	if (Controller && amount)
	{
		FVector left = -GetActorRightVector();
		AddMovementInput(left, amount);
	}
} void AAvatar::MoveBack(float amount)
{
	if (Controller && amount)
	{
		FVector back = -GetActorForwardVector();
		AddMovementInput(back, amount);
	}
}



// Функции осуществляющие поворот камеры

/*
			РЫСКАНИЕ И ТАНГАЖ

Axis Mapping
 Привязки клавиш:
 Yaw:
	mouse X, scale: 1
Pitch:
	mouse Y, scale: 1


	GetWorld()->GetDeltaSeconds() - разница во времени
	между двумя кадрами, около 0.016 сек
*/

// Коэффициент 150 - чувствутельность мыши
void AAvatar::Yaw(float amount)
{
	AddControllerYawInput(150.f * amount * GetWorld()->GetDeltaSeconds());
}

void AAvatar::Pitch(float amount)
{
	AddControllerPitchInput(150.f * amount * GetWorld()->GetDeltaSeconds());
}



// Сообщение отладки
void AAvatar::ToggleInventory()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Red, "Showinginventory...");
	}
}



/*


// Инвентарь
void AAvatar::ToggleInventory()
{
	// Получаем контроллер и HUD
	APlayerController* PController = GetWorld() - > GetFirstPlayerController();
	AMyHUD* hud = Cast<AMyHUD>(PController->GetHUD());
	
	
	// Если инвентарь отображается, то прекращаем отображать его
	if (inventoryShowing)
	{
		hud->clearWidgets();
		inventoryShowing = false;
		PController->bShowMouseCursor = false;
		return;
	}

	// Иначе отображаем инвентарь игрока
	inventoryShowing = true;
	PController->bShowMouseCursor = true;
	
	for (TMap<FString, int>::TIterator it = Backpack.CreateIterator(); it; ++it)
	{

		// Конкатенация имени и количествва предмета 
		FString fs = it->Key + FString::Printf(TEXT(" x %d"), it - > Value);
		UTexture2D* tex;
		if (Icons.Find(it->Key))
			tex = Icons[it->Key];
		hud->addWidget(Widget(Icon(fs, tex)));
	}
}



*/