
//__2__
// Директива, необходимая для подключения файлов только 1 раз
#pragma once

#include "GameFramework/Character.h"
#include "Avatar.generated.h"



// УПРАВЛЕНИЕ ПЕРСОНАЖЕМ

// Макрос, необходимый для работы в UE Editor
UCLASS()

//__3__
class FPROJECT_API AAvatar : public ACharacter
{
	// Макрос, необходимый для функционирования внутри UE
	GENERATED_UCLASS_BODY()

	// Объявления UPROPERTY необходимы для конфигурации с BP

	// Настройка ХП

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
	// SetupPlayerInputComponent - виртуальная функция в базовом классе Apawn
	// override - модификатор, необходимый для корректной работы 
	void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	
	// Перемещение игрока
	void MoveForward(float amount);
	void MoveRight(float amount);
	void MoveBack(float amount);
	void MoveLeft(float amount);

	// Поворот камеры 
	void Yaw(float amount);
	void Pitch(float amount);


	// Отладка инвентаря
	void ToggleInventory();
	
};



