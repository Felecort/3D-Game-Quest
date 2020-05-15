
#include "PRGame.h"
#include "Avatar.h"


AAvatar::AAvatar(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}

// SetupPlayerInputComponent - Виртуальная функция базового класса Apawn
void AAvatar::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{

	// Поиск привязки осей (настройки осей находятся внутри редактора UE)
	check(InputComponent);
	
	// Пердвижение персонажа
	InputComponent -> BindAxis("Forward", this, &AAvatar::MoveForward);
	InputComponent -> BindAxis("Strafe", this, &AAvatar::MoveRight);
	
	// Поворот камеры
	InputComponent -> BindAxis("Yaw", this, &AAvatar::Yaw);
	InputComponent -> BindAxis("Pitch", this, &AAvatar::Pitch);

}
// Объекты Controller и GetActorForwardVector определены внутри базового класса APawn


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
*/

/* Avatar просходит от ACharacter
   ACharacter просходит от APawn
   благодаря наследованию есть возможность использовать 
   всек функции базового класса APawn

*/

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



/*
			РЫСКАНИЕ И ТАНГАЖ

Axis Mapping
 Привязки клавиш:
 Yaw:
	mouse X, scale: 1
Pitch:
	mouse Y, scale: 1
*/



/* коэффициент 150 - чувствутельность мыши 
	
	GetWorld()->GetDeltaSeconds() - разница во времени 
	между двумя кадрами, около 0.016 сек
	*/
void AAvatar::Yaw(float amount)
{
	AddControllerYawInput(150.f * amount * GetWorld() -> GetDeltaSeconds());
}

void AAvatar::Pitch(float amount)
{
	AddControllerPitchInput(150.f * amount * GetWorld() -> GetDeltaSeconds());
}
