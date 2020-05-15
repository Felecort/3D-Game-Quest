

#pragma once

#include "GameFramework/Character.h"
#include "Avatar.generated.h"




// Макрос, необходимый для работы в UE Editor
UCLASS()
class PRGAME_API AAvatar : public ACharacter
{// Макрос, необходимый для функционирования внутри UE
    GENERATED_UCLASS_BODY()


    // Объявление функций работы ввода
    void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
    
    // Объявление функций для перемещения
    void MoveForward(float amount);
    void MoveRight(float amount);
    void MoveBack(float amount);
    void MoveLeft(float amount);
    // Объявление функций для управления камерой
    void Yaw(float amount);
    void Pitch(float amount);

};