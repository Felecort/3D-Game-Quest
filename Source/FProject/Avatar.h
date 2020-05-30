

// Директива, необходимая для подключения файлов только 1 раз
#pragma once

#include "GameFramework/Character.h"
#include "Avatar.generated.h"


// УПРАВЛЕНИЕ ПЕРСОНАЖЕМ

// Макрос, необходимый для работы в UE Editor
UCLASS()


class FPROJECT_API AAvatar : public ACharacter
{
	// Макрос, необходимый для функционирования внутри UE
	// Делает переменные обзедоступными
	GENERATED_UCLASS_BODY()

	// Объявления UPROPERTY необходимы для конфигурации с BP

	// Настройка ХП


	// Для переменных, не являющихся указателями нужно использовать EditAnywhere  BlueprintReadWrite

	// EditAnywhere, BlueprintReadWrite - параметры для редактирования внутри редактора UE
	// PlayerProperties - то, к кому мы применяем заданные свойства
	// *тип* *имя* - переменная, которую мы объявляем

	// Объявление переменной для счётчика ХП
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerProperties)
		float Hp;

	// Объявление переменной для счётчика максимального кол-ва ХП
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerProperties)
		float MaxHp;

	// объявление функций для управления персонажем 

	// Функции, работающие при движении игрока
	// SetupPlayerInputComponent - виртуальная функция в базовом классе Apawn,
		// позволяет устанавливать пользоветельские привязки ввода
	// override - модификатор, необходимый для корректной работы 
	void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	
	// Перемещение игрока
	void MoveForward(float Value);
	void MoveRight(float Value);
	void MoveBack(float Value);
	void MoveLeft(float Value);

	// Поворот камеры 
	void Yaw(float Value);
	void Pitch(float Value);


	// Отладка инвентаря
	void ToggleInventory();
	
};



