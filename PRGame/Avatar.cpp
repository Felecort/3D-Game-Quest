
#include "PRGame.h"
#include "Avatar.h"


AAvatar::AAvatar(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}

// SetupPlayerInputComponent - ����������� ������� �������� ������ Apawn
void AAvatar::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{

	// ����� �������� ���� (��������� ���� ��������� ������ ��������� UE)
	check(InputComponent);
	
	// ����������� ���������
	InputComponent -> BindAxis("Forward", this, &AAvatar::MoveForward);
	InputComponent -> BindAxis("Strafe", this, &AAvatar::MoveRight);
	
	// ������� ������
	InputComponent -> BindAxis("Yaw", this, &AAvatar::Yaw);
	InputComponent -> BindAxis("Pitch", this, &AAvatar::Pitch);

}
// ������� Controller � GetActorForwardVector ���������� ������ �������� ������ APawn


/*
				�����������

Axis Mapping

 �������� ������:
 Forward: 
		W, scale: 1
		S, scale: -1
 Strafe:
		D, scale: 1
		A, scale: -1
*/

/* Avatar ��������� �� ACharacter
   ACharacter ��������� �� APawn
   ��������� ������������ ���� ����������� ������������ 
   ���� ������� �������� ������ APawn

*/

// ������� ��� ��������� ��������� � 2� ��������
void AAvatar::MoveForward(float amount)
{

	/*������ Controller � ������� AddMovementInput
	���������� � ������� ������ APawn*/
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


// ������� ��� ��������� ��������� � ��������������� 2� ��������
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
			�������� � ������

Axis Mapping
 �������� ������:
 Yaw:
	mouse X, scale: 1
Pitch:
	mouse Y, scale: 1
*/



/* ����������� 150 - ���������������� ���� 
	
	GetWorld()->GetDeltaSeconds() - ������� �� ������� 
	����� ����� �������, ����� 0.016 ���
	*/
void AAvatar::Yaw(float amount)
{
	AddControllerYawInput(150.f * amount * GetWorld() -> GetDeltaSeconds());
}

void AAvatar::Pitch(float amount)
{
	AddControllerPitchInput(150.f * amount * GetWorld() -> GetDeltaSeconds());
}
