
#include "FProject.h"
#include "Avatar.h"

/*
 Конструктор класса AAvatar, он принимает аргумент PCIP в виде 
 ссылки на класс FPostConstructInitializeProperties, причём ссылка const 
 (т.е. не подразумевается производить изменения внутри). 
 Далее этот аргумент передаётся в конструктор базового класса 
 и выполняется базовый конструктор. 
 Затем выполняется код внутри конструктора.
*/
AAvatar::AAvatar(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// Присваивание количества ХП 
	Hp = MaxHp = 100;
}



// УПРАВЛЕНИЕ ПЕРСОНАЖЕМ

// UInputComponent - позволяет Actor связывать события для делегирования функций
// SetupPlayerInputComponent - позволяет устанавливать пользовательсктие привязки ввода
// Функция ищет привязки осей заданных в настройках UE

void AAvatar::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{

	// BindAxis - привязка осей. BindAction - привязка клавиш

	// Проверка на наличие вводных данных
	check(InputComponent);


	// "Inventory" - имя, указанное в настройках проекта UE
	// IE_Pressed - клавища нажата 
	// this - ссылка на самого себя 
	// &AAvatar::MoveForward - указываем функцию, с которой работаем
	
	// Открытие инвентаря
	InputComponent->BindAction("Inventory", IE_Pressed, this, &AAvatar::ToggleInventory);
	// аналогично *InputComponent.BindAction?? но -> может быть перегружен
	// обращение к свойствам BindAction
	

	// Привязки осей Forward - имя оси

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
// базового класса APawn. Controller - нефизический Actor 
// Функции для изменения координат в 2х полуосях
void AAvatar::MoveForward(float amount)
{


	if (Controller && amount)
	{
		// Получаем вектор игрока
		FVector forward = GetActorForwardVector();
		// Изменяем его. AddMovementInput - движение по заданному вектору
		AddMovementInput(forward, amount);
	}
}
void AAvatar::MoveRight(float amount)
{
	if (Controller && amount)
	{
		// Получаем вектор игрока
		FVector right = GetActorRightVector();
		// Изменяем его. AddMovementInput - движение по заданному вектору
		AddMovementInput(right, amount);
	}
}


/*
Объект Controller и функции AddMovementInput
определены в базовом классе APawn
*/


// Функции для изменения координат в инвертированных 2х полуосях
void AAvatar::MoveLeft(float amount)
{

	if (Controller && amount)
	{
		// Получаем вектор игрока 
		FVector left = -GetActorRightVector();
		// Изменяем его. AddMovementInput - движение по заданному вектору
		AddMovementInput(left, amount);
	}
} void AAvatar::MoveBack(float amount)
{
	if (Controller && amount)
	{
		// Получаем вектор игрока
		FVector back = -GetActorForwardVector();
		// Изменяем его. AddMovementInput - движение по заданному вектору
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


// AddControllerYawInput аналогично AddMovementInput, но для вращения
// Коэффициент 150 - чувствутельность мыши

// GetDeltaSeconds - разница во времени межу кадрами
// GetWorld - получение кешированного указателя мира, в котором находится Actor
void AAvatar::Yaw(float amount)
{
	// AddControllerYawInput - вращение камеры по горизонтали - рыскание 
	AddControllerYawInput(150.f * amount * GetWorld()->GetDeltaSeconds());
}

void AAvatar::Pitch(float amount)
{
	// AddControllerYawInput - вращение камеры по горизонтали - тангаж 
	AddControllerPitchInput(150.f * amount * GetWorld()->GetDeltaSeconds());
}


// Сообщение отладки свызова функции просмотра инвентаря
void AAvatar::ToggleInventory()
{
	// GEngine - абстрактный базовый класс длявсех классов движка
	// отвечает за управление системами 
	if (GEngine)

	{
		// 0 - "ключ" для предотвращения многократного вывода сообщения
		// 5.f - время отображения
		// FColor::Red - цвет
		// "Showing Inventory..." - текст сообщения
		GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Red, "Showing Inventory...");
		
	}
}

