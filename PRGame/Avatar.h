

#pragma once

#include "GameFramework/Character.h"
#include "Avatar.generated.h"




// ������, ����������� ��� ������ � UE Editor
UCLASS()
class PRGAME_API AAvatar : public ACharacter
{// ������, ����������� ��� ���������������� ������ UE
    GENERATED_UCLASS_BODY()


    // ���������� ������� ������ �����
    void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
    
    // ���������� ������� ��� �����������
    void MoveForward(float amount);
    void MoveRight(float amount);
    void MoveBack(float amount);
    void MoveLeft(float amount);
    // ���������� ������� ��� ���������� �������
    void Yaw(float amount);
    void Pitch(float amount);

};